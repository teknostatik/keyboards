// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0
#include QMK_KEYBOARD_H

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
#define KC_SBSL MT(MOD_LSFT, KC_NUBS)

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
                            KC_ALTA, MO(1), KC_BSPC,                           KC_SPC,  MO(2),   KC_CTF5
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