#include QMK_KEYBOARD_H

// Then we define some combos

const uint16_t PROGMEM combo1[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_K, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo1, KC_LALT),
    COMBO(combo2, KC_LCTL),
    };

#define FN1_SPC LT(1, KC_SPC)
#define FN2_BSPC LT(2, KC_BSPC)
#define FN3_C LT(3, KC_C)
#define FN4_V LT(4, KC_V)
#define FN5_B LT(5, KC_B)
#define CTL_Z CTL_T(KC_Z)
#define ALT_X ALT_T(KC_X)
#define ALT_N ALT_T(KC_N)
#define CTL_M RCTL_T(KC_M)
#define SFT_ENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,  KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,  SFT_ENT,
    KC_Z,   KC_X,   KC_C,   FN4_V,   FN2_BSPC,   FN1_SPC, KC_B,   KC_N,   KC_M,   KC_DOT
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_TAB, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, KC_BOOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_1,   KC_2,    KC_3, KC_4,    KC_5,    KC_6,    KC_7,    KC_ESC,  KC_TAB,  KC_BSPC,
    KC_4,   KC_5,   KC_6,  KC_F4,   KC_F5,   KC_LEFT,   KC_DOWN,   KC_UP, KC_RGHT, KC_SCLN,
    KC_7,   KC_8,   KC_9,  KC_0 ,   KC_DEL,  _______, _______, _______, _______,  KC_COMM
  ),

  [3] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TAB,  _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [4] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TAB,  _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_COLN, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [5] = LAYOUT_ortho_3x10(
    KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, _______, _______, _______, _______, KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,  KC_TRNS,
    _______, _______, _______, _______, QK_BOOT,   _______, _______, _______, _______, _______
  )

};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
