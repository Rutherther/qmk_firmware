#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/cz_accent.h"
#include "features/achordion.h"

bool process_caps_word_off(uint16_t keycode, keyrecord_t* record);

enum layers {
  _QWERTY = 0,
  _QWERTY_NOHOMEMODS,
  _PLAIN,
  _GAMES,
  _SYM,
  _NAV,
  _FUNCTION,
  _NUM,
  _WM,
  _CTRL,
  _TTY,
};

enum custom_keycodes {
  QK_LLCK = SAFE_RANGE,
  CZ_CARETED, // on hold send cz caret prepended to each symbol
  CZ_ACUTED, // on hold send cz acute prepended to each symbol
  ACHORDION_OFF,
  ACHORDION_ON,
};

#define SYM      MO(_SYM)
#define NUM      MO(_NUM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define CTRL     MO(_CTRL)
#define WM       MO(_WM)
#define TTY      MO(_TTY)

#define GAMES    TO(_GAMES)
#define QWERTY   TO(_QWERTY)
#define NOHOMODS   TO(_QWERTY_NOHOMEMODS)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_LCTL, KC_QUOTE)
#define SUP_BSLS MT(MOD_LGUI, KC_BSLS)
#define SUP_TAB  MT(MOD_LGUI, KC_TAB)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define ALT_SPC  MT(MOD_LALT, KC_SPC)

#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

#define NAV_V LT(_NAV, KC_V)
#define NUM_G LT(_NUM, KC_G)
#define NUM_SPC LT(_NUM, KC_SPC)
#define WM_M LT(_WM, KC_M)

#define GUI_Q MT(MOD_LGUI, KC_Q)
#define SYM_A LT(_SYM, KC_A)
#define LALT_S MT(MOD_LALT, KC_S)
#define LSFT_D MT(MOD_LSFT, KC_D)
#define LCTL_F MT(MOD_LCTL, KC_F)

#define GUI_P MT(MOD_RGUI, KC_P)
#define SYM_SCLN LT(_SYM, KC_SCLN)
#define LALT_L MT(MOD_LALT, KC_L)
#define RSFT_K MT(MOD_RSFT, KC_K)
#define LCTL_J MT(MOD_LCTL, KC_J)

