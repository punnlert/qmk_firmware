/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum userspace_layers {
    _QWERTY             = 0,
    FIRST_DEFAULT_LAYER = 0,
    _COLEMAK,
    LAST_DEFAULT_LAYER = _COLEMAK,
    _NUM,
    _SYMBOL,
    _NAV,
};

#define _DEFAULT_LAYER_1 FIRST_DEFAULT_LAYER
#define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 1)
#if LAST_DEFAULT_LAYER > (FIRST_DEFAULT_LAYER + 1)
#    define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 2)
#endif

enum custom_keycodes {
    DSK_LEFT = SAFE_RANGE,
    DSK_RIGHT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DSK_LEFT:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL));
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case DSK_RIGHT:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL));
        } else {
            // when keycode QMKURL is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬────────────────┬─────────────┬──────┬──────┬──────┐   ┌──────┬─────┬─────┬───┬───┬──────┐
//    │ tab  │       q        │      w      │  e   │  r   │  t   │   │  y   │  u  │  i  │ o │ p │ lalt │
//    ├──────┼────────────────┼─────────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┼───┼──────┤
//    │ esc  │       a        │      s      │  d   │  f   │  g   │   │  h   │  j  │  k  │ l │ ; │  '   │
//    ├──────┼────────────────┼─────────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┼───┼──────┤
//    │ lalt │ LT(_SYMBOL, z) │ LT(_NUM, x) │  c   │  v   │  b   │   │  n   │  m  │  ,  │ . │ / │ esc  │
//    └──────┴────────────────┴─────────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┴───┴──────┘
//                                          │ lctl │ lsft │ lgui │   │ bspc │ spc │ ent │
//                                          └──────┴──────┴──────┘   └──────┴─────┴─────┘
[_DEFAULT_LAYER_1] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_Q              , KC_W           , KC_E    , KC_R    , KC_T    ,     KC_Y    , KC_U   , KC_I    , KC_O   , KC_P    , KC_LALT,
  KC_ESC  , KC_A              , KC_S           , KC_D    , KC_F    , KC_G    ,     KC_H    , KC_J   , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LALT , LT(_SYMBOL, KC_Z) , LT(_NUM, KC_X) , KC_C    , KC_V    , KC_B    ,     KC_N    , KC_M   , KC_COMM , KC_DOT , KC_SLSH , KC_ESC ,
                                                 KC_LCTL , KC_LSFT , KC_LGUI ,     KC_BSPC , KC_SPC , KC_ENT
),

//    ┌──────┬────────────────┬─────────────┬──────┬──────┬──────┐   ┌──────┬─────┬─────┬───┬───┬──────┐
//    │ tab  │       q        │      w      │  f   │  p   │  b   │   │  j   │  l  │  u  │ y │ ; │ lalt │
//    ├──────┼────────────────┼─────────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┼───┼──────┤
//    │ esc  │       a        │      r      │  s   │  t   │  g   │   │  m   │  n  │  e  │ i │ o │  '   │
//    ├──────┼────────────────┼─────────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┼───┼──────┤
//    │ lalt │ LT(_SYMBOL, z) │ LT(_NUM, x) │  c   │  d   │  v   │   │  k   │  h  │  ,  │ . │ / │ esc  │
//    └──────┴────────────────┴─────────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┴───┴──────┘
//                                          │ lctl │ lsft │ lgui │   │ bspc │ spc │ ent │
//                                          └──────┴──────┴──────┘   └──────┴─────┴─────┘
[_DEFAULT_LAYER_2] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_Q              , KC_W           , KC_F    , KC_P    , KC_B    ,     KC_J    , KC_L   , KC_U    , KC_Y   , KC_SCLN , KC_LALT,
  KC_ESC  , KC_A              , KC_R           , KC_S    , KC_T    , KC_G    ,     KC_M    , KC_N   , KC_E    , KC_I   , KC_O    , KC_QUOT,
  KC_LALT , LT(_SYMBOL, KC_Z) , LT(_NUM, KC_X) , KC_C    , KC_D    , KC_V    ,     KC_K    , KC_H   , KC_COMM , KC_DOT , KC_SLSH , KC_ESC ,
                                                 KC_LCTL , KC_LSFT , KC_LGUI ,     KC_BSPC , KC_SPC , KC_ENT
),

