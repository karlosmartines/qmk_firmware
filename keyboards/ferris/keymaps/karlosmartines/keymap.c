#include QMK_KEYBOARD_H

// void matrix_init_user(void) {
//   // debug_enable=true;
//   // debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_SCLN, KC_H,    KC_Y,    KC_G,    KC_B,    KC_TRNS,   KC_C,    KC_COMM, KC_U,    KC_MINS,
    KC_R,    KC_L,    KC_S,    KC_T,    KC_D,    KC_M,      KC_N,    KC_A,    KC_I,    KC_O,
    KC_X,    KC_K,    KC_F,    KC_P,    KC_J,    KC_V,      KC_W,    KC_DOT,  KC_SLSH, KC_QUOT,
                               KC_TRNS, KC_SPC, KC_TRNS,   KC_E
),

};
// clang-format on
