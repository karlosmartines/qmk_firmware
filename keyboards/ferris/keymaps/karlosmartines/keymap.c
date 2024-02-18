//#include "quantum.h"
#include QMK_KEYBOARD_H
#include "keymap_us_international_linux.h"
//#include "keymap_norwegian.h"
//#include "sendstring_norwegian.h"
//#include "keymap_"

// void matrix_init_user(void) {
//   // debug_enable=true;
//   // debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }
//const uint16_t PROGMEM nor[] = {S(KC_9), S(KC_0), S(KC_MINS)};
//enum combo_events {
//    COMBO_NOR_LAYER_TOGGLE,
//};
//combo_t key_combos[COMBO_COUNT] = {
//    [COMBO_NOR_LAYER_TOGGLE] = COMBO_ACTION(TO(1)),
//};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_COMM, KC_H,    KC_Y,    KC_G,    KC_B,    KC_QUOT,   KC_C,    QK_REP, KC_U,    KC_DOT,
    KC_R,    KC_L,    KC_S,    KC_T,    KC_D,    KC_M,      KC_N,    KC_A,    KC_I,    KC_O,
    KC_X,    KC_K,    KC_F,    KC_P,    KC_J,    KC_V,      KC_W,    S(KC_9),  S(KC_0), S(KC_MINS),
                               KC_TRNS, LT(2, KC_SPC),  KC_E,      KC_NO
    ),
    [1] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, US_ARNG, US_OSTR, US_AE,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
    KC_TAB,    KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL,
    KC_ESC,    KC_4,    KC_5,    KC_6, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
    KC_TRNS,    KC_1,    KC_2,    KC_3, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
// clang-format on
