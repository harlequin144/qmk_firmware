// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  WDUSER,
  WDPASS,
  WDURPS,

};

#define ALT_ENT MT(MOD_LALT,KC_ENT)
#define SCRCAP LGUI(LSFT(KC_S))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_NO,   KC_NO,   KC_LSFT, KC_LCTL, KC_DEL,                             KC_BSPC, KC_RCTL, KC_RSFT, KC_NO,   KC_NO,   KC_LGUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F11,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F10,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F5,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ADJUST,           KC_ESC,  KC_N,    KC_M,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, LOWER,   ALT_ENT,                   KC_SPC,  RAISE,   KC_RCTL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_MPLY, KC_NO,   KC_NO,   _______, _______, _______,                            _______, _______, _______, KC_NO,   KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MNXT, KC_NO,   KC_TILD, KC_COMM, KC_DOT,  KC_MINS,                            KC_UNDS,S(KC_QUOT),KC_QUOT,KC_GRV,  KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_PLUS, KC_EQL,  _______, _______,          KC_NO,   _______, KC_SLSH, KC_BSLS, KC_QUES, KC_NO,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_NO,   _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬─────────┬──────────┬──────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_NO,   KC_NO,    _______,   _______,   _______,                            _______, _______, _______, KC_NO,   KC_NO,   KC_BTN1,
  //├────────┼────────┼─────────┼──────────┼──────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  S(KC_9),   S(KC_0),   _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_BTN2,
  //├────────┼────────┼─────────┼──────────┼──────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______,S(KC_COMM),S(KC_LBRC),S(KC_RBRC),S(KC_DOT),                          KC_BTN4, S(KC_TAB),KC_TAB, KC_BTN5, KC_NO,   KC_BTN3,
  //├────────┼────────┼─────────┼──────────┼──────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  KC_LBRC,   KC_RBRC,   _______, KC_NO,            _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   _______,
  //└────────┴────────┴─────────┴──┬───────┴───┬──────┴─┬──────┴───┬────┘        └─┬──────┴─┬──────┴─┬──────┴─┬─────┴────────┴────────┴────────┘
                                    _______,    _______, KC_NO,                     _______, _______, _______
                                // └───────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     WDUSER,  _______, _______, RGB_HUD, RGB_HUI, RGB_TOG,                            _______, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, SCRCAP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     WDPASS,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  RGB_MOD,                            _______, KC_7,    KC_8,    KC_9,    _______, KC_CAPS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     WDURPS,  KC_F8,   KC_F7,   KC_F6,   KC_F5,   _______,                            KC_0,    KC_4,    KC_5,    KC_6,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,          _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_0,   
									_______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
	case WDURPS:
      if (record->event.pressed) {
        SEND_STRING("dylant\trwtest#2\n");
      }
	  return true;
      break;
	case WDUSER:
      if (record->event.pressed) {
        SEND_STRING("dylant");
      }
	  return true;
      break;
	case WDPASS:
      if (record->event.pressed) {
        SEND_STRING("rwtest#2");
      }
	  return true;
      break;
    
  }
  return true;
}