#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY_MOD 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _NUM 4
#define _FKEYS 5
#define _TRI 15

enum custom_keycodes {
  QWERTY_MOD = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  NUM,
  FKEYS,
  TRI,
  QWERTY_OFF,
  QWERTY_ON,
};

// Left-hand home row mods
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)

// Base Layer Thumb Keys
#define ALT_ENT MT(MOD_LALT,KC_ENT)
#define SP_TRI LT(_TRI,KC_SPC)

#define ESC_SFT LSFT_T(KC_ESC)
#define BSP_SFT RSFT_T(KC_BSPC)
#define DEL_CTL RCTL_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY_MOD] = LAYOUT(
  KC_LGUI, KC_NO,   KC_LCTL, ESC_SFT,    KC_NO, QK_REP,  /**/ QK_REP, KC_NO,     BSP_SFT, DEL_CTL, KC_NO,   KC_NO,  
  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,  KC_NO,   /**/ KC_NO,  KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,   
  KC_A,    KC_S,    CTL_D,   SFT_F,      KC_G,  KC_NO,   /**/ KC_NO,  KC_H,      SFT_J,   CTL_K,   KC_L,    KC_SCLN,
  KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,  KC_NO,   /**/ KC_NO,  KC_N,      KC_M,    KC_NO,   KC_UP,   KC_NO,  
  KC_NO,   KC_NO,   KC_NO,   LOWER, MO(_FKEYS), ALT_ENT, /**/ KC_SPC, MO(_FKEYS),RAISE,   KC_LEFT, KC_DOWN, KC_RGHT
),

[_QWERTY] = LAYOUT(
  _______, _______, _______, QWERTY_OFF, _______, _______, /**/ _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______,    _______, _______, /**/ _______, _______, _______, _______, _______, _______, 
  _______, _______, KC_D,    KC_F,       _______, _______, /**/ _______, _______, KC_J,    KC_K,    _______, _______, 
  _______, _______, _______, _______,    _______, _______, /**/ _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______,    _______, _______, /**/ _______, KC_LSFT, _______, _______, _______, _______
),

[_NUM] = LAYOUT(
  _______, _______, _______, TG(_NUM), _______, _______, /**/ _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______,  _______, _______, /**/ _______, _______, KC_7,    KC_8,    KC_9,    _______, 
  _______, _______, _______, _______,  _______, _______, /**/ _______, _______, KC_4,    KC_5,    KC_6,    _______, 
  _______, _______, _______, _______,  _______, _______, /**/ _______, _______, KC_1,    KC_2,    KC_3,    _______, 
  _______, _______, _______, _______,  _______, _______, /**/ _______, _______, _______, KC_0,    _______, _______
),

[_FKEYS] = LAYOUT(
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, 
  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, /**/ _______, _______, KC_7,    KC_8,    KC_9,    _______, 
  KC_F8,   KC_F7,   KC_F6,   KC_F5,   _______, _______, /**/ _______, _______, KC_4,    KC_5,    KC_6,    _______, 
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, /**/ _______, _______, KC_1,    KC_2,    KC_3,    _______, 
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, KC_0,    _______, _______
),

// Left-hand home row mods
// #define CTL_COM LCTL_T(KC_COMM)
// #define SFT_DOT LSFT_T(KC_DOT)

// Right-hand home row mods
// #define CTL_QOT RCTL_T(KC_QUO T)

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
  KC_NO,   KC_NO,   _______,  _______,  _______, KC_NO,   /**/  KC_NO,   _______, _______,   _______, KC_NO,     KC_NO,
  KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,   KC_PERC, KC_NO,   /**/  KC_NO,   KC_CIRC, KC_AMPR,   KC_ASTR, KC_PIPE,   KC_NO,
  KC_BSLS, KC_SLSH, KC_COMM,  KC_DOT,   KC_MINS, KC_NO,   /**/  KC_NO,   KC_UNDS, S(KC_QUOT),KC_QUOT, S(KC_SLSH),KC_NO,
  KC_NO,   KC_NO,   S(KC_GRV),S(KC_EQL),KC_NO,   KC_NO,   /**/  KC_NO,   KC_NO,   KC_EQL,    KC_GRV,  KC_PGUP,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,    _______,  _______, _______, /**/  _______, _______, _______,   KC_HOME, KC_PGDN,   KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_NO, KC_NO,     _______,   _______,   _______,   KC_NO,   /**/  KC_NO,  _______, _______,   _______, KC_NO,   KC_NO,
  KC_NO, KC_NO,     S(KC_9),   S(KC_0),   KC_NO,     KC_NO,   /**/  KC_NO,  KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_NO,
  KC_NO, S(KC_COMM),S(KC_LBRC),S(KC_RBRC),S(KC_DOT), KC_NO,   /**/  KC_NO,  KC_BTN4, S(KC_TAB), KC_TAB,  KC_BTN5, KC_NO,
  KC_NO, KC_NO,     KC_LBRC,   KC_RBRC,   KC_NO,     KC_NO,   /**/  KC_NO,  KC_NO,   KC_NO,     KC_NO,   KC_PGUP, KC_NO, 
  KC_NO, KC_NO,     KC_NO,     _______,   _______,   _______, /**/  _______,  _______, _______, KC_HOME, KC_PGDN, KC_END
),

// Left-hand home row mods
//#define CTL_F6 LCTL_T(KC_F6)
//#define SFT_F5 LSFT_T(KC_F5)

// Right-hand home row mods
//#define SFT_4 RSFT_T(KC_4)
//nn#define CTL_5 RCTL_T(KC_5)

/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |   +  |   /  |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F8  |  F7  |  F6  |  F5  |   -  |   *  |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |   =  |   .  |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_TRI] = LAYOUT(
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, QWERTY_ON,QWERTY_OFF, _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
float tone_QWERTY_MOD[][2]     = SONG(QWERTY_MOD_SOUND);
float tone_dvorak[][2]     = SONG(NUM_SOUND);
float tone_QWERTY[][2]    = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_0:
    case KC_1:
    case KC_2:
    case KC_3:
    case KC_4:
    case KC_5:
    case KC_6:
    case KC_7:
    case KC_8:
    case KC_9:
	case NUM:
	  break;
	default:
	  layer_off(_NUM);
	  break;
  }
  switch (keycode) {
    case QWERTY_MOD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_QWERTY_MOD);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY_MOD);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_QWERTY);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case QWERTY_ON:
      if (record->event.pressed) {
        layer_on(_QWERTY);
      }
      return false;
      break;
    case QWERTY_OFF:
      if (record->event.pressed) {
        layer_off(_QWERTY);
      }
      return false;
      break;
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _TRI);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _TRI);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _TRI);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _TRI);
      }
      return false;
      break;
    case TRI:
      if (record->event.pressed) {
        layer_on(_TRI);
      } else {
        layer_off(_TRI);
      }
      return false;
      break;
  }
  return true;
}
