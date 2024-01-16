/*
 * algernon's ErgoDox EZ layout, please see the readme.md file!
 */

#include <stdarg.h>
#include QMK_KEYBOARD_H
#include "led.h"
#include "action_util.h"
#include "eeconfig.h"
#include "version.h"

/* Layers */

enum {
    BASE = 0,
    GAME,
    ARRW,
    MEDIA,
};

/* Tap Dance */

enum {
    DI_CLN = 0,
    CT_PA,
    CT_LBP,
    CT_RBP,
    CT_SR
};

/* Custom keycodes */

enum {
    // Media stuff
    A_MPN = SAFE_RANGE,

    // number/symbol keys
    A_1, // 1
    A_2, // 2
    A_3, // ...
    A_4,
    A_5,
    A_6,
    A_7,
    A_8,
    A_9,
    A_0,
};

/* States & timers */

bool skip_leds  = false;
bool is_swapped = false;

/* The Keymap */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Base Layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * | Next/Prev | 9    | 7  @ | 5  * | 3  ^ | 1  $ | F11  |           |  F12 | 0  % | 2  ! | 4  # | 6  & | 8    |   GAME    |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |     ~     |   '  |   ,  |   .  |   P  |   Y  |   (  |           |  )   |   F  |   G  |   C  |   R  |  L   | \         |
 * |-----------+------+------+------+------+------|   [  |           |  ]   |------+------+------+------+------+-----------|
 * |    Tab    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |  S   |     =     |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * | Play/ARROW|   /  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |  Z   | Stop/Reset|
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *     |       |      |      |      |   :  |                                       |   -  |      |      |      |       |
 *     `-----------------------------------'                                       `-----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         | LAlt | GUI  |           |      | Del  |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      | Ctrl |           |      |      |      |
 *                                  |Backsp|LShift|------|           |------| Enter| Space|
 *                                  |      |      | ESC  |           | MEDIA|      |      |
 *                                  `--------------------'           `--------------------'
 */
[BASE] = LAYOUT_ergodox(
// left hand
 A_MPN              ,A_9         ,A_7         ,A_5     ,A_3     ,A_1     ,KC_F11
,KC_GRV             ,KC_QUOT     ,KC_COMM     ,KC_DOT  ,KC_P    ,KC_Y    ,TD(CT_LBP)
,KC_TAB             ,KC_A        ,KC_O        ,KC_E    ,KC_U    ,KC_I
,TD(CT_PA)          ,KC_SLSH     ,KC_Q        ,KC_J    ,KC_K    ,KC_X    ,KC_NO
,KC_NO              ,KC_NO       ,KC_NO       ,KC_NO   ,TD(DI_CLN)

                                                            ,OSM(MOD_LALT),KC_LGUI
                                                                          ,OSM(MOD_LCTL)
                                                    ,KC_BSPC,OSM(MOD_LSFT),KC_ESC

                                                                // right hand
                                                               ,KC_F12    ,A_0     ,A_2       ,A_4     ,A_6     ,A_8      ,TG(GAME)
                                                               ,TD(CT_RBP),KC_F    ,KC_G      ,KC_C    ,KC_R    ,KC_L     ,KC_BSLS
                                                                          ,KC_D    ,KC_H      ,KC_T    ,KC_N    ,KC_S     ,KC_EQL
                                                               ,KC_NO     ,KC_B    ,KC_M      ,KC_W    ,KC_V    ,KC_Z     ,TD(CT_SR)
                                                                                   ,KC_MINS   ,KC_NO   ,KC_NO   ,KC_NO    ,KC_NO

                                                               ,KC_NO     ,KC_DEL
                                                               ,KC_NO
                                                               ,OSL(MEDIA),KC_ENT ,KC_SPC
    ),


