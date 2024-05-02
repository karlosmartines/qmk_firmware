#include QMK_KEYBOARD_H
#include "keymap_us_extended.h"
#include "oneshot.h"
#include "print.h"
 void matrix_init_user(void) {
     debug_enable=true;
     debug_matrix=true;
     debug_keyboard=true;
//     debug_mouse=true;
 }

enum layer {
    _BASE,
    _NOR,
    _SYM,
    _WM_NAV,
    _NUM_NAV
};

enum custom_keycodes {
    OS_CTRL = SAFE_RANGE,
    OS_GUI,
    OS_ALT,
    OS_SHFT,
    CLEAR,
};
#define WM_LEFT S(A(KC_J))
#define WM_RGHT S(A(KC_K))

#include <stdio.h>

const char* mod_to_string(uint8_t mod) {
    static char mod_str[128];
    mod_str[0] = '\0'; // Start with an empty string

    if (mod & MOD_BIT(KC_LCTL))  strcat(mod_str, "LCTRL ");
    if (mod & MOD_BIT(KC_RCTL))  strcat(mod_str, "RCTRL ");
    if (mod & MOD_BIT(KC_LSFT)) strcat(mod_str, "LSHIFT ");
    if (mod & MOD_BIT(KC_RSFT)) strcat(mod_str, "RSHIFT ");
    if (mod & MOD_BIT(KC_LALT))   strcat(mod_str, "LALT ");
    if (mod & MOD_BIT(KC_RALT))   strcat(mod_str, "RALT ");
    if (mod & MOD_BIT(KC_LGUI))   strcat(mod_str, "LGUI ");
    if (mod & MOD_BIT(KC_RGUI))   strcat(mod_str, "RGUI ");

    // Trim the last space for neatness
    if (strlen(mod_str) > 0) {
        mod_str[strlen(mod_str) - 1] = '\0';
    }

    return mod_str;
}

void print_mods(uint8_t mods) {
    uprintf("Active Mods: %s\n", mod_to_string(mods));
}

const char* keycode_to_string(uint16_t keycode) {
    switch (keycode) {
        case KC_A: return "KC_A";
        case KC_B: return "KC_B";
        case KC_C: return "KC_C";
        case KC_D: return "KC_D";
        case KC_E: return "KC_E";
        case KC_F: return "KC_F";
        case KC_G: return "KC_G";
        case KC_H: return "KC_H";
        case KC_I: return "KC_I";
        case KC_J: return "KC_J";
        case KC_K: return "KC_K";
        case KC_L: return "KC_L";
        case KC_M: return "KC_M";
        case KC_N: return "KC_N";
        case KC_O: return "KC_O";
        case KC_P: return "KC_P";
        case KC_Q: return "KC_Q";
        case KC_R: return "KC_R";
        case KC_S: return "KC_S";
        case KC_T: return "KC_T";
        case KC_U: return "KC_U";
        case KC_V: return "KC_V";
        case KC_W: return "KC_W";
        case KC_X: return "KC_X";
        case KC_Y: return "KC_Y";
        case KC_Z: return "KC_Z";
        case KC_1: return "KC_1";
        case KC_2: return "KC_2";
        case KC_3: return "KC_3";
        case KC_4: return "KC_4";
        case KC_5: return "KC_5";
        case KC_6: return "KC_6";
        case KC_7: return "KC_7";
        case KC_8: return "KC_8";
        case KC_9: return "KC_9";
        case KC_0: return "KC_0";
        case KC_ENTER: return "KC_ENTER";
        case KC_ESCAPE: return "KC_ESCAPE";
        case KC_BACKSPACE: return "KC_BACKSPACE";
        case KC_TAB: return "KC_TAB";
        case KC_SPACE: return "KC_SPACE";
        case KC_MINUS: return "KC_MINUS";
        case KC_EQUAL: return "KC_EQUAL";
        case KC_LBRC: return "KC_LBRC";
        case KC_RBRC: return "KC_RBRC";
        case KC_BACKSLASH: return "KC_BACKSLASH"; // Backslash and pipe key
        case KC_NONUS_HASH: return "KC_NONUS_HASH"; // Non-US # and ~
        case KC_SEMICOLON: return "KC_SEMICOLON"; // Semicolon and colon
        case KC_QUOTE: return "KC_QUOTE"; // Quote and double quote
        case KC_GRAVE: return "KC_GRAVE"; // Grave accent and tilde
        case KC_COMMA: return "KC_COMMA";
        case KC_DOT: return "KC_DOT";
        case KC_SLASH: return "KC_SLASH";
        case KC_CAPS_LOCK: return "KC_CAPS_LOCK";
        case KC_F1: return "KC_F1";
        case KC_F2: return "KC_F2";
        case KC_F3: return "KC_F3";
        case KC_F4: return "KC_F4";
        case KC_F5: return "KC_F5";
        case KC_F6: return "KC_F6";
        case KC_F7: return "KC_F7";
        case KC_F8: return "KC_F8";
        case KC_F9: return "KC_F9";
        case KC_F10: return "KC_F10";
        case KC_F11: return "KC_F11";
        case KC_F12: return "KC_F12";
            //        case KC_PSCREEN: return "KC_PSCREEN";
            //        case KC_SCROLLLOCK: return "KC_SCROLLLOCK";
        case KC_PAUSE: return "KC_PAUSE";
        case KC_INSERT: return "KC_INSERT";
        case KC_HOME: return "KC_HOME";
        case KC_PGUP: return "KC_PGUP";
        case KC_DELETE: return "KC_DELETE";
        case KC_END: return "KC_END";
            //        case KC_PGDOWN: return "KC_PGDOWN";
        case KC_RIGHT: return "KC_RIGHT";
        case KC_LEFT: return "KC_LEFT";
        case KC_DOWN: return "KC_DOWN";
        case KC_UP: return "KC_UP";
            //        case KC_NUMLOCK: return "KC_NUMLOCK";
        case KC_KP_SLASH: return "KC_KP_SLASH";
        case KC_KP_ASTERISK: return "KC_KP_ASTERISK";
        case KC_KP_MINUS: return "KC_KP_MINUS";
        case KC_KP_PLUS: return "KC_KP_PLUS";
        case KC_KP_ENTER: return "KC_KP_ENTER";
        case KC_KP_1: return "KC_KP_1";
        case KC_KP_2: return "KC_KP_2";
        case KC_KP_3: return "KC_KP_3";
        case KC_KP_4: return "KC_KP_4";
        case KC_KP_5: return "KC_KP_5";
        case KC_KP_6: return "KC_KP_6";
        case KC_KP_7: return "KC_KP_7";
        case KC_KP_8: return "KC_KP_8";
        case KC_KP_9: return "KC_KP_9";
        case KC_KP_0: return "KC_KP_0";
        case KC_KP_DOT: return "KC_KP_DOT";
        case OS_GUI: return "OS_GUI";
        case OS_CTRL: return "OS_CTRL";
        case OS_SHFT: return "OS_SHFT";
        case OS_ALT: return "OS_ALT";
            // Add more cases as needed
        default: return "Unknown Keycode";
    }
}

