#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define HUN 1 // default layer
#define SYMB 2 // symbols
#define MDIA 3 // media keys
#define NUM 4 // numbersl	 keys
#include "ergodox.h"

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
 * |   ESC  |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |           |   F7 |   F8 |   F9 |  F10 |      |   -  |   =    
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   HUN  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   SYM  |A/LGUI|S/LALT|D/LCTL|F/LSFT|   G  |------|           |------|   H  |J/RSFT|K/RCTL|L/RALT|;/RGUI|   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  MEDIA |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LANG |      |      |  FN2 |  FN1 |                                       |  FN1 |  FN2 |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | HOME | END  |       |  Left | Right |
 *                                 ,------|------|------|       |-------+-------+------.
 *                                 |      |      | PgUp |       |   Up  |       |      |
 *                                 | Space|Backsp|------|       |-------|  Tab  |Enter |
 *                                 |      |ace   | PgDn |       |  Down |       |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_F1,        KC_F2,          KC_F3,          KC_F4,            KC_F5,  KC_F6,
        TG(HUN),        KC_Q,         KC_W,           KC_E,           KC_R,             KC_T,   KC_TRNS,
        TG(SYMB),       LGUI_T(KC_A), LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,
        TG(MDIA),       KC_Z,         KC_X,           KC_C,           KC_V,             KC_B,   KC_TRNS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_FN2,         KC_FN1,
                                                  KC_HOME, KC_END,
                                                           KC_PGUP,
                                          KC_SPC, KC_BSPC, KC_PGDN,
        // right hand
        KC_F7,    KC_F8,           KC_F9,           KC_F10,        KC_TRNS,          KC_MINS,          KC_EQL,
        KC_TRNS,  KC_Y,            KC_U,            KC_I,          KC_O,             KC_P,             KC_BSLS,
                  KC_H,            RSFT_T(KC_J),   RCTL_T(KC_K),  RALT_T(KC_L),     RGUI_T(KC_SCLN),  KC_QUOT,
        KC_TRNS,  KC_N,            KC_M,            KC_COMM,       KC_DOT,           KC_SLSH,          KC_TRNS,
                                   KC_FN1,          KC_FN2,        KC_TRNS,          KC_TRNS,          KC_TRNS,
             KC_LEFT, KC_RIGHT,
             KC_UP,
             KC_DOWN, KC_TAB, KC_ENT
    ),
