#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUM 3 

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NUMS | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_BSPC, \
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,       KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       RSFT_T(KC_ENT), \
   TT(_NUM),KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, CTL_T(KC_UP), KC_RGHT \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      |PrvTrk| Pause|NxtTrk|      |   -  |   =  |   {  |   }  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |   _  |   +  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Enter    |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN  , KC_RPRN, KC_DELT, \
  _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_MINS, KC_EQL , KC_LCBR  , KC_RCBR, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LBRC  , KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END  \
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |CShTab|CtTb  |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      |      |      |      | Back | Click|RClick| Fwd  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |MClick|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDw | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV , KC_F1   , KC_F2  , KC_F3  , KC_F4 , _______, _______, LCTL(S(KC_TAB)), LCTL(KC_TAB), _______  , _______, KC_DELT, \
  _______, KC_F5   , KC_F6  , KC_F7  , KC_F8 , _______, KC_BTN4, KC_BTN1        , KC_BTN2     , KC_BTN5  , _______, _______, \
  _______, KC_F9   , KC_F10 , KC_F11 , KC_F12, _______, _______, KC_BTN3        , _______     , _______  , _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______        , KC_HOME     , KC_PGDOWN, KC_PGUP, KC_END \
),


/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |   7  |   8  |   9  |      |BackSp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Exc  |  F5  |  F6  |  F7  |  F8  |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F9  |  F10 |  F11 |  F12 |      |      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |   0  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NUM] =  LAYOUT_ortho_4x12( \
  _______, KC_F1   , KC_F2  , KC_F3  , KC_F4  , _______, _______, KC_7   , KC_8, KC_9   , _______, KC_BSPC, \
  _______, KC_F5   , KC_F6  , KC_F7  , KC_F8  , _______, _______, KC_4   , KC_5, KC_6   , _______, _______, \
  _______, KC_F9   , KC_F10 , KC_F11 , KC_F12 , _______, _______, KC_1   , KC_2, KC_3   , _______, _______, \
  _______, _______ , _______, _______, _______, _______, _______, _______, KC_0, _______, _______, _______ \
)
};

/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      }
      return false;
      break;
  }
  return true;
}
*/