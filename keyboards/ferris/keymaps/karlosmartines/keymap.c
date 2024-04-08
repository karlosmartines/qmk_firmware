#include QMK_KEYBOARD_H
#include "oneshot.h"
#include "keymap_us_extended.h"

// void matrix_init_user(void) {
//   // debug_enable=true;
//   // debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }

enum layer {
    _BASE,
    _NOR,
    _SYM,
    _WM_NAV,
    _NUM_NAV
};

enum custom_keycodes {
    OS_CTRL,
    OS_GUI,
    OS_ALT,
    OS_SHFT,
    CLEAR,
};

// clang-format off
const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] =
LAYOUT(
        KC_COMM, KC_H, KC_Y, KC_G, KC_B, QK_BOOT, KC_C, QK_REP, KC_U, KC_DOT,
        KC_R, KC_L, KC_S, KC_T, KC_D, KC_M, KC_N, KC_A, KC_I, KC_O,
        KC_X, KC_K, KC_F, KC_P, KC_J, KC_V, KC_W, S(KC_9), S(KC_0), S(KC_MINS),
        OSL(_SYM), LT(DF(_WM_NAV), KC_SPC), KC_E, DF(_NUM_NAV)
),
[_NOR] =
LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, US_ARNG, US_OSTR, US_AE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_SYM]  =
LAYOUT( // This should be a one-shot layer I think
        US_COMM, US_PLUS, US_ASTR, US_EXLM, KC_NO, KC_NO/*CW here?*/, US_HASH, QK_REP, US_CIRC, KC_DOT,
        US_PIPE, US_LCBR, US_RCBR, US_MINS, US_BSLS, US_GRV, US_QUES, US_LBRC, US_RBRC, US_AT,
        US_TILD, US_LABK, US_RABK, US_PERC, KC_NO, US_SLSH, US_AMPR, US_LPRN, US_RPRN, US_UNDS,
        OS_CTRL, OS_SHFT, OS_GUI, OS_ALT
),
[_WM_NAV] =
LAYOUT(
        KC_TAB, C(KC_7), C(KC_8), C(KC_9), KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_BSPC, KC_DEL,
        KC_ESC, C(KC_1), C(KC_2), C(KC_3), C(KC_0), KC_LEFT, KC_DOWN, KC_UP, KC_DOWN, KC_ENT,
        KC_TRNS, C(KC_4), C(KC_5), C(KC_6), KC_TRNS, KC_TRNS, LCTL(KC_LEFT), KC_TRNS, KC_TRNS, KC_TRNS,
        _______, DF(_BASE), OS_GUI, OS_ALT
),
[_NUM_NAV] =
LAYOUT(
        KC_TAB, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_BSPC, KC_DEL,
        KC_ESC, KC_1, KC_2, KC_3, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_DOWN, KC_ENT,
        KC_TRNS, KC_4, KC_5, KC_6, KC_0, KC_TRNS, LCTL(KC_LEFT), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO, KC_TRNS, KC_TRNS, DF(_BASE)
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

// One-shot mods

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_pre(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_pre(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_pre(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_post(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_post(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_post(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
}

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

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            layer_off(_NUM_NAV);
            layer_off(_WM_NAV);
            layer_off(_SYM);
            layer_move(_BASE);
            return false;
    }
            return true;
    }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_oneshot_pre(keycode, record);

    // If `false` was returned, then we did something special and should register that manually.
    // Otherwise register keyrepeat here by default.
    bool res = _process_record_user(keycode, record);

    // Space needs some special handling to not interfere with NAV toggling.
    // Maybe there's a more general way to do this, but I dunno.
//    if (keycode == MT_SPC) {
//        if (!record->event.pressed && last_key_down == MT_SPC) {
//            register_key_to_repeat(KC_SPC);
//        }
//    } else if (res && record->event.pressed) {
//        register_key_to_repeat(keycode);
//    }

    process_oneshot_post(keycode, record);

//    if (record->event.pressed) {
//        last_key_down = keycode;
//    } else {
//        last_key_up = keycode;
//    }

    return res;
}

