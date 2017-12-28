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
 * | Esc    |  1!  |  2"  |  3#  |  4$  |  5%  | LEFT |           | RIGHT|  6&  |  7'  |  8(  |  9)  |  0   |   BS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   -=   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |   :*   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /?  |   _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | LAlt | LGui |                                       | KP1  |  \|  |      |      |      |
 *   |      |      |      |      |      |                                       | /L1  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BS   |  L2  |       |  L1  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | PgUp |        |      |
 *                                 | Space| Esc  |------|       |------|  Meh   |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_NO,
        KC_LCTL,      KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_NO,
        KC_NO,KC_NO,     KC_NO,  KC_LALT,KC_LGUI,
                                              KC_BSPACE,  TG(MDIA),
                                                              KC_DEL,
                                              KC_SPC,KC_ESC,KC_END,
        // right hand
             KC_RGHT, KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPACE,
             KC_NO,    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_MINS,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          JA_CLON,
             KC_NO,KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_RO,
                                  LT(SYMB,KC_P1),JA_ENVL,KC_NO,KC_NO,        KC_NO,
             TG(SYMB), CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_MEH, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
    --------------------------------------------------             --------------------------------------------------
   |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   |-------- ------ ------ ------ ------ -------------|           |------ ------ ------ ------ ------ ------ --------|
   |        |      |      |  UP  |      |      |      |           |      |      |   {  |  }   |  @   |  `   |        |
   |-------- ------ ------ ------ ------ ------|      |           |      |------ ------ ------ ------ ------ --------|
   |        |      | LEFT | DOWN | RIGHT|      |------|           |------|  BS  |   [  |  ]   |  \   |  |   |        |
   |-------- ------ ------ ------ ------ ------|      |           |      |------ ------ ------ ------ ------ --------|
   |        |      |      |      |      |      |      |           |      |      |      |      |  ^   |  ~   |        |
    -------- ------ ------ ------ ------ -------------             ------------- ------ ------ ------ ------ --------
     |      |      |      |      |      |                                       |      |      |      |      |      |
     |      |      |      |      |      |                                       |      |      |      |      |      |
      ----------------------------------                                         ----------------------------------
                                           -------------         -------------
                                          |      |      |       |      |        |
                                    ------|------|------|       |------ -------- ------
                                   |      |      |      |       |      |        |      |
                                   |      |      |------|       |------|        |      |
                                   |      |      |      |       |      |        |      |
                                    --------------------         ----------------------
 */
// SYMB
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, LSFT(JA_LBRC), LSFT(JA_RBRC),  JA_AT  , LSFT(JA_AT), KC_TRNS,
                KC_BSPC, JA_LBRC,       JA_RBRC,        JA_ENVL, LSFT(JA_ENVL), KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,        JA_HAT , LSFT(JA_HAT), KC_TRNS,
                         KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
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
