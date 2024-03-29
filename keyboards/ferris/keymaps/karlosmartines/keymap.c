#include QMK_KEYBOARD_H
#include "keymap_us_extended.h"

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
                               DF(3), LT(2, KC_SPC),  KC_E,      DF(4)
    ),
    [1] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, US_ARNG, US_OSTR, US_AE,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2]  = LAYOUT( // This should be a one-shot layer I think
    US_COMM,    US_PLUS, US_ASTR, US_EXLM, KC_NO,      KC_NO, US_HASH, QK_REP,   US_CIRC,    KC_DOT,
    US_PIPE, US_LCBR, US_RCBR, US_MINS, US_BSLS,      US_DGRV,     US_QUES, US_LBRC, US_RBRC, US_AT,
    US_TILD, US_LABK, US_RABK, US_PERC, KC_NO,      US_SLSH, US_AMPR, US_LPRN, US_RPRN, US_UNDS,
                                 KC_LCTL, _______,      KC_LGUI, KC_LALT
    ),
    [3] = LAYOUT(
        KC_TAB,    C(KC_7),    C(KC_8),    C(KC_9), KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_BSPC, KC_DEL,
        KC_ESC,    C(KC_1),    C(KC_2),    C(KC_3), C(KC_0), KC_LEFT, KC_DOWN, KC_UP, KC_DOWN, KC_ENT,
        KC_TRNS,    C(KC_4),    C(KC_5),    C(KC_6), KC_TRNS, KC_TRNS, LCTL(KC_LEFT), KC_TRNS, KC_TRNS, KC_TRNS,
                                        DF(0), S(KC_LALT), KC_LGUI, KC_RALT
    ),
    [4] = LAYOUT(
        KC_TAB,    KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_BSPC, KC_DEL,
        KC_ESC,    KC_1,    KC_2,    KC_3, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_DOWN, KC_ENT,
        KC_TRNS,    KC_4,    KC_5,    KC_6, KC_0, KC_TRNS, LCTL(KC_LEFT), KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_NO, KC_TRNS, KC_TRNS, DF(0)
    )
// What functions will I be using this layer for?
// I want tap to be change to layer, so that I can backspace, scroll with arrow keys.
// I also want it to act like a navigationlayer for my window manager, but also Id like to keep the modifier keys on the four thumbkeys consistently.
// I think the order ctrl, alt, gui(windows/cmd) make sense. These need to be callum style one-shot on layer 2
// For the window navigation I need:
// goto ws num, goto ws left/right
// moveto ws num, moveto ws left/right
// change window positions on current ws        shift + ctrl + option + j/k
// change window size                           shift + option + h/l
// change layout                                shift + option + space // shift + option + ctrl + space
// I should maybe have two versions of this layer? One that stays in the layer for when I want to keep moving and one to exit after number and arrow e.g.
//
//
//
//
//
//
//
//
//
};
// clang-format on
