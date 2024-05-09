#include "Janky-SDVX-Controller.h"
#include "Encoder.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <EEPROM.h>

JankySDVXControllerReport_t report;

// Number of microseconds between HID reports
// 2000 = 500hz
#define REPORT_DELAY 1000

// Read eeprom address 0. Value stored indicated mode. Mode1=joystick, Mode2=keyboard.
int currMode = EEPROM.read(0);

// Mouse Sens Multiplier
#define MOUSE_MULT  3

// Button Keybinds
#define BIND_A    'd'
#define BIND_B    'f'
#define BIND_C    'j'
#define BIND_D    'k'
#define BIND_FX_L 'c'
#define BIND_FX_R 'm'
#define BIND_ST   '1'

// Button Pinout
#define BT_A  2
#define BT_B  3
#define BT_C  4
#define BT_D  5
#define FX_L  6
#define FX_R  7
#define BT_ST 21

// Number of cycles before HID falls back to reactive
unsigned long reactiveTimeoutMax = 1000;
unsigned long reactiveTimeoutCount = reactiveTimeoutMax;

uint8_t bindKeys[] = { BIND_A, BIND_B, BIND_C, BIND_D, BIND_FX_L, BIND_FX_R, BIND_ST };
uint8_t buttonPins[] = { BT_A, BT_B, BT_C, BT_D, FX_L, FX_R, BT_ST };
uint8_t buttonCount = sizeof(buttonPins) / sizeof(buttonPins[0]);

// Encoder sensitivity = number of positions per rotation times 4 (24*4) / number of positions for HID report (256)
#define ENCODER_SENSITIVITY (double) 0.375
Encoder encL(9, 8), encR(16, 10);
float knob1 = 0;
float knob2 = 0;
float old_knob1 = 0;
float old_knob2 = 0;

/**
 * Arduino Setup
 */
void setup() {
  // Setup I/O for pins
  for (int i = 0; i < buttonCount; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Startup mode
  int Button1State = digitalRead(BT_A); //Read Btn-A
  int Button2State = digitalRead(BT_B); //Read Btn-B
  // Button 1 is held down: Joystick Mode
  if (Button1State == LOW && Button2State == HIGH) {
    if (currMode != 1) {
      EEPROM.update(0, 1); 
      delay(200);
    }
  } else if (Button2State == LOW && Button1State == HIGH) {
    // Button 2 is held down: Keyboard Mode
    if (currMode != 2) {
      EEPROM.update(0, 2);
      delay(200);
    }
  }
}

/**
 * Arduino Loop
 */
void loop() {
  if (EEPROM.read(0) == 1) {
    joy_mode();
  } else if (EEPROM.read(0) == 2) {
    keyboard_mode();
  }
}

/**
 * Keyboard Implementation
 */
void keyboard_mode() {
  // Read encoders
  knob1 =  (float)(encL.read());
  knob2 = (float)encR.read();

  if(knob1 != old_knob1) {
    Mouse.move((knob1 - old_knob1) * MOUSE_MULT, 0);
    
    // We count the difference in the encoders, but we must not go over arduino's int limit
    if(knob1 < -255 || knob1 > 255) {
      encL.write(0);
      old_knob1 = 0;
    } else {
      old_knob1 = knob1;
    }
  }
  
  if(knob2 != old_knob2) {
    Mouse.move(0, (knob2 - old_knob2) * MOUSE_MULT);
    
    if(knob2 < -255 || knob2 > 255) {
      encR.write(0);
      old_knob2 = 0;
    } else {
      old_knob2 = knob2;
    }
  }
  
  // Read the buttons, if it's low, output a keyboard press  
  for (int i = 0; i < buttonCount; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      Keyboard.press(bindKeys[i]);
    } else {
      Keyboard.release(bindKeys[i]);
    }
  }
}

/**
 * Controller Implementation
 */
void joy_mode() {
  // Read buttons except BT_ST
  for (int i = 0; i < buttonCount - 1; i++) {
    if (digitalRead(buttonPins[i]) != HIGH) {
      report.buttons |= (uint16_t)1 << i;
    } else {
      report.buttons &= ~((uint16_t)1 << i);
    }
  }
  // Read BT_ST
  if (digitalRead(BT_ST) != HIGH) {
    report.buttons |= (uint16_t)1 << 8;
  } else {
    report.buttons &= ~((uint16_t)1 << 8);
  }
  
  // Read Encoders
  report.xAxis = (uint8_t)((int32_t)(encL.read() / ENCODER_SENSITIVITY) % 256);
  report.yAxis = (uint8_t)((int32_t)(encR.read() / ENCODER_SENSITIVITY) % 256);
  
  JankySDVXController.setState(&report);
  delayMicroseconds(REPORT_DELAY);
}