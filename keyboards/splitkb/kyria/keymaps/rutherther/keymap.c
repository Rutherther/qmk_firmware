#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/cz_accent.h"

enum layers {
  _QWERTY = 0,
  _SYM,
  _NAV,
  _FUNCTION,
  _NUM,
  _GUI,
  _GAMES,
  _MEDIA,
  _PLAIN,
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
#define QWERTY   TO(_GAMES)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_LCTL, KC_QUOTE)
#define SUP_BSLS MT(MOD_LGUI, KC_BSLS)
#define SUP_TAB  MT(MOD_LGUI, KC_TAB)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define ALT_SPC  MT(MOD_LALT, KC_SPC)

#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

/// and gui map

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |LGUI/Tab|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | \/LGui |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |Ctrl/Esc|A/SYM |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |' "/Ctrl|
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * | LShift |   Z  |   X  |   C  |   V  |   B  | GAMES| MEDIA|  |F-keys|      |   N  |   M  | ,  < | .  > | /  ? | RShift |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        | Lock | Czech| Repea| LAlt/| Num  |  | GUI  | LAlt/| Bksp | Czech| Menu |
//  *                        | Key  | Acute| Key  | Space|      |  |      | Enter|      | Caret|      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
  [_QWERTY] = LAYOUT(
    SUP_TAB , KC_Q ,  KC_W   ,  KC_E  ,     KC_R ,   KC_T ,                                          KC_Y ,   KC_U ,  KC_I ,   KC_O ,  KC_P , SUP_BSLS,
    CTL_ESC , LT(_SYM, KC_A) ,  KC_S   ,  KC_D  ,     KC_F ,   KC_G ,                                          KC_H ,   KC_J ,  KC_K ,   KC_L ,LT(_SYM, KC_SCLN), CTL_QUOT,
    OSM_LSFT, KC_Z ,  KC_X   ,  KC_C  ,LT(_NAV, KC_V),   KC_B , GAMES, MEDIA  ,     FKEYS  , _______ , KC_N ,   LT(NAV, KC_M) ,KC_COMM, KC_DOT ,KC_SLSH, OSM_RSFT ,
    QK_LOCK, CZ_ACUTED,QK_REP,  ALT_SPC  , NUM    ,     GUI    ,ALT_ENT, KC_BSPC, CZ_CARETED , KC_APP
  ),

  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                                     KC_HOME, KC_PGDN, KC_PGUP,KC_END, _______, KC_DEL,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, KC_INS,
    _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
    _______, _______, _______, _______, _______, QK_LLCK, _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                                     KC_EQUAL, KC_8, KC_9,KC_4, KC_PLUS   , KC_SLASH,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_COLN, KC_1, KC_2, KC_3, KC_MINUS  , KC_ASTR,
    _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_COMMA, KC_7, KC_6, KC_5, KC_DOT    , _______,
    _______, _______, _______, _______, _______, QK_LLCK, KC_0, _______, _______, _______
  ),

  [_SYM] = LAYOUT(
                  _______ , _______ , KC_LABK,  KC_RABK,   KC_BSLS,KC_GRAVE,                                      KC_AMPR,KC_UNDS, KC_LBRC,KC_RBRC, _______, _______ ,
    _______ ,KC_EXLM,KC_MINUS,  KC_PLUS,  KC_EQUAL, KC_HASH,                                          KC_PIPE, KC_TILD, KC_LPRN, KC_RPRN, KC_PERC, _______,
    _______ , _______ , KC_SLASH,  KC_ASTR,  KC_CIRC, _______ , _______ , _______ ,      _______ , _______ , _______ ,  KC_DLR,KC_LCBR,KC_RCBR,   KC_AT, _______,
                                _______, _______, _______, _______, _______, QK_LLCK, _______, _______, _______, _______
  ),

/*
* Function Layer: Function keys
*
* ,-------------------------------------------.                              ,-------------------------------------------.
* |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
* |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
* |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
* |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        `----------------------------------'  `----------------------------------'
*/
  [_FUNCTION] = LAYOUT(
    _______,  _______,  KC_F4 ,  KC_F9,  KC_F8, KC_F10,                                     _______, _______, _______, _______, _______, _______,
    _______,  _______,  KC_F3 ,  KC_F2 ,  KC_F1 , KC_F11,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
    _______,  _______,  KC_F5 ,  KC_F6 ,  KC_F7 , KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, QK_LOCK, _______, _______, _______, _______
  ),

  [_GUI] = LAYOUT(
    _______,  G(KC_W),  G(KC_4) , G(KC_9) ,  G(KC_8), _______,                   _______, G(S(KC_SCLN)), G(S(KC_ENT)), _______, _______, _______,
    _______,  G(KC_E),  G(KC_3) ,  G(KC_2) ,  G(KC_1) , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
    _______,  G(KC_R),  G(KC_5) ,  G(KC_6) ,  G(KC_7) , _______, _______, _______, _______, _______, _______, G(KC_SCLN), G(S(KC_C)), _______, _______, _______,
                                _______, _______, _______, _______, _______, QK_LOCK, _______, _______, _______, _______
  ),

  [_GAMES] = LAYOUT(
    KC_TAB , KC_Q ,  KC_W   ,  KC_E  ,     KC_R ,   KC_T ,                                          KC_Y ,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSLS,
    KC_LCTL, KC_A ,  KC_S   ,  KC_D  ,     KC_F ,   KC_G ,                                          KC_H ,   KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_QUOT,
    OSM_LSFT,KC_Z ,  KC_X   ,  KC_C  ,     KC_V ,   KC_B ,  QWERTY  , MEDIA  ,     FKEYS  , _______,KC_N ,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, OSM_RSFT ,
                              QK_LOCK, CZ_ACUTED, KC_SPC,  QK_REP  , NUM    ,     GUI    , KC_BSPC,KC_ENT, CZ_CARETED , KC_APP
  ),
  [_PLAIN] = LAYOUT(
    KC_TAB , KC_Q ,  KC_W   ,  KC_E  ,     KC_R ,   KC_T ,                                          KC_Y ,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSLS,
    KC_LCTL, KC_A ,  KC_S   ,  KC_D  ,     KC_F ,   KC_G ,                                          KC_H ,   KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_QUOT,
    OSM_LSFT,KC_Z ,  KC_X   ,  KC_C  ,     KC_V ,   KC_B ,  GAMES   , MEDIA  ,     FKEYS  , _______ ,KC_N ,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, OSM_RSFT ,
                              QK_LOCK, CZ_ACUTED,KC_SPC,  QK_REP  , NUM    ,     GUI    , KC_BSPC,KC_ENT, CZ_CARETED , KC_APP
  ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
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
