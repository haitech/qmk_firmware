#include "atomic.h"
#include "action_layer.h"
#include "led.h"

enum keyboard_layers_macros {
  QW, // qwerty
  ARR, // arrows
  SYS,
  T1,T2,T3,T4,T5,T6,
  // Macros
  M_N,
  M_BCKL,
};

// hold space for Fn
#define SPC_FN LT(ARR, KC_SPC)
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QW] = { /* QWERTY */
   { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, XXXXXXX  },
   { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL   },
   { KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP  },
   { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN  },
   //{ M(ARR),  KC_LALT, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX, SPC_FN, XXXXXXX,  XXXXXXX, XXXXXXX, KC_RGUI, M(SYS),  KC_LEFT, KC_DOWN, KC_RGHT  },
   { M(T1),   M(T2),   M(T3),   M(T4),   M(T5), M(T6), SPC_FN, XXXXXXX,  XXXXXXX, XXXXXXX, KC_RGUI, M(SYS),  KC_LEFT, KC_DOWN, KC_RGHT  },
  },
  
  [ARR] = { /* LAYER_ARROW */
   { KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, XXXXXXX  },
   { _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_D, _______, _______, _______, KC_UP,   _______, _______, _______, _______, KC_BSLS, KC_DEL   },
   { KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,  KC_ENT,  KC_PGUP  },
   { KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
   { _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT },
  },
  
  [SYS] = { /* LAYER_SYS */
   { M(M_BCKL),_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   XXXXXXX  },
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL   },
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
   { KC_LSFT, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
   { _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT },
  },
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{  
  switch(id) {
    case T1:
      uprintf("T1\n");
      break;
    case T2:
      uprintf("T2\n");
      break;
    case T3:
      uprintf("T3\n");
      break;
    case T4:
      uprintf("T4\n");
      break;
    case T5:
      uprintf("T5\n");
      break;
    case T6:
      uprintf("T6\n");
      break;
    case ARR:
      uprintf("ARR\n");
      if (record->event.pressed) {
        breathing_speed_set(2);
        breathing_pulse();
        layer_on(ARR);
      } else {
        layer_off(ARR);
      }
      break;
    case SYS:
      uprintf("SYS\n");
      if (record->event.pressed) {
        breathing_speed_set(1);
        breathing_pulse();
        layer_on(SYS);
      } else {
        layer_off(SYS);
      }
      break;
    case M_N:
      return MACRODOWN( DOWN(KC_LGUI), TYPE(KC_GRV), END ); // Assumes Norwegien layout
      //return MACRODOWN( DOWN(KC_LGUI), DOWN(KC_LSFT), TYPE(KC_DOT), END ); // US ansi layout
      break;
#ifdef BACKLIGHT_ENABLE
      case M_BCKL:
          if (record->event.pressed) {
              backlight_step();
          }
          break;
#endif
  }
  return MACRO_NONE;
};
