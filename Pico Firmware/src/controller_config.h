#ifndef CONTROLLER_CONFIG_H
#define CONTROLLER_CONFIG_H

#define SW_GPIO_SIZE 7                // Number of switches
#define ENC_GPIO_SIZE 2               // Number of encoders
#define ENC_PPR 24                    // Encoder PPR
#define MOUSE_SENS 5                  // Mouse sensitivity multiplier
#define ENC_DEBOUNCE true             // Encoder Debouncing
#define SW_DEBOUNCE_TIME_US 4000      // Switch debounce delay in us
#define ENC_PULSE (ENC_PPR * 4)       // 4 pulses per PPR

#ifdef PICO_GAME_CONTROLLER_C

// MODIFY KEYBINDS HERE, MAKE SURE LENGTHS MATCH SW_GPIO_SIZE
const uint8_t SW_KEYCODE[] = {
    HID_KEY_D, HID_KEY_F, HID_KEY_J, HID_KEY_K, HID_KEY_C,
    HID_KEY_M, HID_KEY_1,
};
const uint8_t SW_GPIO[] = {
    2, 3, 4, 5, 8, 9, 6
};
const uint8_t ENC_GPIO[] = {16, 18};     // L_ENC(0, 1); R_ENC(2, 3)
const bool ENC_REV[] = {false, false};  // Reverse Encoders

#endif

extern bool joy_mode_check;

#endif