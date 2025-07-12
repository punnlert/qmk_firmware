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

enum layer_names {
    _QWERTY,
    _COLMAK,
    _NUM,
    _SYMBOL,
    _NAV
};

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
//        ┌──────┬───┬───┬───────┬──────┬──────┐   ┌─────┬─────┬───────┬───┬───┬──────┐
//        │ tab  │ q │ w │   e   │  r   │  t   │   │  y  │  u  │   i   │ o │ p │ bspc │
//        ├──────┼───┼───┼───────┼──────┼──────┤   ├─────┼─────┼───────┼───┼───┼──────┤
//        │ esc  │ a │ s │   d   │  f   │  g   │   │  h  │  j  │   k   │ l │ ; │  '   │
//        ├──────┼───┼───┼───────┼──────┼──────┤   ├─────┼─────┼───────┼───┼───┼──────┤
//        │ lctl │ z │ x │   c   │  v   │  b   │   │  n  │  m  │   ,   │ . │ / │ esc  │
//        └──────┴───┴───┼───────┼──────┼──────┤   ├─────┼─────┼───────┼───┴───┴──────┘
//                       │ MO(2) │ lsft │ lgui │   │ spc │ ent │ MO(3) │
//                       └───────┴──────┴──────┘   └─────┴─────┴───────┘
[_QWERTY] = LAYOUT_split_3x6_3(
      KC_TAB  , KC_Q , KC_W , KC_E  , KC_R    , KC_T    ,     KC_Y   , KC_U   , KC_I    , KC_O   , KC_P    , KC_BSPC,
      KC_ESC  , KC_A , KC_S , KC_D  , KC_F    , KC_G    ,     KC_H   , KC_J   , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
      KC_LCTL , KC_Z , KC_X , KC_C  , KC_V    , KC_B    ,     KC_N   , KC_M   , KC_COMM , KC_DOT , KC_SLSH , KC_ESC ,
                              MO(2) , KC_LSFT , KC_LGUI ,     KC_SPC , KC_ENT , MO(3)
),

//        ┌──────┬───┬───┬───────┬──────┬──────┐   ┌─────┬─────┬───────┬───┬───┬──────┐
//        │ tab  │ q │ w │   f   │  p   │  b   │   │  j  │  l  │   u   │ y │ ; │ bspc │
//        ├──────┼───┼───┼───────┼──────┼──────┤   ├─────┼─────┼───────┼───┼───┼──────┤
//        │ esc  │ a │ r │   s   │  t   │  g   │   │  m  │  n  │   e   │ i │ o │  '   │
//        ├──────┼───┼───┼───────┼──────┼──────┤   ├─────┼─────┼───────┼───┼───┼──────┤
//        │ lctl │ x │ c │   d   │  v   │  z   │   │  k  │  h  │   ,   │ . │ / │ esc  │
//        └──────┴───┴───┼───────┼──────┼──────┤   ├─────┼─────┼───────┼───┴───┴──────┘
//                       │ MO(2) │ lsft │ lgui │   │ spc │ ent │ MO(3) │
//                       └───────┴──────┴──────┘   └─────┴─────┴───────┘
[_COLMAK] = LAYOUT_split_3x6_3(
      KC_TAB  , KC_Q , KC_W , KC_F  , KC_P    , KC_B    ,     KC_J   , KC_L   , KC_U    , KC_Y   , KC_SCLN , KC_BSPC,
      KC_ESC  , KC_A , KC_R , KC_S  , KC_T    , KC_G    ,     KC_M   , KC_N   , KC_E    , KC_I   , KC_O    , KC_QUOT,
      KC_LCTL , KC_X , KC_C , KC_D  , KC_V    , KC_Z    ,     KC_K   , KC_H   , KC_COMM , KC_DOT , KC_SLSH , KC_ESC ,
                              MO(2) , KC_LSFT , KC_LGUI ,     KC_SPC , KC_ENT , MO(3)
),