// clang-format off
const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] =
LAYOUT(
        KC_COMM, KC_H, KC_Y, KC_G, KC_B, QK_BOOT, KC_C, QK_REP, KC_U, KC_DOT,
        KC_R, KC_L, KC_S, KC_T, KC_D, KC_M, KC_N, KC_A, KC_I, KC_O,
        KC_X, KC_K, KC_F, KC_P, KC_J, KC_V, KC_W, S(KC_9), S(KC_0), S(KC_MINS),
        OSL(_SYM), LT(MO(_WM_NAV), KC_SPC), KC_E, MO(_NUM_NAV)
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
        US_PIPE, US_LCBR, US_RCBR, US_MINS, US_BSLS, US_GRV, US_QUES, US_LBRC, KC_RBRC, US_AT,
        US_TILD, US_LABK, US_RABK, US_PERC, KC_NO, US_SLSH, US_AMPR, US_LPRN, US_RPRN, US_UNDS,
        OS_CTRL, OS_SHFT, OS_GUI, OS_ALT
),
[_WM_NAV] =
LAYOUT(
        KC_TAB, C(KC_7), C(KC_8), C(KC_9), KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_ENT, KC_DEL,
        KC_ESC, C(KC_1), C(KC_2), C(KC_3), C(KC_0), WM_LEFT, KC_DOWN, KC_UP, WM_RGHT, KC_BSPC,
        KC_TRNS, C(KC_4), C(KC_5), C(KC_6), KC_TRNS, KC_TRNS, _______, KC_TRNS, KC_TRNS, KC_TRNS,
        OS_CTRL, _______, OS_GUI, OS_ALT
),
[_NUM_NAV] =
LAYOUT(
        KC_TAB, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_ENT, KC_DEL,
        KC_ESC, KC_1, KC_2, KC_3, KC_0, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC,
        KC_TRNS, KC_4, KC_5, KC_6, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        OS_CTRL, OS_ALT, OS_GUI, _______
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
static uint16_t last_key_down = KC_NO;
static uint16_t last_key_up   = KC_NO;


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
    uprintf("process_oneshot_key | keycode: %d  | record: %s\n", keycode, *record);
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
const uint16_t PROGMEM osg[] = {KC_M, KC_N, COMBO_END};
//enum combo_events {
//    COMBO_NOR_LAYER_TOGGLE,
//};
combo_t key_combos[COMBO_COUNT] = {
        COMBO(to_layer_nor, TO(_NOR)),
        COMBO(to_layer_base, TO(_BASE)),
        COMBO(type_z, KC_Z),
        COMBO(type_q, KC_Q),
//    COMBO(type_qu, KC_Q + KC_U)
        COMBO(tap_bspc, KC_BSPC),
        COMBO(tap_del, KC_DEL),
        COMBO(tap_ent, KC_ENT),
        COMBO(tap_esc, KC_ESC),
        COMBO(osg, OS_GUI)
};

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
//     Error: Too many arguments for format. Meh!
//    #ifdef CONSOLE_ENABLE
//        if (record->event.pressed) {
//        uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
//                keycode,
//                record->event.key.row,
//                record->event.key.col,
//                get_highest_layer(layer_state),
//                record->event.pressed,
//                get_mods(),
//                get_oneshot_mods(),
//                record->tap.count
//        );
//    }
//    #endif
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

void print_record(uint16_t keycode, keyrecord_t *record) {
    uprintf("KC: %s %d, Pressed: %d, Time: %u, Tap Count: %u, Tap interrupted: %d \n",
            keycode_to_string(keycode),
            record->event.key,
            record->event.pressed,
            record->event.time,
            record->tap.count,
            record->tap.interrupted
            );
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("Key: %s \n", keycode_to_string(keycode));
    print_record(keycode, record);
    uprintf("1 Active Mods: %s\n", mod_to_string(get_mods()));
//    print_mods(get_mods());
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

   if (record->event.pressed) {
        last_key_down = keycode;
    } else {
        last_key_up = keycode;
    }

    uprintf("2 Active Mods: %s\n", mod_to_string(get_mods()));
    return res;
}

