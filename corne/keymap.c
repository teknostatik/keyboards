/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// Add some definitions so that complicated keymaps can be expressed in fewer characters

#define KC_ALTA MT(MOD_LALT, KC_TAB)
#define KC_CTF5 MT(MOD_LCTL, KC_F5)
#define KC_SHEN MT(MOD_RSFT, KC_ENT)
#define KC_LCAD LCA(KC_DEL)
#define KC_RCSE RCS(KC_ENT)
#define KC_RCSD RCS(KC_DOWN)
#define KC_SCV RCS(KC_V)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_SESC MT(MOD_LCTL, KC_ESC)
#define KC_SBSL MT(MOD_LALT, KC_NUBS)
#define KC_ENM2 LT(2, KC_ENT)
#define KC_TBM1 LT(1, KC_TAB)

// Then we define some combos

const uint16_t PROGMEM combo1[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_X, KC_C, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo1, KC_LALT),
    COMBO(combo2, KC_LCTL),
    COMBO(combo3, KC_BSPC),
    COMBO(combo4, KC_LGUI),
};
// This is the keymap itself, using the custom definitions

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TAB,    KC_Q,   KC_W,   KC_E,    KC_R,  KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_SESC,   KC_A,   KC_S,   KC_D,    KC_F,  KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_SBSL,   KC_Z,   KC_X,   KC_C,    KC_V,  KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_SHEN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                          KC_LGUI, KC_TBM1, KC_BSPC,                           KC_SPC,  KC_ENM2,   KC_LCTL
                                      //`--------------------------'  `--------------------------'

),

[1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.             ,-----------------------------------------------------.
    KC_ESC, KC_F1, KC_F2,  KC_F3,   KC_F4, KC_TRNS,                    KC_GRV, KC_LCAD, KC_ESC,  KC_TAB,   KC_BSPC, KC_LCAD,
  //|--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_F5, KC_F6,  KC_F7,  KC_F8, KC_RCSE,                    KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_QUOT, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_F9, KC_F10, KC_F11,  KC_F12, G(KC_L),                  KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_SHEN,  KC_F11,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            KC_LALT, _______,KC_ENT,                   KC_ENT,   MO(3), KC_LGUI
                                      //`--------------------------'  `--------------------------'
),

[2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_GRV, KC_1,   KC_2, KC_3,  KC_TRNS, KC_PSCR,                     KC_TRNS, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RCS(KC_V), KC_4, KC_5, KC_6, KC_TRNS, KC_SCV,                      KC_TRNS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RCS(KC_DOWN), KC_7, KC_8, KC_9, KC_0, KC_RCSD,                     KC_TRNS, KC_NUHS, KC_NUBS, KC_WBAK, KC_WFWD, KC_BTN1,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LALT,   MO(3),  KC_SPC,     KC_ENT, _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'
),

[3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.             ,-----------------------------------------------------.
    QK_BOOT, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------|
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------|
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LALT, _______,  KC_SPC,      KC_ENT, _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'
)
};

// This is the code to make the OLEDs work

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}
return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
if (keycode < 60) {
    name = code_to_name[keycode];
}

  // update keylog
snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
        record->event.key.row, record->event.key.col,
        keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
if (record->event.pressed) {
    set_keylog(keycode, record);
}
return true;
}
#endif // OLED_ENABLE
