#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_60_iso_split_rshift(
        KC_ESC,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        MT(MOD_LCTL, KC_NUHS), KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT,KC_ENT),MO(1),
        MT(MOD_LCTL,KC_F5), MO(1), KC_LALT,               KC_SPC,                        MT(MOD_LALT,KC_LEFT), MT(MOD_LGUI,KC_DOWN), MT(MOD_RALT,KC_UP), MT(MOD_RCTL,KC_RGHT)
    ),

    [1] = LAYOUT_60_iso_split_rshift(
        QM_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, KC_UP,   RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_PSCR, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END
    )
};