#define WM_MON1 G(KC_W)
#define WM_MON2 G(KC_E)
#define WM_MON3 G(KC_R)
#define WM_WS(i) G(KC_##i)
#define WM_RUN G(KC_SCLN)
#define WM_RUN2 G(S(KC_SCLN))
#define WM_TERM G(S(KC_ENT))
#define WM_KILL G(S(KC_C))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_TAB,  GUI_Q,    KC_W,     KC_E,     KC_R,      KC_T,                                                        KC_Y,     KC_U,     KC_I,     KC_O,     GUI_P,    KC_BSLS,
    KC_ESC,  SYM_A,    LALT_S,   LSFT_D,   LCTL_F,    KC_G,                                                        KC_H,     LCTL_J,   RSFT_K,   LALT_L,   SYM_SCLN, KC_QUOT,
    QK_LOCK, KC_Z,     KC_X,     KC_C,     NAV_V,     KC_B,      _______, CTRL,                FKEYS,     TTY,     KC_N,     WM_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_APP,
                                 _______,  _______,   QK_REP,    NUM_SPC,  CZ_ACUTED,          CZ_CARETED,KC_ENT,  KC_BSPC,  _______,  _______
  ),

  [_QWERTY_NOHOMEMODS] = LAYOUT(
    SUP_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                                                        KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     SUP_BSLS,
    CTL_ESC,  SYM_A,    KC_S,     KC_D,     KC_F,      NUM_G,                                                       KC_H,     KC_J,    KC_K,     KC_L,     SYM_SCLN, CTL_QUOT,
    OSM_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     _______,    CTRL,               FKEYS,     TTY,      KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  OSM_RSFT,
                                  QK_LOCK,  _______,   QK_REP,   ALT_SPC,  CZ_ACUTED,          CZ_CARETED,ALT_ENT,  KC_BSPC,  KC_DEL,  KC_APP
  ),

  [_PLAIN] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                                                       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_LCTL,  KC_A,     KC_S,     LSFT_D,   KC_F,      KC_G,                                                       KC_H,     KC_J,     RSFT_K,   KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,    _______,    CTRL,              FKEYS,    _______,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,  _______
  ),

  [_GAMES] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                                                       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,                                                       KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,    KC_LALT,    CTRL,               FKEYS,    _______, KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                  _______,  _______,   NAV,     KC_SPC,     NUM,                SYM,      KC_ENT,  _______,  _______,  KC_ESC
  ),

  [_SYM] = LAYOUT(
    _______,  _______,  KC_LABK,  KC_RABK,  KC_BSLS,  KC_GRAVE,                                                   KC_AMPR,  KC_UNDS,  KC_LBRC,  KC_RBRC,  KC_PERC,  _______,
    _______,  KC_EXLM,  KC_MINUS, KC_PLUS,  KC_EQUAL, KC_HASH,                                                    KC_PIPE,  KC_TILD,  KC_LPRN,  KC_RPRN,  KC_COLON, KC_DQUO,
    _______,  KC_COLN,  KC_SLASH, KC_ASTR,  KC_CIRC,  _______,  _______,  _______,            _______,  _______,  _______,  KC_DLR,   KC_LCBR,  KC_RCBR,  KC_AT,    _______,
                                  _______,  _______,  _______,  _______,  _______,            QK_LLCK,  _______,  KC_DEL,   _______,  _______
  ),

  [_NAV] = LAYOUT(
    _______,  KC_LGUI,  _______,  _______,  _______,  _______,                                                    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,   KC_DEL,
    _______,  KC_LCTL,  KC_LALT,  OSM_LSFT, KC_LCTL,  _______,                                                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SCRL,            _______,  _______,  KC_PAUSE, KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_PSCR,
                                  _______,  _______,  _______,  _______,  _______,            QK_LLCK,  _______,  _______,  _______,  _______
  ),

  [_FUNCTION] = LAYOUT(
    _______,  _______,  KC_F4,    KC_F9,    KC_F8,    KC_F10,                                                     _______,  _______,  _______,  _______,  KC_RGUI,  _______,
    _______,  _______,  KC_F3,    KC_F2,    KC_F1,    KC_F11,                                                     _______,  KC_LCTL,  OSM_RSFT, KC_LALT,  KC_RGUI,  _______,
    _______,  _______,  KC_F5,    KC_F6,    KC_F7,    KC_F12,   _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,  _______,  _______,            QK_LLCK,  _______,  _______,  _______,  _______
  ),

  [_NUM] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,                                                    KC_PLUS,  KC_8,     KC_9,     KC_4,     _______,  _______,
    _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  OSM_LSFT, _______,                                                    KC_EQUAL, KC_1,     KC_2,     KC_3,     KC_SLASH, _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  KC_MINUS, KC_7,     KC_6,     KC_5,     KC_DOT,   _______,
                                  _______,  _______,  _______,  _______,  _______,            QK_LLCK,  KC_0,     _______,  _______,  _______
  ),

  /* [_NUML] = LAYOUT( */
  /*   _______, _______,   KC_4,     KC_9,     KC_8,  KC_PLUS,                                                       _______,  _______,  _______,  _______,  KC_RGUI,  _______, */
  /*   _______, KC_SLASH,  KC_3,     KC_2,     KC_1,  KC_EQUAL,                                                      _______,  KC_LCTL,  KC_RSFT,  KC_LALT,  KC_RGUI,  _______, */
  /*   _______, KC_DOT,    KC_5,     KC_6,     KC_7,  KC_MINUS,    _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, */
  /*                                 _______,  _______,  _______,  KC_0,     QK_LLCK,            _______,  _______,  _______,  _______,  _______ */
  /* ), */

  [_WM] = LAYOUT(
    _______,  WM_MON2,  WM_WS(4), WM_WS(9), WM_WS(8), _______,                                                    _______,  _______,  WM_RUN,   WM_TERM,  _______,  _______,
    _______,  WM_MON1,  WM_WS(3), WM_WS(2), WM_WS(1), _______,                                                    _______,  KC_RCTL,  KC_RSFT,  KC_LALT,  KC_RGUI,  WM_KILL,
    _______,  WM_MON3,  WM_WS(5), WM_WS(6), WM_WS(7), _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  WM_RUN2,
                                  _______,  _______,  _______,  _______,  QK_LLCK,            _______,  _______,  _______,  _______,  _______
  ),

  [_CTRL] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,                                                    DT_UP,    _______,  _______,  _______,  _______,  ACHORDION_ON,
    _______,  _______,  _______,  _______,  _______,  _______,                                                    DT_DOWN,  _______,  _______,  _______,  _______,  ACHORDION_OFF,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  DT_PRNT,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,  _______,  _______,            QWERTY,   NOHOMODS, GAMES,  _______,  _______
  ),

  [_TTY] = LAYOUT(
    _______,  _______,  LCA(KC_F4), LCA(KC_F9), LCA(KC_F8), LCA(KC_F10),                                                     _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  LCA(KC_F3), LCA(KC_F2), LCA(KC_F1), LCA(KC_F11),                                                     _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  LCA(KC_F5), LCA(KC_F6), LCA(KC_F7), LCA(KC_F12), _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                    _______,    _______,    _______,     _______,  QK_LLCK,            _______,  _______,  _______,  _______,  _______
  ),

  /* [_TEMPLATE] = LAYOUT( */
  /*   _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,  _______,  _______, */
  /*   _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,  _______,  _______, */
  /*   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, */
  /*                                 _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______ */
  /* ), */
};

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool achordion = true;
  if (!process_caps_word_off(keycode, record)) { return false; }
  if (!process_czech_acute(keycode, record, CZ_ACUTED, _PLAIN)) { return false; }
  if (!process_czech_caret(keycode, record, CZ_CARETED, _PLAIN)) { return false; }
  if (!process_layer_lock(keycode, record, QK_LLCK)) { return false; }

  // NOTE: it's important that this is under processing czech accent modes
  if (!is_in_czech_accent_mode() && achordion)
    if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {
    case ACHORDION_OFF:
      cancel_achordion();
      achordion = false;
      return false;
    case ACHORDION_ON:
      achordion = true;
      return false;
  }

  return true;
}

