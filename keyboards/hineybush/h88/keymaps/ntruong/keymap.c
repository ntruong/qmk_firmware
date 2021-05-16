/* Copyright 2019 Josh Hinnebusch

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _VIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer 0: Base layer
   *
   * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐ ┌───┬───┬───┐
   * │ ⎋ ││ ⅰ │ ⅱ │ ⅲ │ ⅳ ││ ⅴ │ ⅵ │ ⅶ │ ⅷ ││ ⅸ │ ⅹ │ ⅺ │ ⅻ ││   │ │ ⎙ │ ↕ │ ≠ │
   * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │   ⌫   │ │〖 │ ⇱ │ ⎗ │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
   * │  ↹  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │ ⌦ │ ⇲ │ ⎗ │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
   * │  ⎋⌃  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ⒉ │ ' │   ↩    │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
   * │   ⇧    │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    ⇧     │     │ ↑ │
   * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤ ┌───┼───┼───┐
   * │  ⌃  │   │  ⌘  │          Space            │  ⌥  │   │  ⒈  │ │ ← │ ↓ │ → │
   * └─────┘   └─────┴───────────────────────────┴─────┘   └─────┘ └───┴───┴───┘
   *
   */
  [_BASE] = LAYOUT_tkl_ansi_wkl(
      KC_ESC,         KC_F1, KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9,  KC_F10,            KC_F11,  KC_F12, KC_F13,     KC_PSCR, KC_SLCK, KC_PAUS,
      KC_GRV,         KC_1,  KC_2,    KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,   KC_0,              KC_MINS, KC_EQL, KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
      KC_TAB,         KC_Q,  KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,              KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
      LCTL_T(KC_ESC), KC_A,  KC_S,    KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,   LT(_VIM, KC_SCLN), KC_QUOT, KC_ENT,
      KC_LSFT,        KC_Z,  KC_X,    KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,           KC_RSFT,                              KC_UP,
      KC_LCTL,               KC_LGUI,               KC_SPC,                               KC_RALT,           MO(_FN),                     KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Layer 1: Function layer
   *
   * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐ ┌───┬───┬───┐
   * │ ⟳ ││   │   │   │   ││   │   │   │   ││   │   │   │   ││   │ │   │   │   │
   * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   ⌦   │ │   │ ≡ │ ♫ │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │ │   │ ※ │ ♪ │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
   * │      │   │ s │   │   │   │ h │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
   * │   ⇪    │   │   │   │ v │   │   │   │   │   │   │          │     │   │
   * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤ ┌───┼───┼───┐
   * │     │   │     │             ▶             │     │   │     │ │ ♪ │ ¤ │ ♫ │
   * └─────┘   └─────┴───────────────────────────┴─────┘   └─────┘ └───┴───┴───┘
   *
   */
  [_FN] = LAYOUT_tkl_ansi_wkl(
      RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,    _______, RGB_MOD, KC_VOLU,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, RGB_TOG, KC_VOLD,
      _______, _______, RGB_SAI, _______, _______, _______, RGB_HUI, _______, _______, _______, _______, _______, _______,
      KC_CAPS, _______, _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______,                              _______,
      _______,          _______,                   KC_MPLY,                            _______,          _______,                     KC_MPRV, KC_MUTE, KC_MNXT
  ),

  /* Layer 2: Vim layer
   *
   * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐ ┌───┬───┬───┐
   * │   ││   │   │   │   ││   │   │   │   ││   │   │   │   ││   │ │   │   │   │
   * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
   * │   │   │   │   │ ⇲ │   │   │   │   │   │ ⇱ │   │   │       │ │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
   * │     │   │   │   │   │   │   │ ⎗ │   │   │   │   │   │     │ │   │   │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
   * │      │   │   │ ⎗ │ ⎗ │   │ ← │ ↓ │ ↑ │ → │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
   * │        │   │ ⌦ │   │   │ ⎗ │   │   │   │   │   │          │     │   │
   * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤ ┌───┼───┼───┐
   * │     │   │     │                           │     │   │     │ │   │   │   │
   * └─────┘   └─────┴───────────────────────────┴─────┘   └─────┘ └───┴───┴───┘
   *
   */
  [_VIM] = LAYOUT_tkl_ansi_wkl(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
      _______, _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, KC_HOME, _______, _______, _______,   _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
      _______, _______, _______, KC_PGDN, KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
      _______, _______, KC_DEL,  _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,                              _______,
      _______,          _______,                   _______,                            _______,          _______,                     _______, _______, _______
  ),

};

void matrix_init_user(void) { }

void matrix_scan_user(void) { }

bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }
