// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};

// Then we add some definitions so that complicated keymaps can be expressed in fewer characters. 
// These are ones I don't use but that other people have found useful:

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)
#define KC_SPM2 LT(2, KC_SPC)

// And these are the ones that I use in my keymap:

#define KC_TBM1 LT(1, KC_TAB)
#define KC_ABSP MT(MOD_LALT, KC_BSPC)
#define KC_CTSP MT(MOD_LCTL, KC_SPC)
#define KC_SHEN MT(MOD_RSFT, KC_ENT)
#define KC_LCAD LCA(KC_DEL)
#define KC_RCSE RCS(KC_ENT)
#define KC_RCSD RCS(KC_DOWN)
#define KC_SCV RCS(KC_V)
#define KC_SESC MT(MOD_LCTL, KC_ESC)
#define KC_SBSL MT(MOD_LSFT, KC_NUBS)

// This is the keymap itself, using the custom definitions:

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    KC_Q, KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    KC_A, KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_QUOT,
    KC_Z, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SHEN,
                            KC_TBM1, KC_ABSP,         KC_CTSP, MO(2)
  ),

  [_LOWER] = LAYOUT( /* [> LOWER <] */
    KC_F1, KC_F2,  KC_F3,   KC_F4,  KC_TRNS,       KC_GRV,  KC_LCAD, QK_GESC, KC_TAB,  KC_BSPC,
    KC_F5, KC_F6,  KC_F7,   KC_F8,  KC_RCSD,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN,
    KC_F9, KC_F10, KC_F11,  KC_F12, G(KC_L),       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_SLSH,
                            KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS  
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_1,  KC_2,   KC_3,    KC_F5,   KC_PSCR,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_4,  KC_5,   KC_6,    KC_TRNS, KC_SCV,       KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    KC_7,  KC_8,   KC_9,    KC_0,    KC_RCSD,      KC_TRNS, KC_NUHS, KC_NUBS, KC_TRNS, QK_BOOT,
                            KC_TRNS, KC_TRNS,      KC_LGUI, KC_TRNS
  )
};
