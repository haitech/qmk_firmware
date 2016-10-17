#include "gh60.h"
#include "action_layer.h"

enum keyboard_layers_macros {
  LAYER_QWERTY,
  LAYER_ARROW,
  LAYER_SYS,
  // Macros
  MACRO_N
};
#define SPC_FN LT(LAYER_ARROW, KC_SPC)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
  [LAYER_QWERTY] = {
    { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC },
    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS },
    { KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT  },
    { KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT },
    { M(LAYER_ARROW),   KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, SPC_FN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI, KC_RALT, KC_APP, M(LAYER_SYS) }
  },
    /* 1: fn0 */
	[LAYER_ARROW] = {
    { KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL   },
    { _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, },
    { _______, _______, _______, _______, _______, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, XXXXXXX, _______, },
    { _______, XXXXXXX, _______, _______, _______, _______, _______, M(MACRO_N)   , _______, _______, _______, _______, XXXXXXX, KC_RSFT, },
    { _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______  }
  },
    /* 2: fn1 */
	[LAYER_SYS] = {
    { KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET    },
    { _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_D, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, },
    { _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, XXXXXXX, _______, },
    { _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_RSFT, },
    { _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______  }
  },
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case LAYER_ARROW:
      if (record->event.pressed) {
        layer_on(LAYER_ARROW);
      } else {
        layer_off(LAYER_ARROW);
      }
      break;
    case LAYER_SYS:
      if (record->event.pressed) {
        layer_on(LAYER_SYS);
      } else {
        layer_off(LAYER_SYS);
      }
      break;
    case MACRO_N:
      return MACRODOWN( DOWN(KC_LGUI), TYPE(KC_GRV), END ); // Assumes Norwegien layout
      //return MACRODOWN( DOWN(KC_LGUI), DOWN(KC_LSFT), TYPE(KC_DOT), END ); // US ansi layout
      break;
  }
  return MACRO_NONE;
};
