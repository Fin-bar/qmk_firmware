/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR

#define TAPPING_FORCE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_16BIT

#define RGB_MATRIX_STARTUP_SPD 60
#define RGB_MATRIX_TIMOUT 300000

#define BOTH_SHIFTS_TURN_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 2000

#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_TERM 500

#define MOONLANDER_USER_LEDS

