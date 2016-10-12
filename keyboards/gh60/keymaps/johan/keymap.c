#include "gh60.h"
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
      ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,  EQL, BSPC, \
      TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,  RBRC,BSLS, \
      LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,  NO,  ENT,  \
      LSFT,NO, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,      NO,   RSFT, \
      FN0,LALT,LGUI,          SPC,                   NO,  RGUI, RALT,APP,   FN1),
    /* 1: fn0 */
	KEYMAP(
    GRV,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,UP,TRNS,TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BSPC,LEFT,DOWN,RGHT,TRNS,TRNS, NO,    TRNS, \
    TRNS,NO,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    NO,      RSFT,   \
    TRNS,TRNS,TRNS,          TRNS,                    NO,TRNS,TRNS,TRNS,TRNS),

    /* 2: fn1 */
	KEYMAP(
    GRV,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,UP,TRNS,TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BSPC,LEFT,DOWN,RGHT,TRNS,TRNS, NO,    TRNS, \
    TRNS,NO,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    NO,      RSFT,   \
    TRNS,TRNS,TRNS,          TRNS,                    NO,TRNS,TRNS,TRNS,TRNS),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [1] = ACTION_LAYER_TOGGLE(2),     // toggle arrow overlay
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_scan_user(void) {

//Layer LED indicators
    uint32_t layer = layer_state;
	
    if (layer & (1<<1)) {
        gh60_wasd_leds_on();
        gh60_fn_led_on();
    } else {
        gh60_wasd_leds_off();
        gh60_fn_led_off();
    }
	
    if (layer & (1<<2)) {
        gh60_poker_leds_on();
        gh60_esc_led_on();
    } else {
        gh60_poker_leds_off();
        gh60_esc_led_off();
    }
	
};
