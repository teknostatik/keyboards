# Cantor Build Guide

## Parts list

This is what we need to build a Cantor:

* [PCB](https://github.com/diepala/cantor/releases/tag/rev1.0) - I order these from [JLCPCB](https://jlcpcb.com/)
* Two STM32F401CC blackpill microcontrollers and sockets - can be picked up really cheaply from Aliexpress
* 42 choc v1 switches 
* 42 choc-compatible 1U keycaps 
* 2 TRRS jacks (PJ-320A)
* TRRS cable
* USB-C cable
* 10-12 rubber feet

All the example code in this guide will be assuming that the [Vial firmware](https://github.com/vial-kb/vial-qmk/tree/vial/keyboards/cantor) will be used. it requires having a working installation of the `vial-qmk` github repository.

## Flashing Controllers

Flash each controller to test they work, and to define which controller belongs to which side of the keyboard. 

Firstly test that your firmware compiles:

    qmk compile -kb cantor -km vial

Then flash each controller in turn:

    qmk flash -kb cantor -km vial --bootloader dfu-util-split-left
    qmk flash -kb cantor -km vial --bootloader dfu-util-split-right

If you get the message `Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)` you will need to bridge BOOT0 to VCC (via BOOT0 button or jumper), short RESET to GND (via RESET button or jumper), and then let go of the BOOT0 bridge.

Once you have done this then label the controllers so you are absolutely sure which is which.

If QMK encounters errors it will let you know. Fix any errors before proceeding to the next step.

## PCB

These steps will get us a PCB that we can test:

1. Solder the sockets to the PCB
2. Solder the TRRS jacks to the PCB
3. Socket the controllers (for this build both controllers will be face down)
4. Connect the two halves with the TRRS cable

## Testing

Plug the keyboard into a computer, and short every single socket to test that the right key codes are sent. I use [QMK Configurator](https://config.qmk.fm/#/test) to test this.

If anything is awry, fix it before soldering switches.

## Soldering switches

Press each switch into the PCB, and ensure they are straight. Then solder each one in turn. 

Once the switches are soldered, repeat the same tests as before. If any switches do not work, or behave oddly (repeated keys, excessive chatter etc.) then resolder them.

## Final touches

Apply 5-6 rubber feet to the bottom of each half of the PCB, and then add keycaps. 

