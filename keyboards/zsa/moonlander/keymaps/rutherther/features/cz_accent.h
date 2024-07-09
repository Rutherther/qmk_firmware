#include <stdint.h>
#include "quantum.h"

// Type czech caret and acute symbols.
// Uses czech programmer/coder layer from OS.

// When acute or caret keycode is held, the layer will be switched to
// plain_layer, if it's not equal to -1. This is a hack for not having
// to care about tap hold, tap dance characters.

bool process_czech_acute(uint16_t keycode, keyrecord_t* record,
                         uint16_t acute_keycode, int8_t plain_layer);

bool process_czech_caret(uint16_t keycode, keyrecord_t* record,
                         uint16_t caret_keycode, int8_t plain_layer);
