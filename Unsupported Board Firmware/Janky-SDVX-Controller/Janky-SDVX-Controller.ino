#include "Encoder.h"

// Mouse Sens Multiplier
#define MOUSE_MULT  3

// Button Keybinds
#define BIND_A    "d"
#define BIND_B    "f"
#define BIND_C    "j"
#define BIND_D    "k"
#define BIND_FX_L "c"
#define BIND_FX_R "m"
#define BIND_ST   "1"

// Button Pinout
// CHANGE THESE
#define BT_A  2
#define BT_B  3
#define BT_C  4
#define BT_D  5
#define FX_L  6
#define FX_R  7
#define BT_ST 8

String bindKeys[] = { BIND_A, BIND_B, BIND_C, BIND_D, BIND_FX_L, BIND_FX_R, BIND_ST };
bool keysHeld[] = { false, false, false, false, false, false, false, false };
uint8_t buttonPins[] = { BT_A, BT_B, BT_C, BT_D, FX_L, FX_R, BT_ST };
uint8_t buttonCount = sizeof(buttonPins) / sizeof(buttonPins[0]);

// Encoder sensitivity = number of positions per rotation times 4 (24*4) / number of positions for HID report (256)
#define ENCODER_SENSITIVITY (double) 0.375
// CHANGE THESE
Encoder encL(20, 19), encR(22, 21);
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

  Serial.begin(9600);
}

/**
 * Arduino Loop
 */
void loop() {
  keyboard_mode();
}

/**
 * Keyboard Implementation
 */
void keyboard_mode() {
  // Read encoders
  knob1 =  (float)(encL.read());
  knob2 = (float)encR.read();

  if(knob1 != old_knob1) {
    Serial.println("mm:" + String((knob1 - old_knob1) * MOUSE_MULT) + ",0");
    
    // We count the difference in the encoders, but we must not go over arduino's int limit
    if(knob1 < -255 || knob1 > 255) {
      encL.write(0);
      old_knob1 = 0;
    } else {
      old_knob1 = knob1;
    }
  }
  
  if(knob2 != old_knob2) {
    Serial.println("mm:0," + String((knob2 - old_knob2) * MOUSE_MULT));
    
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
      if (keysHeld[i]) return;
      keysHeld[i] = true;
      Serial.println("kd:" + bindKeys[i]);
    } else {
      if (!keysHeld[i]) return;
      keysHeld[i] = false;
      Serial.println("ku:" + bindKeys[i]);
    }
  }
}