/* Keymap 1: Hun layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |           |   F7 |   F8 |   F9 |  F10 |   Ö  |   Ü  |   Ó    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Z  |   U  |   I  |   O  |   P  |   Ő    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   SYM  |A/LGUI|S/LALT|D/LCTL|F/LSFT|   G  |------|           |------|   H  |J/RSFT|K/RCTL|L/RALT|É/RGUI|   Á    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  MEDIA |  Y   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -  |   Ú    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  Í   | AltGr|  FN2 | FN1  |                                       |  FN1 |  FN2 | AltGr|      |   Ű  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | HOME | END  |       |  Left | Right |
 *                                 ,------|------|------|       |-------+-------+------.
 *                                 |      |      | PgUp |       |   Up  |       |      |
 *                                 | Space|Backsp|------|       |-------|  Tab  |Enter |
 *                                 |      |ace   | PgDn |       |  Down |       |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[HUN] = KEYMAP( 
        KC_ESC,         KC_F1,           KC_F2,          KC_F3,          KC_F4,            KC_F5,  KC_F6,
        KC_TRNS,        KC_Q,            KC_W,           KC_E,           KC_R,             KC_T,   KC_TRNS,
        TG(SYMB),       LGUI_T(KC_A),    LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,
        TG(MDIA),       KC_Z,            KC_X,           KC_C,           KC_V,             KC_B,   KC_TRNS,
        KC_TRNS,        KC_NONUS_BSLASH, KC_RALT,        KC_FN2,         KC_FN1,
                                                  KC_HOME, KC_END,
                                                           KC_PGUP,
                                          KC_SPC, KC_BSPC, KC_PGDN,
        // right hand
             KC_F7,    KC_F8,   KC_F9,           KC_F10,        KC_0,         KC_MINS,          KC_EQL,
             KC_TRNS,  KC_Y,    KC_U,            KC_I,          KC_O,         KC_P,             KC_LBRC,
                       KC_H,    RSFT_T(KC_J),  RCTL_T(KC_K),  RALT_T(KC_L), RGUI_T(KC_SCLN),  KC_QUOT,
             KC_TRNS,  KC_N,    KC_M,            KC_COMM,       KC_DOT,       KC_SLSH,          KC_RBRC,
                                KC_FN1,          KC_FN2,        KC_RALT,      KC_TRNS,          KC_BSLS,
             KC_LEFT, KC_RIGHT,
             KC_UP,
             KC_DOWN, KC_TAB, KC_ENT
    ),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |      |      |  NUM |   /  |   *  |   -  |           |      |      |   <  |   >  |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |   7  |   8  |   9  |   +  |           |      |      |   [  |   ]  |   ;  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |   4  |   5  |   6  |------|           |------|      |   (  |   )  |   ,  |      |        |
 * |---------+------+------+------+------+------| Enter|           |      |------+------+------+------+------+--------|
 * |         |      |      |   1  |   2  |   3  |      |           |      |      |   {  |   }  |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |   .  |   0  |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | HOME | END  |       |  Left | Right |
 *                                 ,------|------|------|       |-------+-------+------.
 *                                 |      |      | PgUp |       |   Up  |       |      |
 *                                 | Space|Backsp|------|       |-------|  Tab  |Enter |
 *                                 |      |ace   | PgDn |       |  Down |       |      |
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       VRSN,    KC_TRNS, KC_TRNS, KC_NUMLOCK, KC_SLASH,    KC_ASTR,     KC_MINS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_7,    KC_KP_8,     KC_KP_9,     KC_KP_PLUS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_4,    KC_KP_5,     KC_KP_6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_1,    KC_KP_2,     KC_KP_3,     KC_KP_ENTER,
          EPRM, KC_TRNS, KC_TRNS, KC_KP_DOT,  KC_KP_0,
                                                  KC_HOME, KC_END,
                                                           KC_PGUP,
                                          KC_SPC, KC_BSPC, KC_PGDN,
       // right hand
       KC_TRNS, KC_TRNS,   KC_LABK,    KC_RABK,      KC_TRNS,      KC_TRNS,       KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_LBRC,    KC_RBRC,      KC_TRNS,      KC_TRNS,       KC_TRNS,
                KC_TRNS,   KC_LPRN,    KC_RPRN,      KC_TRNS,      KC_TRNS,       KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_LCBR,    KC_RCBR,      KC_TRNS,      KC_TRNS,       KC_TRNS,
                           KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,
             KC_LEFT, KC_RIGHT,
             KC_UP,
             KC_DOWN, KC_TAB, KC_ENT
    ),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  Mute  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  Up  |      |      |      |           |      |      |      |  MsUp|      |      |  VolUp |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Rght |      |------|           |------|      |MsLeft|MsDown|MsRght|      |  VolDn |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Lclk | Mclk | Rclk |      |      |           |      |      |      | Prev | Next |      |  Play  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Left | Right| Upwh |       | BRefr|Brwser|Brwser|
 *                                 | Wheel| Wheel|------|       |------|Back  |Fwd   |
 *                                 |      |      | Dnwh |       | BHome|      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                           KC_TRNS, KC_TRNS,
                                                    KC_WH_U,
                                  KC_WH_L, KC_WH_R, KC_WH_D,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_VOLU,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_MPLY,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_VOLD,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_WREF,
       KC_WHOM, KC_WBAK, KC_WFWD
    ),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | HOME | END  |       |  Left | Right |
 *                                 ,------|------|------|       |-------+-------+------.
 *                                 |      |      | PgUp |       |   Up  |       |      |
 *                                 | Space|Backsp|------|       |-------|  Tab  |Enter |
 *                                 |      |ace   | PgDn |       |  Down |       |      |
 *                                 `--------------------'       `----------------------'
 */
// MEDIA AND MOUSE

[NUM] = KEYMAP(
       KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS,
       KC_TRNS, LGUI_T(KC_1), LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4),  KC_5,
       KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, 
                                                  KC_HOME, KC_END,
                                                           KC_PGUP,
                                          KC_SPC, KC_BSPC, KC_PGDN,
    // right hand
       KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS,
                KC_6,     RSFT_T(KC_7), RCTL_T(KC_8), RALT_T(KC_9),  RGUI_T(KC_0), KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS, 
             KC_LEFT, KC_RIGHT,
             KC_UP,
             KC_DOWN, KC_TAB, KC_ENT
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NUM),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA)                // FN1 - Momentary Layer 1 (Symbols)
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
        case 4	:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
