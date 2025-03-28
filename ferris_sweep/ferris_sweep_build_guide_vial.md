# Ferris Sweep Build Guide

The Ferris Sweep is a 34-key split board with an aggressive stagger. I have built a few of these, both for my own use and for other people. 

## Parts list

This is what we need to build a Ferris Sweep:

* [Sweep High PCB](https://github.com/davidphilipbarr/Sweep/tree/main/Sweep%20High). I get mine printed by [JLCPCB](https://jlcpcb.com/).
* Two controllers and sockets. I have built these with a number of different controllers, but mostly the Pro-Micro to keep the cost down.
* 34 switches (Choc v1 or v2, or MX). For this minimal build a low-profile switch makes a lot more sense.
* 34 1U keycaps to match switches chosen. Blank keycaps will bring the cost down if they are an option for you.
* 2 TRRS jacks (PJ-320A)
* TRRS cable
* Cable to match controllers chosen (almost certainly a USB-C cable)
* 10-12 rubber feet (these are definitely _not_ optional on this build)

All the example code in this guide will be assuming that the [Vial firmware](https://github.com/vial-kb/vial-qmk/tree/vial/keyboards/ferris/sweep) will be used. It requires having a working installation of the [`vial-qmk`](https://github.com/vial-kb/vial-qmk) github repository.

## Flashing Controllers

Flash each controller to test they work, and to define which controller belongs to which side of the keyboard. 

Firstly test that your firmware compiles:

    qmk compile -kb ferris/sweep -km vial

Then flash each controller in turn:

### Pro-Micro

    qmk flash -kb ferris/sweep -km vial --bootloader avrdude-split-left
    qmk flash -kb ferris/sweep -km vial --bootloader avrdude-split-right

If you get the message `Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)` you will need to Short RST to GND quickly in order to flash the controller. 

### Elite-Pi

    qmk flash -c -kb ferris/sweep -km vial -e CONVERT_TO=elite_pi --bootloader uf2-split-left
    qmk flash -c -kb ferris/sweep -km vial -e CONVERT_TO=elite_pi --bootloader uf2-split-right

### Frood

    qmk flash -c -kb ferris/sweep -km vial -e CONVERT_TO=promicro_rp2040 --bootloader uf2-split-left
    qmk flash -c -kb ferris/sweep -km vial -e CONVERT_TO=promicro_rp2040 --bootloader uf2-split-right

### Elite-C

    qmk flash -kb ferris/sweep -km vial --bootloader dfu-split-left
    qmk flash -kb ferris/sweep -km vial --bootloader dfu-split-right

Once you have done this then label the controllers so you are absolutely sure which is which.

If QMK encounters errors it will let you know. Fix any errors before proceeding to the next step.

## PCB

These steps will get us a PCB that we can test:

1. Solder the sockets to the PCB
2. Solder the TRRS jacks to the PCB
3. Socket the controllers (for this build both controllers will be face down, but there is a handy message printed on the PCB which will help with orientation)
4. Connect the two halves with the TRRS cable

## Testing

Plug the keyboard into a computer, and short every single socket to test that the right key codes are sent. I use [QMK Configurator](https://config.qmk.fm/#/test) to test this.

If anything does not work, fix it before soldering switches.

## Soldering switches

Press each switch into the PCB, and ensure they are straight. Then solder each one in turn. 

Once the switches are soldered, repeat the same tests as before. If any switches do not work, or behave oddly (repeated keys, excessive chatter etc.) then resolder them.

## Final touches

Apply 5-6 rubber feet to the bottom of each half of the PCB, and then add keycaps. 

## Alternatives

I have used [the Mechboards Ferris Sweep](https://mechboards.co.uk/products/ferris-sweep-kit?variant=41437490577613) for a few builds, and it's great. All you need with this one is controllers, keycaps and switches. It's also got a functional case, and will work with the fancier cases that Mechboards sell.