//        ┌──────┬─────┬─────┬─────┬──────┬──────┐   ┌─────┬─────┬───────┬───┬─────┬─────┐
//        │ tab  │     │     │     │      │      │   │  =  │  1  │   2   │ 3 │     │     │
//        ├──────┼─────┼─────┼─────┼──────┼──────┤   ├─────┼─────┼───────┼───┼─────┼─────┤
//        │ esc  │     │     │     │      │      │   │  0  │  4  │   5   │ 6 │     │     │
//        ├──────┼─────┼─────┼─────┼──────┼──────┤   ├─────┼─────┼───────┼───┼─────┼─────┤
//        │ lctl │     │     │     │      │      │   │  -  │  7  │   8   │ 9 │     │     │
//        └──────┴─────┴─────┼─────┼──────┼──────┤   ├─────┼─────┼───────┼───┴─────┴─────┘
//                           │     │ lsft │ lgui │   │ spc │ ent │ MO(4) │
//                           └─────┴──────┴──────┘   └─────┴─────┴───────┘
[_NUM] = LAYOUT_split_3x6_3(
      KC_TAB  , _______ , _______ , _______ , _______ , _______ ,     KC_EQUAL , KC_1   , KC_2  , KC_3 , _______ , _______,
      KC_ESC  , _______ , _______ , _______ , _______ , _______ ,     KC_0     , KC_4   , KC_5  , KC_6 , _______ , _______,
      KC_LCTL , _______ , _______ , _______ , _______ , _______ ,     KC_MINUS , KC_7   , KC_8  , KC_9 , _______ , _______,
                                    _______ , KC_LSFT , KC_LGUI ,     KC_SPC   , KC_ENT , MO(4)
),

//        ┌──────┬────┬────┬───────┬──────┬──────┐   ┌─────┬─────┬─────┬───┬───┬──────┐
//        │ tab  │ !  │ @  │   #   │  $   │  %   │   │  ^  │  &  │  *  │ ( │ ) │ bspc │
//        ├──────┼────┼────┼───────┼──────┼──────┤   ├─────┼─────┼─────┼───┼───┼──────┤
//        │ lctl │ no │ no │  no   │  no  │  no  │   │  -  │  =  │  [  │ ] │ \ │  `   │
//        ├──────┼────┼────┼───────┼──────┼──────┤   ├─────┼─────┼─────┼───┼───┼──────┤
//        │ lctl │ no │ no │  no   │  no  │  no  │   │  _  │  +  │  {  │ } │ | │  ~   │
//        └──────┴────┴────┼───────┼──────┼──────┤   ├─────┼─────┼─────┼───┴───┴──────┘
//                         │ MO(4) │ lsft │ lgui │   │ spc │ ent │     │
//                         └───────┴──────┴──────┘   └─────┴─────┴─────┘
[_SYMBOL] = LAYOUT_split_3x6_3(
      KC_TAB  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC,
      KC_LCTL , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS , KC_GRV ,
      KC_LCTL , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                    MO(4)   , KC_LSFT , KC_LGUI ,     KC_SPC  , KC_ENT  , _______
),

//        ┌─────────┬────────┬────────┬─────┬──────┬──────┐   ┌──────────┬──────────────┬────────────────┬───────────┬────┬────┐
//        │ QK_BOOT │ PDF(0) │ PDF(1) │ no  │  no  │  no  │   │    no    │ kB_VOLUME_UP │ kB_VOLUME_DOWN │  kB_MUTE  │ no │ no │
//        ├─────────┼────────┼────────┼─────┼──────┼──────┤   ├──────────┼──────────────┼────────────────┼───────────┼────┼────┤
//        │   no    │   no   │   no   │ no  │  no  │  no  │   │   left   │     down     │       up       │   rght    │ no │ no │
//        ├─────────┼────────┼────────┼─────┼──────┼──────┤   ├──────────┼──────────────┼────────────────┼───────────┼────┼────┤
//        │   no    │   no   │   no   │ no  │  no  │  no  │   │ DSK_LEFT │      no      │       no       │ DSK_RIGHT │ no │ no │
//        └─────────┴────────┴────────┼─────┼──────┼──────┤   ├──────────┼──────────────┼────────────────┼───────────┴────┴────┘
//                                    │     │ lsft │ lgui │   │   spc    │     ent      │                │
//                                    └─────┴──────┴──────┘   └──────────┴──────────────┴────────────────┘
[_NAV] = LAYOUT_split_3x6_3(
      QK_BOOT , PDF(0)  , PDF(1)  , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX  , KC_KB_VOLUME_UP , KC_KB_VOLUME_DOWN , KC_KB_MUTE , XXXXXXX , XXXXXXX,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_LEFT  , KC_DOWN         , KC_UP             , KC_RIGHT   , XXXXXXX , XXXXXXX,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     DSK_LEFT , XXXXXXX         , XXXXXXX           , DSK_RIGHT  , XXXXXXX , XXXXXXX,
                                    _______ , KC_LSFT , KC_LGUI ,     KC_SPC   , KC_ENT          , _______
)
};

#ifdef OLED_ENABLE
bool oled_task_user(void){
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _COLMAK:
            oled_write_P(PSTR("COLMAK\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUM\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("SYMBOLS\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    return false;
}
#endif /* ifdef OLED_ENABLED */
