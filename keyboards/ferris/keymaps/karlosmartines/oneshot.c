#include "oneshot.h"

void update_oneshot_pre(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            uprintf("update_oneshot_pre pressed | mod: %d state: %d\n", mod, *state);
            // Trigger keydown
            if (*state == os_up_unqueued) {
                uprintf("update_oneshot_pre pressed unqueued | mod: %d state: %d\n", mod, *state);
                register_code(mod);
            }
            *state = os_down_unused;
            uprintf("update_oneshot_pre pressed | mod: %d state: %d\n", mod, *state);
//            print_mods(get_mods());
        } else {
            // Trigger keyup
            uprintf("update_oneshot_pre keyup | state: %d \n", *state);
            switch (*state) {
                case os_down_unused:
                    uprintf("update_oneshot_pre keyup unused | state: %d \n", *state);
                    // If we didn't use the mod while trigger was held, queue it.
                    *state = os_up_queued;
//                    print_mods(get_mods());
                    break;
                case os_down_used:
                    uprintf("update_oneshot_pre keyup used | state: %d \n", *state);
                    // If we did use the mod while trigger was held, unregister it.
                    *state = os_up_unqueued;
                    unregister_code(mod);
//                    print_mods(get_mods());
                    uprintf("update_oneshot_pre keyup used | state: %d \n", *state);
                    break;
                default:
                    break;
            }
        }
    } else {
        if (record->event.pressed) {
//            print_mods(get_mods());
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
//                print_mods(get_mods());
            }
        }
    }
}

void update_oneshot_post(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode != trigger && !record->event.pressed) {
        if (!is_oneshot_ignored_key(keycode)) {
            uprintf("update_oneshot_post isnotignoredkey | mod: %d state: %d \n", mod, *state);
//            print_mods(get_mods());
            // On non-ignored keyup, consider the oneshot used.
            switch (*state) {
                case os_down_unused:
                    uprintf("update_oneshot_post isnotignoredkey unused | mod: %d state: %d \n", mod, *state);
                    *state = os_down_used;
//                    print_mods(get_mods());
                    break;
                case os_up_queued:
                    uprintf("update_oneshot_post isnotignoredkey queued | mod: %d state: %d \n", mod, *state);
                    *state = os_up_unqueued;
                    unregister_code(mod);
//                    print_mods(get_mods());
                    break;
                default:
                    break;
            }
        }
    }
}