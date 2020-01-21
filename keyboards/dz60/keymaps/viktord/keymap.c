#include QMK_KEYBOARD_H



#define _QWERTY 0
#define _ALT 1
#define _FUNC 2
#define _PROG 3
#define _NUM 4
#define ______ KC_TRNS


enum my_keycodes {
	  RPAIR = SAFE_RANGE,
	  EPAIR,
	  PERCPAIR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps/FN |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | DEL |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt(1)  |              Space                | RAlt  | MO(2) |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

  [_QWERTY] = LAYOUT_directional(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      LT(_PROG,KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI, LM(1,MOD_LALT), KC_SPC, KC_SPC, KC_SPC, KC_RALT, MO(2), KC_LEFT, KC_DOWN, KC_RIGHT
      ),
  /* Alted
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |     |     |     |     |     |     |     |     |     |     |     |     |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |    |       |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

  [_ALT] = LAYOUT_directional(
      KC_GRV, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______,______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______,______, ______, ______, ______
      ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   RESET   |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|Scrsh|PrtSc|      | WhUP |      |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL+ | BL- |     |     |     |     |     |     | WhDN|             |
   * |-----------------------------------------------------------------------------------------+
   * |           | Vol+| Vol-| Mute| Bri+| Bri-| NUM |     |     |     |M_BTN3|    | PUP | Ins |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |Home | PDN | End |
   * `-----------------------------------------------------------------------------------------'
   */

  [_FUNC] = LAYOUT_directional(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS, RESET,
     ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, LCTL(LSFT(KC_PSCREEN)), KC_PSCREEN , KC_SYSREQ, KC_MS_WH_UP, ______,
      ______, BL_TOGG, BL_STEP, BL_INC, BL_DEC, BL_BRTG, ______, ______, ______, ______, ______, KC_MS_WH_DOWN, ______,
      ______, KC_VOLD, KC_VOLU, KC_MUTE, KC_BRID, KC_BRIU , TG(_NUM), ______, ______, ______, KC_BTN3, ______, KC_PGUP, KC_INSERT,
      ______, ______, ______, ______, ______, ______, ______, ______, KC_HOME, KC_PGDOWN , KC_END
      ),
  /* Prog Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  () |  F9 | F10 | F11 | F12 |   RESET   |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|Scrsh|PrtSc|  []  | WhUP |      |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL+ | BL- |     |     |     |     |     |     | WhDN|             |
   * |-----------------------------------------------------------------------------------------+
   * |           | Vol+| Vol-| Mute| Bri+| Bri-|     |     |     |     |M_BTN3|    | PUP | Ins |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |Home | PDN | End |
   * `-----------------------------------------------------------------------------------------'
   */

  [_PROG] = LAYOUT_directional(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   PERCPAIR,   KC_F6,   KC_F7,  KC_F8, RPAIR, KC_F10, KC_F11, KC_F12, KC_TRNS, RESET,
     ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, LCTL(LSFT(KC_PSCREEN)), KC_PSCREEN , EPAIR, KC_MS_WH_UP, ______,
      ______, BL_TOGG, BL_STEP, BL_INC, BL_DEC, BL_BRTG, ______, ______, ______, ______, ______, KC_MS_WH_DOWN, ______,
      ______, KC_VOLD, KC_VOLU, KC_MUTE, KC_BRID, KC_BRIU , ______, ______, ______, ______, KC_BTN3, ______, KC_PGUP, KC_INSERT,
      ______, ______, ______, ______, ______, ______, ______, ______, KC_HOME, KC_PGDOWN , KC_END
      ),
  /* Numpad
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |     |     |     |     |     |     |     |  7  |  8  |  9  |     |     |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |     |  4  |  5  |  6  |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     |     |     |  1  |  2  |  3  |     |   ENTER     |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |  0  |  0  |  .  |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |    |  FN   |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

  [_NUM] = LAYOUT_directional(
      KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_KP_7, KC_KP_8, KC_KP_9, KC_NO, KC_NO, KC_NO, KC_NO, ______,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_KP_4, KC_KP_5, KC_KP_6, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_KP_1, KC_KP_2, KC_KP_3, KC_NO, KC_NO, ______,
      KC_NO,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, ______,  KC_KP_0, KC_KP_0, KC_KP_DOT,KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,______, KC_NO, KC_NO, KC_NO
      ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PERCPAIR:
      if (record->event.pressed) {
        // Do something when pressed
        SEND_STRING("{%%}" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case RPAIR:
      if (record->event.pressed) {
        // Do something when pressed
        SEND_STRING("()" SS_TAP(X_LEFT));
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case EPAIR:
      if (record->event.pressed) {
        // Do something when pressed
	if ( (keyboard_report->mods & MOD_BIT (KC_LSFT))) 
          SEND_STRING("{}" SS_TAP(X_LEFT));
	else 
          SEND_STRING("[]" SS_TAP(X_LEFT));
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
