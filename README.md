# Janky SDVX Controller
A worse version of the [Pocket-SDVX-Pico-v4](https://github.com/speedypotato/Pocket-SDVX-Pico-v4) with no RGB

Both the Leonardo and Pico firmware function mostly the same, use the Leonardo version if you are using a ATmega32u4 microcontroller or the Pico version if you are using a RP2040 microcontroller

## Parts
* x2 Encoders ([PEC16-2015F-N0024](https://mou.sr/3JNRuk8))
* x7 Switches ([Gateron Red](https://mechboards.co.uk/products/gateron-red?variant=41710358888653))
* x1 ATmega32u4 or RP2040 microcontroller ([Raspberry Pi Pico](https://thepihut.com/products/raspberry-pi-pico), [Pro Micro](https://www.aliexpress.com/item/32808519179.html))
* x1 [1U Keycap](https://www.aliexpress.com/item/1005004064331568.html)
* x4 [1.5U Keycaps](https://www.aliexpress.com/item/1005004784994416.html)
* x2 [2U Keycaps](https://www.aliexpress.com/item/1005004784994416.html)

## 3D Printed Parts
* x1 [Case](./Models/Case.stl)
* x1 [Case Top (14.4mm Switch Holes)](./Models/Case%20Top%20(14.4mm%20Switch%20Holes).stl) or [Case Top (14mm Switch Holes)](./Models/Case%20Top%20(14mm%20Switch%20Holes).stl)
* x2 [Knobs (22mm)](./Models/Knob%20(22mm).stl) or [Knobs (25mm)](./Models/Knob%20(25mm).stl)
* x1 [1U Keycap](https://www.printables.com/model/440477-keycaps-for-pico-sdvx-controller)
* x4 [1.5U Keycaps](https://www.printables.com/model/440477-keycaps-for-pico-sdvx-controller)
* x2 [2U Keycaps](https://www.printables.com/model/440477-keycaps-for-pico-sdvx-controller)

## Pico GPIO
* `GP2`: BT-A
* `GP3`: BT-B
* `GP4`: BT-C
* `GP5`: BT-D
* `GP8`: FX-L
* `GP9`: FX-R
* `GP6`: START
* `GP14` & `GP15`: VOL-L
* `GP16` & `GP17`: VOL-R

## Leonardo/Pro Micro GPIO
* `2`: BT-A
* `3`: BT-B
* `4`: BT-C
* `5`: BT-D
* `6`: FX-L
* `7`: FX-R
* `21`: START
* `8` & `9`: VOL-L
* `10` & `16`: VOL-R

## Pictures
![Top + Keycaps](./Pictures/Top%20+%20Keycaps.png)
![Top](./Pictures/Top.png)
![Pico Inside](./Pictures/Pico%20Inside.png)
![Pico Inside Bottom](./Pictures/Pico%20Inside%20Bottom.png)
## Pico Pins
![Pico Pins](./Pictures/Pico%20Pins.png)
## Pro Micro Pins
![Pro Micro Pins](./Pictures/Pro%20Micro%20Pins.png)
# DO NOT SCROLL PAST HERE!
![Luxury SDVX Controller](./Pictures/Luxury%20SDVX%20Controller.png)