/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define VIAL_TAP_DANCE_ENTRIES 10
#define VIAL_KEYBOARD_UID {0x47, 0x97, 0x7E, 0x32, 0xC9, 0xAC, 0x13, 0xF3}

#define VIAL_UNLOCK_COMBO_ROWS { 2, 3, 0, 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1, 0, 2, 4 }

    #undef DIRECT_PINS
    #define DIRECT_PINS { \
        { D7, F7, F6, F5, F4 }, \
        { B1, B3, B2, B6, D3 }, \
        { D1, D0, D4, C6, E6 }, \
        { B5, B4, NO_PIN, NO_PIN, NO_PIN } \
    }
    #undef DIRECT_PINS_RIGHT
    #define DIRECT_PINS_RIGHT { \
        { F4, F5, F6, F7, D7 }, \
        { D1, D3, B2, B3, B1 }, \
        { B4, E6, C6, B5, D0 }, \
        { B6, D4, NO_PIN, NO_PIN, NO_PIN } \
    }


