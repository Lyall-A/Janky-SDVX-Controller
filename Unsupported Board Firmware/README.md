Stolen from https://github.com/speedypotato/Pocket-SDVX

This firmware uses Serial instead of HID and should really **not** be used. This should work with all microcontrollers that can be flashed using Arduino IDE, supports Serial and supports the Arduino Encoder library (has interrupt pins)

## Flashing the firmware
* Open the `Janky-SDVX-Controller.ino` file in [Arduino IDE](https://www.arduino.cc/en/software)
* Modify all the pins
* Go to `Tools > Board` and select your board
* Go to `Tools > Port` and select your port
* Press `Upload` (`CTRL+U`) to compile and upload the firmware to your board
* Run `Start.bat` and input your port and 9600 for baud rate OR run `Serial-To-HID.exe <port> 9600`