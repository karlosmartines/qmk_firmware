#include QMK_KEYBOARD_H
#include "keymap_us_international_linux.h"

// void matrix_init_user(void) {
//   // debug_enable=true;
//   // debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }
const uint16_t PROGMEM to_layer_nor[] = {S(KC_9), S(KC_0), S(KC_MINS), COMBO_END};
const uint16_t PROGMEM to_layer_base[] = {US_ARNG, US_OSTR, US_AE, COMBO_END};
const uint16_t PROGMEM type_z[] = {KC_QUOT, KC_C, COMBO_END};
const uint16_t PROGMEM type_q[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM tap_bspc[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM tap_del[] = {KC_U, KC_DOT, COMBO_END};
const uint16_t PROGMEM tap_ent[] = {KC_DOT, KC_O, COMBO_END};
const uint16_t PROGMEM tap_esc[] = {KC_H, KC_L, COMBO_END};
//enum combo_events {
//    COMBO_NOR_LAYER_TOGGLE,
//};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(to_layer_nor, TO(1)),
    COMBO(to_layer_base, TO(0)),
    COMBO(type_z, KC_Z),
    COMBO(type_q, KC_Q),
//    COMBO(type_qu, KC_Q + KC_U)
    COMBO(tap_bspc, KC_BSPC),
    COMBO(tap_del, KC_DEL),
    COMBO(tap_ent, KC_ENT),
    COMBO(tap_esc, KC_ESC)
};


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
    [2]  = LAYOUT(
    US_COMM,    US_PLUS, US_ASTR, US_EXLM, KC_NO,      KC_NO, US_HASH, QK_REP,   US_CIRC,    KC_DOT,
    US_PIPE, US_LCBR, US_RCBR, US_MINS, US_BSLS,      US_DGRV,     US_QUES, US_LBRC, US_RBRC, US_AT,
    US_TILD, US_LABK, US_RABK, US_PERC, KC_NO,      US_SLSH, US_AMPR, US_LPRN, US_RPRN, US_UNDS,
                                 _______, _______,      _______, _______
    ),
    [3] = LAYOUT(
    KC_TAB,    KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_BSPC, KC_DEL,
    KC_ESC,    KC_4,    KC_5,    KC_6, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_DOWN, KC_ENT,
    KC_TRNS,    KC_1,    KC_2,    KC_3, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
// clang-format on
