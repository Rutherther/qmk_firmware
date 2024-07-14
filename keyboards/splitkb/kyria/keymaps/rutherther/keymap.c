#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/cz_accent.h"

enum layers {
  _QWERTY = 0,
  _PLAIN,
  _GAMES,
  _SYM,
  _NAV,
  _FUNCTION,
  _NUM,
  _GUI,
  _MEDIA,
};

enum custom_keycodes {
  QK_LLCK = SAFE_RANGE,
  CZ_CARETED, // on hold send cz caret prepended to each symbol
  CZ_ACUTED, // on hold send cz acute prepended to each symbol
};

#define SYM      MO(_SYM)
#define NUM      MO(_NUM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define MEDIA    MO(_MEDIA)
#define GUI      MO(_GUI)

#define GAMES    TO(_GAMES)
#define QWERTY   TO(_QWERTY)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_LCTL, KC_QUOTE)
#define SUP_BSLS MT(MOD_LGUI, KC_BSLS)
#define SUP_TAB  MT(MOD_LGUI, KC_TAB)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define ALT_SPC  MT(MOD_LALT, KC_SPC)

#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

#define NAV_V LT(_NAV, KC_V)

#define SYM_SCLN LT(_SYM, KC_SCLN)
#define SYM_A LT(_SYM, KC_A)

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
    SUP_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                                                       KC_Y,     KC_U,       KC_I,     KC_O,     KC_P,     SUP_BSLS,
    CTL_ESC,  SYM_A,    KC_S,     KC_D,     KC_F,      KC_G,                                                       KC_H,     KC_J,       KC_K,     KC_L,     SYM_SCLN, CTL_QUOT,
    OSM_LSFT, KC_Z,     KC_X,     KC_C,     NAV_V,     KC_B,     GAMES,    MEDIA,              FKEYS,    _______,  KC_N,     KC_M,       KC_COMM,  KC_DOT,   KC_SLSH,  OSM_RSFT,
                                  QK_LOCK,  CZ_ACUTED, QK_REP,   ALT_SPC,  NUM,                GUI,      ALT_ENT,  KC_BSPC,  CZ_CARETED, KC_APP
  ),

  [_PLAIN] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                                                       KC_Y,     KC_U,       KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,                                                       KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    OSM_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,    _______,    MEDIA,             FKEYS,    _______,  KC_N,     KC_M,       KC_COMM,  KC_DOT,   KC_SLSH,  OSM_RSFT,
                                  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,    _______
  ),

  [_GAMES] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                                                       KC_Y,     KC_U,       KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,                                                       KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    OSM_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,    KC_LALT,    MEDIA,              FKEYS,    QWERTY,  KC_N,     KC_M,       KC_COMM,  KC_DOT,   KC_SLSH,  OSM_RSFT,
                                  _______,  _______,   NAV,     KC_SPC,   _______,                SYM,    KC_ENT,  _______,  _______,    KC_ESC
  ),

  [_NAV] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,                                                    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,   KC_DEL,
    _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,                                                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SCRL,            _______,  _______,  KC_PAUSE, KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_PSCR,
                                  _______,  _______,  _______,  _______,  _______,            QK_LLCK,  _______,  _______,  _______,  _______
  ),

  [_NUM] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,                                                    KC_EQUAL, KC_8,     KC_9,     KC_4,     KC_PLUS,  KC_SLASH,
    _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,                                                    KC_COLN,  KC_1,     KC_2,     KC_3,     KC_MINUS, KC_ASTR,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SCRL,            _______,  _______,  KC_COMMA, KC_7,     KC_6,     KC_5,     KC_DOT,   _______,
                                  _______,  _______,  _______,  _______,  _______,            QK_LLCK,  KC_0,     _______,  _______,  _______
  ),

  [_SYM] = LAYOUT(
    _______,  _______,  KC_LABK,  KC_RABK,  KC_BSLS,  KC_GRAVE,                                                   KC_AMPR,  KC_UNDS,  KC_LBRC,  KC_RBRC,  _______,  _______,
    _______,  KC_EXLM,  KC_MINUS, KC_PLUS,  KC_EQUAL, KC_HASH,                                                    KC_PIPE,  KC_TILD,  KC_LPRN,  KC_RPRN,  KC_PERC,  _______,
    _______,  _______,  KC_SLASH, KC_ASTR,  KC_CIRC,  _______,  _______,  _______,            _______,  _______,  _______,  KC_DLR,   KC_LCBR,  KC_RCBR,  KC_AT,    _______,
                                  _______,  _______,  _______,  _______,  _______,            QK_LLCK,  _______,  _______,  _______,  _______
  ),

  [_FUNCTION] = LAYOUT(
    _______,  _______,  KC_F4,    KC_F9,    KC_F8,    KC_F10,                                                     _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  KC_F3,    KC_F2,    KC_F1,    KC_F11,                                                     _______,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  _______,
    _______,  _______,  KC_F5,    KC_F6,    KC_F7,    KC_F12,   _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,  _______,  _______,            QK_LOCK,  _______,  _______,  _______,  _______
  ),

  [_GUI] = LAYOUT(
    _______,  WM_MON2,  WM_WS(4), WM_WS(9), WM_WS(8), _______,                                                    _______,  WM_RUN,   WM_RUN2,  WM_TERM,  _______,  _______,
    _______,  WM_MON1,  WM_WS(3), WM_WS(2), WM_WS(1), _______,                                                    _______,  KC_RSFT,  KC_RCTL,  KC_LALT,  KC_RGUI,  _______,
    _______,  WM_MON3,  WM_WS(5), WM_WS(6), WM_WS(7), _______,  _______,  _______,            _______,  _______,  _______,  _______,  WM_KILL,  _______,  _______,  _______,
                                  _______,  _______,  _______,  _______,  _______,            QK_LOCK,  _______,  _______,  _______,  _______
  ),
};

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_czech_acute(keycode, record, CZ_ACUTED, _PLAIN)) { return false; }
  if (!process_czech_caret(keycode, record, CZ_CARETED, _PLAIN)) { return false; }
  if (!process_layer_lock(keycode, record, QK_LLCK)) { return false; }

  /* switch (keycode) {
    case
  } */

  return true;
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
