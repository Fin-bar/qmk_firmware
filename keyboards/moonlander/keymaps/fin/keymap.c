#include QMK_KEYBOARD_H
#define MOON_LED_LEVEL LED_LEVEL
// Make LED code prettier
#define on true
#define off false

enum custom_keycodes {
    HOLD_BOOT = SAFE_RANGE,
};

enum {
    BASE = 0,
    NUM,
    SYM,
    FUN,
    NAV,
    MOUSE,
    MEDIA,
    GAME,
    KEYBOARD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TG(GAME),
        KC_TRNS,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_TRNS,                                        KC_TRNS,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_TRNS,
        KC_TRNS,        MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_O),MT(MOD_LCTL, KC_E),MT(MOD_LSFT, KC_U),KC_I,KC_TRNS,                                       KC_TRNS,        KC_D,           MT(MOD_RSFT, KC_H),MT(MOD_LCTL, KC_T),MT(MOD_LALT, KC_N),MT(MOD_LGUI, KC_S),KC_TRNS,
        KC_TRNS,        KC_SLASH,       KC_Q,           KC_J,           KC_K,           KC_X,                                                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        LT(MEDIA,KC_ESCAPE),             KC_MEDIA_PLAY_PAUSE,                           TG(KEYBOARD),                   LT(FUN,KC_DELETE),KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        LT(NAV,KC_BSPC),LT(MOUSE,KC_TAB),KC_TRNS,                                       KC_TRNS,        LT(SYM,KC_ENTER), LT(NUM,KC_SPACE)
    ),
    [NUM] = LAYOUT_moonlander(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,
        KC_TRNS,        KC_LBRC,        KC_7,           KC_8,           KC_9,           KC_RBRC,        KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          KC_TRNS,
        KC_TRNS,        KC_SCLN,        KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_TRNS,
        KC_TRNS,        KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BSLS,                                                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MINUS,                       KC_NO,                                          KC_NO,                          KC_NO,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_0,           KC_DOT,         KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_TRANSPARENT
    ),
    [SYM] = LAYOUT_moonlander(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,
        KC_TRNS,        KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          KC_TRNS,
        KC_TRNS,        KC_COLN,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_PLUS,        KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_TRNS,
        KC_TRNS,        KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_PIPE,                                                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_UNDS,                        KC_NO,                                          KC_NO,                          KC_NO,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_LPRN,        KC_RPRN,        KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_NO
    ),
    [FUN] = LAYOUT_moonlander(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,
        KC_TRNS,        KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PSCR,        KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          KC_TRNS,
        KC_TRNS,        KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_LSCR,        KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_TRNS,
        KC_TRNS,        KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PAUSE,                                                                       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_APPLICATION,                 KC_NO,                                          KC_NO,                          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_SPACE,       KC_TAB,         KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_NO
    ),
    [NAV] = LAYOUT_moonlander(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,
        KC_TRNS,        RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,                                        KC_TRNS,        LCTL(KC_Y),     LCTL(KC_V),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_Z),     KC_TRNS,
        KC_TRNS,        KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        KC_NO,          KC_TRNS,                                        KC_TRNS,        CW_TOGG,        KC_PGUP,        KC_UP,          KC_PGDN,        KC_HOME,        KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_INSERT,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,                          KC_NO,                                          KC_NO,                          KC_DELETE,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_NO,          KC_TRNS,                                        KC_TRNS,        KC_ENTER,       KC_BSPC
    ),
    [MOUSE] = LAYOUT_moonlander(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,
        KC_TRNS,        RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,                                        KC_TRNS,        KC_NO,          LSFT(KC_INSERT),LCTL(KC_INSERT),LSFT(KC_DELETE),KC_UNDO,        KC_TRNS,
        KC_TRNS,        KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        KC_NO,          KC_TRNS,                                        KC_TRNS,        KC_NO,         KC_WH_L,        KC_MS_U,         KC_WH_R,        KC_WH_U,        KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_MS_L,        KC_MS_D,        KC_MS_R,       KC_WH_D,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,                          KC_NO,                                          KC_NO,                          KC_MS_BTN3,     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_NO,          KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_MS_BTN2,     KC_MS_BTN1
    ),
    [MEDIA] = LAYOUT_moonlander(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,
        KC_TRNS,        RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,                                        KC_TRNS,        RGB_MOD,        RGB_SPI,        RGB_HUI,        RGB_SAI,        RGB_VAI,        KC_TRNS,
        KC_TRNS,        KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        KC_NO,          KC_TRNS,                                        KC_TRNS,        RGB_M_P,        KC_MPRV,        KC_VOLD,        KC_VOLU,        KC_MNXT,        KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          RGB_TOG,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_NO,                                          KC_NO,                          KC_AUDIO_MUTE,  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_NO,          KC_NO,          KC_TRNS,                                        KC_TRNS,        KC_MSTP,      KC_MPLY
    ),
    [GAME] = LAYOUT_moonlander(
        KC_ESCAPE,      KC_9,           KC_7,           KC_5,           KC_3,           KC_1,           KC_F11,                                         KC_F7,          KC_0,           KC_2,           KC_4,           KC_6,           KC_8,           KC_TRNS,
        KC_GRAVE,       KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_F1,                                          KC_F4,          KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_BSLS,
        KC_TAB,         KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_SCLN,                                        KC_MINUS,       KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_EQUAL,
        KC_LSFT,        KC_SLASH,       KC_Q,           KC_J,           KC_K,           KC_X,                                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_LSFT,
        KC_MPLY,        KC_LBRC,        KC_RBRC,        KC_LALT,        KC_LCTL,                        KC_ENTER,                                       KC_ENTER,                       KC_LCTL,        KC_LALT,        KC_F3,          KC_F2,          KC_F1,
        KC_BSPC,        SH_MON,         KC_TRNS,                        KC_TRNS,        KC_NO,          KC_SPACE
    ),
    [KEYBOARD] = LAYOUT_moonlander(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,                                        KC_TRNS,        KC_NO,          DT_DOWN,        DT_PRNT,        DT_UP,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          HOLD_BOOT,      KC_NO,          KC_NO,          KC_TRNS,                                        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,                          QK_RBT,                                         KC_TRNS,                        KC_NO,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_NO,          KC_NO,          KC_TRNS,                                        KC_TRNS,        MU_TOGG,        MU_NEXT
    ),
};

