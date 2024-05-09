#ifndef CONTROLLER_CONFIG_H
#define CONTROLLER_CONFIG_H

#define SW_GPIO_SIZE 7                // Number of switches
#define ENC_GPIO_SIZE 2               // Number of encoders
#define ENC_PPR 24                    // Encoder PPR
#define MOUSE_SENS 5                  // Mouse sensitivity multiplier
#define ENC_DEBOUNCE true             // Encoder Debouncing
#define SW_DEBOUNCE_TIME_US 4000      // Switch debounce delay in us
#define ENC_PULSE (ENC_PPR * 4)       // 4 pulses per PPR

#ifdef JANKY_SDVX_CONTROLLER_C

// MODIFY KEYBINDS HERE, MAKE SURE LENGTHS MATCH SW_GPIO_SIZE
const uint8_t SW_KEYCODE[] = {
    HID_KEY_D, // BT-A
    HID_KEY_F, // BT-B
    HID_KEY_J, // BT-C
    HID_KEY_K, // BT-D
    HID_KEY_C, // FX-L
    HID_KEY_M, // FX-R
    HID_KEY_1, // START
};
const uint8_t SW_GPIO[] = {
    2, // BT-A
    3, // BT-B
    4, // BT-C
    5, // BT-D
    6, // FX-L
    7, // FX-R
    10 // START
};
const uint8_t ENC_GPIO[] = {
    14, // VOL-L
    16, // VOL-R
};
const bool ENC_REV[] = {false, false};  // Reverse Encoders

#endif
extern bool joy_mode_check;
#endif