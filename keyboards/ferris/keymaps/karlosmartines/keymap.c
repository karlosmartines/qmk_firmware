#include QMK_KEYBOARD_H

// void matrix_init_user(void) {
//   // debug_enable=true;
//   // debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(                                // Husk på at jeg skal ha med REPEAT, så la denne stå åpen
    KC_COMM, KC_H,    KC_Y,    KC_G,    KC_B,    KC_QUOT,   KC_C,    REPEAT, KC_U,    KC_SLSH,
    KC_R,    KC_L,    KC_S,    KC_T,    KC_D,    KC_M,      KC_N,    KC_A,    KC_I,    KC_O,
    KC_X,    KC_K,    KC_F,    KC_P,    KC_J,    KC_V,      KC_W,    KC_DOT,  KC_DOT, KC_MINS,
                               KC_TRNS, LT(1, KC_SPC),  KC_E,      TO(1)
    ),
    [1] = LAYOUT(
    KC_TAB,    KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL,
    KC_ESC,    KC_4,    KC_5,    KC_6, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
    KC_TRNS,    KC_1,    KC_2,    KC_3, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        TO(0), KC_TRNS, KC_TRNS, KC_TRNS
),

};
// clang-format on