// Some HRM QOL improvements courtesy of https://github.com/filterpaper/qmk_userspace

static uint16_t    next_keycode;
static keyrecord_t next_record;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Cache current input for on-going mod-tap decisions
        next_keycode = keycode;
        next_record  = *record;
    }
    return true;
}

#define IS_HOMEROW(r) (r->event.key.row == 2 || r->event.key.row == 8)

// Mod-tap and the following key are on opposite sides of the keyboard
#define IS_BILATERAL_TAP(r, n) ( \
(r->event.key.row <= 5 && 6 <= n.event.key.row) || \
(r->event.key.row >= 6 && 5 >= n.event.key.row))

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Hold modifier with a nested bilateral tap on the opposite hand
    return IS_BILATERAL_TAP(record, next_record);
}
#endif

/* Just use !IS_BILATERAL_TAP
// Mod-tap and the following key are on the same side of the keyboard
// #define IS_UNILATERAL_TAP(r, n) ( r->event.key.col != n.event.key.col &&    (  \
// (r->event.key.row == 1 && 0 <= n.event.key.row && n.event.key.row <= 2) || \
// (r->event.key.row == 5 && 4 <= n.event.key.row && n.event.key.row <= 6) ))
*/

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}


bool rgb_matrix_indicators_user(void) {
    return true;
}

// Runs constantly in the background; keep this lightweight
void matrix_scan_user(void) {
    // Swap_hands LED indicator
    if (IS_LAYER_ON(GAME)) {
        if (is_swap_hands_on())
            ML_LED_3(on);
        else
            ML_LED_3(off);
    }
}

// Also runs constantly in the background, but after everything else. Keep this lightweight too.
void housekeeping_task_user(void) {
    if (!is_transport_connected()) {
        layer_on(GAME);
    }
}

// Runs on layer switch
layer_state_t layer_state_set_user(layer_state_t state) {
    // Layer LED lighting
    ML_LED_1(off);
    ML_LED_2(off);
    ML_LED_3(off);
    ML_LED_4(off);
    ML_LED_5(off);
    ML_LED_6(off);
    switch (get_highest_layer(state)) {
        case 1:
            ML_LED_1(on);
            break;
        case 2:
            ML_LED_2(on);
            break;
        case 3:
            ML_LED_3(on);
            break;
        case 4:
            ML_LED_4(on);
            break;
        case 5:
            ML_LED_5(on);
            break;
        case 6:
            ML_LED_6(on);
            break;
        case 7:
            ML_LED_1(on);
            ML_LED_2(on);
            break;
        case 8:
            ML_LED_4(on);
            ML_LED_5(on);
            ML_LED_6(on);
            break;
            return state;
        default:
            break;
    };
    return state;
}

// Hold for bootloader macro
static deferred_token token;
static uint8_t counter = 0;
float goodbye[][2] = SONG(GOODBYE_SOUND);

uint32_t boot_callback(uint32_t trigger_time, void *cb_arg) {
    uint8_t *counter = (uint8_t *)cb_arg;
    *counter += 1;

    if (*counter <= 3) {
        audio_play_note(2637.02f, 64);
    } else {
        PLAY_SONG(goodbye);
        reset_keyboard();
    }

    return 1000; // 1 second till this gets called again
}

// Runs on keypress/release
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOLD_BOOT:
            if (record->event.pressed) {
                counter = 0;
                token   = defer_exec(10, boot_callback, &counter);
            } else {
                cancel_deferred_exec(token);
                audio_play_note(1318.51f, 64);
            }
        default:
            break; // do nothing!
    }
    return true;
}
