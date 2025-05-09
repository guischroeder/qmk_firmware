#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT
};

enum combos {
  JK_ESC
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_AGR  OSM(MOD_RALT)
#define OSL_FUN  OSL(_FUNC)
#define GUI_ENT  GUI_T(KC_ENT)
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define RSE_BSP  LT(_RAISE, KC_BSPC)
#define OSM_SFT  OSM(MOD_LSFT)
#define CTL_ESC  LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_DEL,
    OSM(MOD_LALT), KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H,   KC_J,   KC_K,   KC_L,   KC_QUOT, OSM_AGR,
    OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, OSL_FUN,
                      OSM_LCTL, GUI_ENT, LOW_TAB,    RSE_BSP, KC_SPC, OSM_SFT
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_1,    KC_2,  KC_3,    KC_4,   KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, XXXXXXX, KC_TILD, KC_GRV, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, _______,
                        KC_TRNS, KC_TRNS, LOWER,          KC_TRNS, KC_TRNS, KC_COLON
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
    _______, KC_DEL , XXXXXXX, KC_UNDS, KC_PLUS, KC_PGUP,  XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_PIPE, _______,
    _______, KC_HOME, KC_END , KC_MINS, KC_EQL , KC_PGDN,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_APP , _______,
    _______, KC_LT  , KC_GT  , KC_COPY, KC_PSTE, KC_SCLN,  KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, _______,
                          CTL_ESC, KC_TRNS, XXXXXXX,        RAISE, KC_TRNS, KC_TRNS
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
    _______, KC_F1  , KC_F2  , KC_F3 , KC_F4 ,  KC_F5,     KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 , _______,
    _______, KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET  , XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, FUNC, XXXXXXX
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_RAISE, KC_BSPC):
        case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
        default:
            return TAPPING_TERM;
    }
}