/* Keymap 1: Gaming Layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |     Esc   |  9   |  7   |  5   |  3   |  1   | F11  |           |  F7  |  0   |  2   |  4   |  6   |  8   |   GAME    |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |     ~     |  "   |  ,   |  .   |  .   |  P   |  F1  |           |  F4  |  F   |  G   |  C   |  R   |  L   |    \      |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |    Tab    |  A   |  O   |  E   |  U   |  I   |------|           |------|  D   |  H   |  T   |  N   |  S   |    =      |
 * |-----------+------+------+------+------+------|  :   |           |  -   |------+------+------+------+------+-----------|
 * |   LShift  |  /   |  Q   |  J   |  K   |  X   |      |           |      |  B   |  M   |  W   |  V   |  Z   |  LShift   |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |  [   |  F2  |  F3  | LAlt | LCtrl|                                       | LCtrl| LAlt |  F6  |  F5  |  ]   |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         | LAlt | Enter|           | Enter| LAlt |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      | Temp | Lctrl|           | Lctrl|      |      |
 *                                  |Backsp| Swap |------|           |------| ARROW| Space|
 *                                  |      |      | Swap |           | Swap |      |      |
 *                                  `--------------------'           `--------------------'
 */

[GAME] = LAYOUT_ergodox(
// left hand
 KC_ESC             ,KC_9        ,KC_7        ,KC_5    ,KC_3    ,KC_1    ,KC_F11
,KC_GRV             ,KC_QUOT     ,KC_COMM     ,KC_DOT  ,KC_P    ,KC_Y    ,KC_F1
,KC_TAB             ,KC_A        ,KC_O        ,KC_E    ,KC_U    ,KC_I
,KC_LSFT            ,KC_SLSH     ,KC_Q        ,KC_J    ,KC_K    ,KC_X    ,KC_SCLN
,KC_LBRC            ,KC_F2       ,KC_F3       ,KC_LALT ,KC_LCTL

                                                            ,KC_LALT ,KC_ENT
                                                                     ,KC_LCTL
                                                    ,KC_BSPC,SH_MON  ,SH_TG

                                                                // right hand
                                                               ,KC_F7     ,KC_0    ,KC_2      ,KC_4    ,KC_6    ,KC_8     ,TG(GAME)
                                                               ,KC_F4     ,KC_F    ,KC_G      ,KC_C    ,KC_R    ,KC_L     ,KC_BSLS
                                                                          ,KC_D    ,KC_H      ,KC_T    ,KC_N    ,KC_S     ,KC_EQL
                                                               ,KC_MINS   ,KC_B    ,KC_M      ,KC_W    ,KC_V    ,KC_Z     ,KC_LSFT
                                                                                   ,KC_LCTL   ,KC_LALT ,KC_F6   ,KC_F5    ,KC_RBRC

                                                               ,KC_ENT    ,KC_LALT
                                                               ,KC_LCTL
                                                               ,SH_TG     ,MO(ARRW) ,KC_SPC
    ),

/* Keymap 2: Arrow layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      | Print| Home |  Up  |  End |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|           |------|      | Left | Down | Rght |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  | Enter|      |------|           |------| PgUp | PgDn |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */

[ARRW] = LAYOUT_ergodox(
// left hand
 KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_TRNS    ,KC_TRNS   ,KC_TRNS    ,KC_TRNS

                                             ,KC_TRNS ,KC_TRNS
                                                      ,KC_TRNS
                                    ,KC_ENT  ,KC_TRNS ,KC_TRNS

                                                                // right hand
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS ,KC_PSCR ,KC_HOME ,KC_UP   ,KC_END  ,KC_TRNS ,KC_TRNS
                                                                        ,KC_TRNS ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                                 ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS

                                                               ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS
                                                               ,KC_TRNS ,KC_PGUP ,KC_PGDN
    ),

/* Keymap 3: Navigation & Media layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |  F9  |  F7  |  F5  |  F3  |  F1  |ScrLCK|           |      | F10  |  F2  |  F4  |  F6  |  F8  |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|           |------|      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         | Mute | VlUp |           | BASE |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      | VlDn |           |      |      |      |
 *                                  |      |      |------|           |------|      |      |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */
