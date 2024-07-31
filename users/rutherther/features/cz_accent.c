#include "cz_accent.h"
#include "keymap_czech.h"

bool cz_send_acuted = false;
bool cz_send_careted = false;

const uint16_t cz_acute_keycodes[] = {
  KC_A, KC_E, KC_I, KC_O, KC_U, KC_Y
};
const uint8_t NUM_ACUTE_KEYCODES = sizeof(cz_acute_keycodes) / sizeof(uint16_t);

const uint16_t cz_caret_keycodes[] = {
  KC_Z, KC_S, KC_C, KC_R, KC_E, KC_D, KC_T, KC_N, KC_U
};
const uint8_t NUM_CARET_KEYCODES = sizeof(cz_caret_keycodes) / sizeof(uint16_t);

const uint16_t cz_scln_char = KC_U;

void process_prefixed_accent(uint16_t keycode, keyrecord_t* record, const uint16_t accent_prefix, const uint16_t *filters, const uint8_t filters_size) {
  // TODO wait for the actual key, this can trigger hold condition, I think
  if (!record->event.pressed) {
    return;
  }

  bool found = false;
  for (int i = 0; i < filters_size; i++) {
    if (QK_MODS_GET_BASIC_KEYCODE(keycode) == filters[i]) {
      found = true;
      break;
    }
  }

  if (!found) {
    return;
  }

  const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();

  clear_mods();
  clear_weak_mods();
  clear_oneshot_mods();

  tap_code16(accent_prefix);

  set_mods(mods);
}

bool process_czech_acute(uint16_t keycode, keyrecord_t* record,
                         uint16_t acute_keycode, int8_t plain_layer) {
  if (keycode == acute_keycode) {
    cz_send_acuted = record->event.pressed;

    // TODO: make sure that this works also for stuff like tap-hold
    // without this plain layer hack.
    // The problem is that here we don't know if it's tap or hold, at
    // least I think. Maybe different function will have to be overriden
    // somehow.
    if (record->event.pressed) {
      layer_move(plain_layer);
    } else {
      layer_move(0);
    }

    return false;
  }

  if (cz_send_acuted) {
    process_prefixed_accent(keycode, record, QK_CZ_ACUTE, cz_acute_keycodes, NUM_ACUTE_KEYCODES);
  }

  return true;
}

bool process_czech_caret(uint16_t keycode, keyrecord_t* record,
                         uint16_t caret_keycode, int8_t plain_layer) {
  if (keycode == caret_keycode) {
    cz_send_careted = record->event.pressed;

    if (record->event.pressed) {
      layer_move(plain_layer);
    } else {
      layer_move(0);
    }
    return false;
  }

  if (cz_send_careted) {
    if (QK_MODS_GET_BASIC_KEYCODE(keycode) == cz_scln_char)
      process_prefixed_accent(keycode, record, QK_CZ_SCLN, cz_caret_keycodes, NUM_CARET_KEYCODES);
    else
      process_prefixed_accent(keycode, record, QK_CZ_CARET, cz_caret_keycodes, NUM_CARET_KEYCODES);
  }

  return true;
}

bool is_in_czech_accent_mode() {
  return cz_send_careted || cz_send_acuted;
}
