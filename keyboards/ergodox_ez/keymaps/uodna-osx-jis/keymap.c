#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

// JIS Keycodes
#define JA_CLON KC_QUOT  // : and *
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }

// Shifted JIS Keycodes
#define JA_ASTR KC_DQUO  // *
#define JA_BQUO KC_LCBR  // `
#define JA_TILD KC_PLUS  // ~
#define JA_LCBR KC_RCBR  // {
#define JA_RCBR KC_PIPE  // }

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  1!  |  2"  |  3#  |  4$  |  5%  |      |           |      |  6&  |  7'  |  8(  |  9)  |  0   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   -=   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |   :*   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /?  |   _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Esc  | LGui |                                       |  L1   |  \|  |      |      |      |
 *   |      |      |      | /Alt |      |                                       |       | /L2  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |  L2  |       |  L1  |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space|      |------|       |------|  KP1   |Enter |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_NO,    KC_1,   KC_2,   KC_3,           KC_4,     KC_5,  KC_NO,
        KC_TAB,   KC_Q,   KC_W,   KC_E,           KC_R,     KC_T,  KC_NO,
        KC_LCTL,  KC_A,   KC_S,   KC_D,           KC_F,     KC_G,
        KC_LSFT,  KC_Z,   KC_X,   KC_C,           KC_V,     KC_B,  KC_NO,
        KC_NO,    KC_NO,  KC_NO,  ALT_T(KC_ESC),  KC_LGUI,

                                                           KC_NO,  TG(MDIA),
                                                                   KC_NO,
                                                  KC_SPC,  KC_NO,  KC_NO,

        // right hand
        KC_NO,  KC_6,      KC_7,               KC_8,    KC_9,    KC_0,     KC_NO,
        KC_NO,  KC_Y,      KC_U,               KC_I,    KC_O,    KC_P,     KC_MINS,
                KC_H,      KC_J,               KC_K,    KC_L,    KC_SCLN,  JA_CLON,
        KC_NO,  KC_N,      KC_M,               KC_COMM, KC_DOT,  KC_SLSH,  KC_RO,
                MO(SYMB),  LT(MDIA, JA_ENVL),  KC_NO,   KC_NO,   KC_NO,

        TG(SYMB),  KC_NO,
        KC_NO,
        KC_NO,     KC_P1,  KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
    --------------------------------------------------             --------------------------------------------------
   |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   |-------- ------ ------ ------ ------ -------------|           |------ ------ ------ ------ ------ ------ --------|
   |        |      |      |  UP  |      |      |      |           |      |  `   |   {  |  }   |  @   |      |        |
   |-------- ------ ------ ------ ------ ------|      |           |      |------ ------ ------ ------ ------ --------|
   |        |      | LEFT | DOWN | RIGHT|      |------|           |------|  BS  |   [  |  ]   |  ~   |  ^   |        |
   |-------- ------ ------ ------ ------ ------|      |           |      |------ ------ ------ ------ ------ --------|
   |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    -------- ------ ------ ------ ------ -------------             ------------- ------ ------ ------ ------ --------
     |      |      |      |      |      |                                       |      |      |      |      |      |
     |      |      |      |      |      |                                       |      |      |      |      |      |
      ----------------------------------                                         ----------------------------------
                                           -------------         -------------
                                          |      |      |       |      |        |
                                    ------|------|------|       |------ -------- ------
                                   |      |      |      |       |      |        |      |
                                   | KP1  |      |------|       |------|        |      |
                                   |      |      |      |       |      |        |      |
                                    --------------------         ----------------------
 */
// SYMB
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP  ,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                         KC_TRNS,  KC_TRNS,
                                                                   KC_TRNS,
                                                 KC_P1,  KC_TRNS,  KC_TRNS,

       // right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  JA_BQUO,  JA_LCBR,  JA_RCBR,  JA_AT,    KC_TRNS,  KC_TRNS,
                 KC_BSPC,  JA_LBRC,  JA_RBRC,  JA_TILD,  JA_HAT,   KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  1   |  2   |  3   |  4   |  5   |      |           |      |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  $   |  %   |------|           |------|  ^   |  &   |  *   |  (   |  )   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Reset|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_TRNS,
    KC_TRNS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,

    // right hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
              KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
