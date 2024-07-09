#include "cz_accent.h"
#include "keymap_czech.h"

bool process_czech_acute(uint16_t keycode, keyrecord_t* record,
                         uint16_t acute_keycode, int8_t plain_layer) {
  static bool cz_send_acuted = false;

  if (keycode == acute_keycode) {
    cz_send_acuted = record->event.pressed;

    if (record->event.pressed) {
      layer_move(plain_layer);
    } else {
      layer_move(0);
    }

    return false;
  }

  // TODO: Ignore everything else except for A - Z (or even just the letters that are actually used with acute in czech)
  // 1. release shift if held, save if held to shift_held
  // 2. send acute accent char with ralt
  // 3. if shift_held, hold shift
  // 4. process original
  if (cz_send_acuted &&
      keycode != acute_keycode &&
      keycode != KC_LEFT_SHIFT &&
      keycode != KC_RIGHT_SHIFT &&
      record->event.pressed) {
    const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();

    clear_mods();
    clear_weak_mods();
    clear_oneshot_mods();

    tap_code16(RALT(CZ_ACUT));

    set_mods(mods);
  }

  return true;
}

bool process_czech_caret(uint16_t keycode, keyrecord_t* record,
                         uint16_t caret_keycode, int8_t plain_layer) {
  static bool cz_send_careted = false;

  if (keycode == caret_keycode) {
    cz_send_careted = record->event.pressed;

    if (record->event.pressed) {
      layer_move(plain_layer);
    } else {
      layer_move(0);
    }
    return false;
  }

  // TODO: Ignore everything else except for A - Z (or even just the letters that are actually used with acute in czech)
  if (cz_send_careted && keycode != caret_keycode &&
      keycode != KC_LEFT_SHIFT &&
      keycode != KC_RIGHT_SHIFT &&
      record->event.pressed) {

    const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();

    clear_mods();
    clear_weak_mods();
    clear_oneshot_mods();

    if (QK_MODS_GET_BASIC_KEYCODE(keycode) == KC_U) {
      tap_code16(LSFT(RALT(CZ_SCLN)));
    } else {
      tap_code16(LSFT(RALT(CZ_ACUT)));
    }

    set_mods(mods);
  }

  return true;
}
