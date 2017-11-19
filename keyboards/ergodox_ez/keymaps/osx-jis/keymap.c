#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define JA_CLON KC_QUOT  // : and *
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }

#define M_ZR_AST M(2)
#define M_CLN_UN M(3)

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
 * | Esc    |  1!  |  2"  |  3#  |  4$  |  5%  | LEFT |           | RIGHT|  6&  |  7'  |  8(  |  9)  |  0*  |   BS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L2  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   -=   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |[{/LCtrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |]}/RCtrl|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /?  |   :_   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Esc  | LGui |                                       | RCtrl|  \|  |      |      |      |
 *   |      |      |      |/LAlt |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BS   | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | PgUp |        |      |
 *                                 | Space|  ^~  |------|       |------|   @`   |Enter |
 *                                 |      | /L1  | End  |       | PgDn |  /L1   |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(MDIA),
        LCTL_T(JA_LBRC),      KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_NO,
        KC_NO,KC_NO,     KC_NO,  LALT_T(KC_ESC),KC_LGUI,
                                              KC_BSPACE,  KC_LGUI,
                                                              KC_DEL,
                                              KC_SPC,LT(SYMB,JA_HAT),KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   M_ZR_AST,             KC_BSPACE,
             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_MINS,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          RCTL_T(JA_RBRC),
             KC_NO,KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          M_CLN_UN,
                                  KC_RCTL,JA_ENVL,KC_NO,KC_NO,        KC_NO,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,LT(SYMB,JA_AT), KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |  1!  |  2"  |  3#  |  4$  |  5%  | LEFT |           | RIGHT|  6&  |  7'  |  8(  |  9)  |  0*  |   BS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L2  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   -=   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |LCtrl [ |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |   ]}   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /?  |   :_   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Alt  | LGui |                                       | RGui |  \|  |      |      |      |
 *   |      |      |      | Esc  | Eisu |                                       | Kana |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BS   | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | PgUp |        |      |
 *                                 | Space|  ^~  |------|       |------|   @`   |Enter |
 *                                 |      | /L1  | End  |       | PgDn |  /L1   |      |
 *                                 `--------------------'       `----------------------'
 */
// SYMB
[SYMB] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(MDIA),
        KC_LCTL,      KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_NO,
        KC_NO,KC_NO,     KC_NO,  KC_LALT,KC_LGUI,
                                              KC_BSPACE,  KC_LGUI,
                                                              KC_DEL,
                                              KC_SPC,LT(SYMB,JA_HAT),KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   M_ZR_AST,             KC_BSPACE,
             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_MINS,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          JA_RBRC,
             KC_NO,KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          M_CLN_UN,
                                  KC_RGUI,JA_ENVL,KC_NO,KC_NO,        KC_NO,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,LT(SYMB,JA_AT), KC_ENT
    ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Reset|      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RESET,   KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
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
    case 2:
      if(record->event.pressed){
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)){
          /* unregister_code(KC_LSFT); */
          /* register_code(JA_CLON);      //On German layout # */
          /* unregister_code(JA_CLON);      //On German layout # */
          /* register_code(KC_LSFT);     //to keep shift pressed if held */
          return MACRO(D(LSFT), T(QUOT), U(LSFT), END);
        }
        else{
          /* register_code(KC_0); */
          /* unregister_code(KC_0); */
          return MACRO(T(0), END);
        }
      }
      break;
    case 3:
      if(record->event.pressed){
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)){
          /* unregister_code(KC_LSFT); */
          /* register_code(JA_CLON);      //On German layout # */
          /* unregister_code(JA_CLON);      //On German layout # */
          /* register_code(KC_LSFT);     //to keep shift pressed if held */
          return MACRO(T(RO), END);
        }
        else{
          /* register_code(KC_0); */
          /* unregister_code(KC_0); */
          return MACRO(T(QUOT), END);
        }
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

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