//    ┌──────┬──────────┬─────┬──────┬──────┬──────┐   ┌──────┬─────┬─────┬───┬─────┬─────┐
//    │ tab  │          │     │      │      │      │   │  =   │  1  │  2  │ 3 │     │     │
//    ├──────┼──────────┼─────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┼─────┼─────┤
//    │ esc  │          │     │ btn1 │ btn2 │      │   │  0   │  4  │  5  │ 6 │     │     │
//    ├──────┼──────────┼─────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┼─────┼─────┤
//    │ lalt │ MO(_NAV) │     │ ent  │      │      │   │  -   │  7  │  8  │ 9 │     │     │
//    └──────┴──────────┴─────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┴─────┴─────┘
//                            │ lctl │ lsft │ lgui │   │ bspc │ spc │ ent │
//                            └──────┴──────┴──────┘   └──────┴─────┴─────┘
[_NUM] = LAYOUT_split_3x6_3(
  KC_TAB  , _______  , _______ , _______ , _______ , _______ ,     KC_EQUAL , KC_1   , KC_2   , KC_3 , _______ , _______,
  KC_ESC  , _______  , _______ , KC_BTN1 , KC_BTN2 , _______ ,     KC_0     , KC_4   , KC_5   , KC_6 , _______ , _______,
  KC_LALT , MO(_NAV) , _______ , KC_ENT  , _______ , _______ ,     KC_MINUS , KC_7   , KC_8   , KC_9 , _______ , _______,
                                 KC_LCTL , KC_LSFT , KC_LGUI ,     KC_BSPC  , KC_SPC , KC_ENT
),

//    ┌──────┬─────┬──────────┬──────┬──────┬──────┐   ┌──────┬─────┬─────┬───┬───┬─────┐
//    │ tab  │  !  │    @     │  #   │  $   │  %   │   │  ^   │  &  │  *  │ ( │ ) │ ent │
//    ├──────┼─────┼──────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┼───┼─────┤
//    │ esc  │     │          │      │      │      │   │  -   │  =  │  [  │ ] │ \ │  `  │
//    ├──────┼─────┼──────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┼───┼─────┤
//    │ lalt │     │ MO(_NAV) │      │      │      │   │  _   │  +  │  {  │ } │ | │  ~  │
//    └──────┴─────┴──────────┼──────┼──────┼──────┤   ├──────┼─────┼─────┼───┴───┴─────┘
//                            │ lctl │ lsft │ lgui │   │ bspc │ spc │ ent │
//                            └──────┴──────┴──────┘   └──────┴─────┴─────┘
[_SYMBOL] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_EXLM , KC_AT    , KC_HASH , KC_DLR  , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_ENT ,
  KC_ESC  , _______ , _______  , _______ , _______ , _______ ,     KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS , KC_GRV ,
  KC_LALT , _______ , MO(_NAV) , _______ , _______ , _______ ,     KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                 KC_LCTL , KC_LSFT , KC_LGUI ,     KC_BSPC , KC_SPC  , KC_ENT
),

//    ┌─────────┬──────────────┬───────────────┬──────┬──────┬──────┐   ┌──────────┬──────────────┬────────────────┬───────────┬─────┬─────────┐
//    │ QK_BOOT │ PDF(_QWERTY) │ PDF(_COLEMAK) │      │      │      │   │          │ kB_VOLUME_UP │ kB_VOLUME_DOWN │  kB_MUTE  │     │ QK_BOOT │
//    ├─────────┼──────────────┼───────────────┼──────┼──────┼──────┤   ├──────────┼──────────────┼────────────────┼───────────┼─────┼─────────┤
//    │         │              │               │      │      │      │   │   left   │     down     │       up       │   rght    │     │         │
//    ├─────────┼──────────────┼───────────────┼──────┼──────┼──────┤   ├──────────┼──────────────┼────────────────┼───────────┼─────┼─────────┤
//    │         │              │               │      │      │      │   │ DSK_LEFT │              │                │ DSK_RIGHT │     │         │
//    └─────────┴──────────────┴───────────────┼──────┼──────┼──────┤   ├──────────┼──────────────┼────────────────┼───────────┴─────┴─────────┘
//                                             │ lctl │ lsft │ lgui │   │   bspc   │     spc      │      ent       │
//                                             └──────┴──────┴──────┘   └──────────┴──────────────┴────────────────┘
[_NAV] = LAYOUT_split_3x6_3(
  QK_BOOT , PDF(_QWERTY) , PDF(_COLEMAK) , _______ , _______ , _______ ,     _______  , KC_KB_VOLUME_UP , KC_KB_VOLUME_DOWN , KC_KB_MUTE , _______ , QK_BOOT,
  _______ , _______      , _______       , _______ , _______ , _______ ,     KC_LEFT  , KC_DOWN         , KC_UP             , KC_RIGHT   , _______ , _______,
  _______ , _______      , _______       , _______ , _______ , _______ ,     DSK_LEFT , _______         , _______           , DSK_RIGHT  , _______ , _______,
                                           KC_LCTL , KC_LSFT , KC_LGUI ,     KC_BSPC  , KC_SPC          , KC_ENT
)
};

#ifdef OLED_ENABLE

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (!is_keyboard_master()) {
//         return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//     }
//
//     return rotation;
// }

// so that the oled from the non-master side still updates when change layer
bool should_process_keypress(void) {
    return true;
}

bool oled_task_user(void){
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    oled_set_cursor(0, 1);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY ... _COLEMAK:
            oled_write_P(PSTR("base\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("number\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("symbols\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("navigation\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    return false;
}
#endif /* ifdef OLED_ENABLED */