[MEDIA] = LAYOUT_ergodox(
// left hand
 KC_NO      ,KC_F9       ,KC_F7      ,KC_F5   ,KC_F3   ,KC_F1   ,LGUI(KC_L)
,KC_NO      ,KC_NO       ,KC_NO      ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO
,KC_NO      ,KC_NO       ,KC_NO      ,KC_NO   ,KC_NO   ,KC_NO
,KC_NO      ,KC_NO       ,KC_NO      ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO
,KC_NO      ,KC_NO       ,KC_NO      ,KC_NO   ,KC_NO
                                                        ,KC_MUTE ,KC_VOLU
                                                                 ,KC_VOLD
                                                 ,KC_NO ,KC_NO   ,KC_TRNS

                                                                     // right hand
                                                                     ,KC_TRNS   ,KC_F10  ,KC_F2   ,KC_F4   ,KC_F6   ,KC_F8    ,KC_NO
                                                                     ,KC_NO     ,KC_NO   ,KC_NO   ,KC_UP   ,KC_NO   ,KC_NO    ,KC_NO
                                                                                ,KC_NO   ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_NO    ,KC_NO
                                                                     ,KC_NO     ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO    ,KC_NO
                                                                                         ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO    ,KC_NO

                                                                     ,KC_TRNS   ,KC_NO
                                                                     ,KC_NO
                                                                     ,KC_NO     ,KC_NO   ,KC_NO
    ),

};

static void ang_handle_num_row(uint16_t id, keyrecord_t *record) {
    uint16_t    idx = id - A_1;
    uint16_t    kc;
    static bool shifted[10];

    if (get_mods() & MOD_BIT(KC_LSFT) || ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out())) {
        if (record->event.pressed) shifted[idx] = true;
    }

    if (!shifted[idx]) {
        kc = idx + KC_1;
    } else {
        switch (id) {
            case A_8:
            case A_9:
                shifted[idx] = false;
                return;

            case A_7:
                kc = KC_2;
                break;
            case A_5:
                kc = KC_8;
                break;
            case A_3:
                kc = KC_4;
                break;
            case A_1:
                kc = KC_6;
                break;

            case A_0:
                kc = KC_5;
                break;
            case A_2:
                kc = KC_1;
                break;
            case A_4:
                kc = KC_3;
                break;
            case A_6:
                kc = KC_7;
                break;
        }
    }

    if (record->event.pressed) {
        register_code(kc);
    } else {
        unregister_code(kc);
        shifted[idx] = false;
    }
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_led_all_on();
    for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
        ergodox_led_all_set(i);
        wait_ms(5);
    }
    wait_ms(1000);
    for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
        ergodox_led_all_set(i);
        wait_ms(10);
    }
    ergodox_led_all_off();

    if (!eeconfig_is_enabled()) eeconfig_init();
};

typedef struct {
    bool layer_toggle;
    bool sticky;
} dance_pa_state_t;

static dance_pa_state_t pa_state = {.layer_toggle = false, .sticky = false};

static void dance_play_arrow_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (pa_state.sticky) {
        pa_state.sticky       = false;
        pa_state.layer_toggle = false;
        layer_off(ARRW);
        return;
    }

    if (state->count == 1 && !state->pressed) {
        register_code(KC_MPLY);
        pa_state.sticky       = false;
        pa_state.layer_toggle = false;
    } else {
        pa_state.layer_toggle = true;
        layer_on(ARRW);
        pa_state.sticky = (state->count == 2);
    }
}

static void dance_play_arrow_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (!pa_state.layer_toggle) unregister_code(KC_MPLY);
    if (!pa_state.sticky) layer_off(ARRW);
}

static void dance_stop_reset_each(qk_tap_dance_state_t *state, void *user_data) {
    skip_leds = true;

    switch (state->count) {
        case 1:
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            break;
        case 4:
            ergodox_right_led_3_off();
            wait_ms(50);
            ergodox_right_led_2_off();
            wait_ms(50);
            ergodox_right_led_1_off();
            break;
    }
}

