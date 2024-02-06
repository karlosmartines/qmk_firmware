#include QMK_KEYBOARD_H

void matrix_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        KC_J,       KC_C,   KC_Y,   KC_F,   KC_K,     KC_Z,   KC_L,   KC_COMM,    KC_U,       KC_Q,
        KC_R,       KC_S,   KC_T,   KC_H,   KC_D,     KC_M,   KC_N,   KC_A,       KC_I,       KC_O,
        KC_SLASH,   KC_V,   KC_G,   KC_P,   KC_B,     KC_X,   KC_W,   KC_DOT,     KC_SCLN,    KC_MINS,
                                    KC_E,   KC_BSPC,  KC_ENT, KC_SPC
    )
};
// clang-format on
