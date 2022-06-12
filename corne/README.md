# Notes on my Corne configuration

_The Corne is a 42-key mechanical keyboard. These are my notes on building and configuring it. Largely for my own benefit._

Currently I'm using the [default black case](https://mechboards.co.uk/products/helidox-corne-case?variant=40336262070477) with Kaih heavy burnt orange switches and Drop WOB keycaps.

I'm about half way through getting the keymap how I want it. The defaults are sensible, but I want this to be interchangeable with the Planck and so I have moved a few things around.

As with all my keyboards, I'm using `AUTO_SHIFT_ENABLE`, plus `SPLIT_USB_DETECT` to get it to realise that it is two halves of the _same_ keyboard and not two distinct keyboards.

In _config.h_:

    #define MASTER_LEFT
    #define SPLIT_USB_DETECT

In _rules.mk_:

    OLED_ENABLE = yes
    OLED_DRIVER = SSD1306
    AUTO_SHIFT_ENABLE = yes
    BOOTLOADER = atmel-dfu
    SPLIT_KEYBOARD = yes

I type on this at least a day a week and could probably use it full time at this point.