bool process_caps_word_off(uint16_t keycode, keyrecord_t* record)
{
  if (is_caps_word_on() && keycode == KC_ESC) {
    caps_word_off();
    return false;
  }

  return true;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                      keyrecord_t* tap_hold_record,
                      uint16_t other_keycode,
                      keyrecord_t* other_record) {
  if (other_keycode == CZ_CARETED ||
      other_keycode == CZ_ACUTED ||
      tap_hold_keycode == CZ_ACUTED ||
      tap_hold_keycode == CZ_CARETED) {
    return true;
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
    case MOD_LGUI:
    case MOD_RGUI:
      return true;  // Eagerly apply Shift and Ctrl mods.

    default:
      return false;
  }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;
        default:
            return false;  // Deactivate Caps Word.
    }
}

/*
qmk-keyboard-format:json:begin
{
    "name": "Kyria",
    "numkeys": 50,
    "rows": [
        [  0,  1,  2,  3,  4,  5, -1, -1, -2, -1, -1,  6,  7,  8,  9, 10, 11 ],
        [ 12, 13, 14, 15, 16, 17, -1, -1, -2, -1, -1, 18, 19, 20, 21, 22, 23 ],
        [ 24, 25, 26, 27, 28, 29, 30, 31, -2, 32, 33, 34, 35, 36, 37, 38, 39 ],
        [ -1, -1, -1, 40, 41, 42, 43, 44, -2, 45, 46, 47, 48, 49, -1, -1, -1 ]
        ]
}
qmk-keyboard-format:json:end
*/