static void dance_stop_reset_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_MSTP);
    }
    if (state->count >= 4) {
        wait_ms(1000);
        reset_keyboard();
        reset_tap_dance(state);
    }
}

static void dance_stop_reset_reset(qk_tap_dance_state_t *state, void *user_data) {
    ergodox_right_led_1_off();
    wait_ms(50);
    ergodox_right_led_2_off();
    wait_ms(50);
    ergodox_right_led_3_off();
    wait_ms(1000);
    skip_leds = false;

    if (state->count == 1) {
        unregister_code(KC_MSTP);
    }
}

static void dance_brackets_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->keycode == TD(CT_LBP))
            register_code16(KC_LBRC);
        else
            register_code16(KC_RBRC);
    } else if (state->count == 2) {
        if (state->keycode == TD(CT_LBP))
            register_code16(KC_LPRN);
        else
            register_code16(KC_RPRN);
    }
}

static void dance_brackets_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->keycode == TD(CT_LBP))
            unregister_code16(KC_LBRC);
        else
            unregister_code16(KC_RBRC);
    } else if (state->count == 2) {
        if (state->keycode == TD(CT_LBP))
            unregister_code16(KC_LPRN);
        else
            unregister_code16(KC_RPRN);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
   [DI_CLN] = ACTION_TAP_DANCE_DOUBLE (KC_COLN, KC_SCLN)
  ,[CT_PA]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_play_arrow_finished, dance_play_arrow_reset)
  ,[CT_LBP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_brackets_finished, dance_brackets_reset)
  ,[CT_RBP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_brackets_finished, dance_brackets_reset)
  ,[CT_SR]  = ACTION_TAP_DANCE_FN_ADVANCED (dance_stop_reset_each, dance_stop_reset_finished, dance_stop_reset_reset)
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    // bool is_arrow = false;

    if (!skip_leds) {
        if (layer == GAME) {
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            if (is_swapped) {
                ergodox_right_led_1_on();
            }
        } else if (layer == ARRW) {
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
        } else if (layer == MEDIA) {
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
        }
    }

    if (!skip_leds) {
        if (get_mods() & MOD_BIT(KC_LSFT) || ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out())) {
            ergodox_right_led_1_set(LED_BRIGHTNESS_HI);
            ergodox_right_led_1_on();
        } else {
            ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
            if (layer != ARRW && layer != MEDIA && is_swapped == false) ergodox_right_led_1_off();
        }

        if (get_mods() & MOD_BIT(KC_LALT) || ((get_oneshot_mods() & MOD_BIT(KC_LALT)) && !has_oneshot_mods_timed_out())) {
            ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
            ergodox_right_led_2_on();
        } else {
            ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
            if (layer != GAME && layer != MEDIA) ergodox_right_led_2_off();
        }

        if (get_mods() & MOD_BIT(KC_LCTRL) || ((get_oneshot_mods() & MOD_BIT(KC_LCTRL)) && !has_oneshot_mods_timed_out())) {
            ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
            ergodox_right_led_3_on();
        } else {
            ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
            if (layer != GAME && layer != ARRW) ergodox_right_led_3_off();
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC:
            if (record->event.pressed) {
                if ((get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
                    clear_oneshot_mods();
                }
            }
            break;

        case A_MPN:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT) || ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out())) {
                    int oneshot = ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out());

                    if (oneshot) clear_oneshot_mods();
                    unregister_code(KC_LSFT);

                    tap_code(KC_MPRV);

                    if (!oneshot) register_code(KC_LSFT);
                } else {
                    tap_code(KC_MNXT);
                }
            }
            return false;

        // number row and symbols
        case A_1 ... A_0:
            ang_handle_num_row(keycode, record);
            return false;

        case SH_TG:
            if (record->event.pressed) {
                is_swapped = !is_swapped;
            }
            break;

        case SH_MON:
            is_swapped = !is_swapped;
            break;
    }

    return true;
}
