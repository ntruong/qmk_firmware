#include QMK_KEYBOARD_H

#undef  PRODUCT
#define PRODUCT hhkb

enum keycodes {
  QWERTY = SAFE_RANGE,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define RECORD1 DYN_REC_START1
#define RECORD2 DYN_REC_START2
#define REPLAY1 DYN_MACRO_PLAY1
#define REPLAY2 DYN_MACRO_PLAY2
#define STOPREC DYN_REC_STOP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer 0: Default layer
   *
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │ ⎋ │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │  ↹  │ ⒉ │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  ⌫  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │  ⎋⌃  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ⒈ │ ' │   ↩    │
   * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┬───┤
   * │   ⇧   │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   ⇧   │ ⒈ │
   * └───────┴─┬─┴─┬─┴─┬─┴───┴───┴───┴───┴───┴─┬─┴─┬─┴─┬─────┴───┘
   *           │ ⌥ │ ⌘ │         Space         │ ⌘ │ ⌥ │
   *           └───┴───┴───────────────────────┴───┴───┘
   *
   */
  [0] = LAYOUT_60_tsangan_hhkb(
      KC_GRV,         KC_1,        KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,           KC_MINS, KC_EQL,  KC_BSLS, KC_ESC,
      KC_TAB,         LT(2, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,           KC_LBRC, KC_RBRC, KC_BSPC,
      LCTL_T(KC_ESC), KC_A,        KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   LT(1, KC_SCLN), KC_QUOT, KC_ENT,
      KC_LSFT,        KC_Z,        KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,        KC_RSFT, TO(1),
      KC_LALT, KC_NO, KC_LGUI, KC_SPC, KC_RGUI, KC_NO, KC_RALT
      ),

  /* Layer 1: Default layer
   *
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │ ⟳ │ ⅰ │ ⅱ │ ⅲ │ ⅳ │ ⅴ │ ⅵ │ ⅶ │ ⅷ │ ⅸ │ ⅹ │ ⅺ │ ⅻ │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │   │ † │ ‡ │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │   │   │   │ ← │ ↓ │ ↑ │ → │   │   │        │
   * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┬───┤
   * │   ⇪   │   │   │   │   │   │   │   │   │   │   │       │   │
   * └───────┴─┬─┴─┬─┴─┬─┴───┴───┴───┴───┴───┴─┬─┴─┬─┴─┬─────┴───┘
   *           │ ♪ │ ♫ │           ▶           │   │   │
   *           └───┴───┴───────────────────────┴───┴───┘
   *
   */
  [1] = LAYOUT_60_tsangan_hhkb(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
      _______, _______, REPLAY1, REPLAY2, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
      KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, KC_VOLD, KC_VOLU, KC_PAUS, _______, _______, _______
      ),

  /* Layer 2: Macro layer
   *
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │  ∅  │ ∅ │ † │ ‡ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │  ∅  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │  ∅   │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │   ∅    │
   * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┬───┤
   * │   ∅   │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │ ∅ │   ∅   │ ∅ │
   * └───────┴─┬─┴─┬─┴─┬─┴───┴───┴───┴───┴───┴─┬─┴─┬─┴─┬─────┴───┘
   *           │ ∅ │ ∅ │           ◙           │ ∅ │ ∅ │
   *           └───┴───┴───────────────────────┴───┴───┘
   *
   */
  [2] = LAYOUT_60_tsangan_hhkb(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, RECORD1, RECORD2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, STOPREC, XXXXXXX, XXXXXXX, XXXXXXX
      )
};

// Gets called before the keymap is set up.
void matrix_init_user(void) { }


// Gets called every matrix scan.
void matrix_scan_user(void) { }

void led_set_user(uint8_t usb_led) { }

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (!process_record_dynamic_macro(keycode, record)) { return false; }
  return true;
}
