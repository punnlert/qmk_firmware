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
    _FIGMA
};

#define _DEFAULT_LAYER_1 FIRST_DEFAULT_LAYER
#define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 1)
#if LAST_DEFAULT_LAYER > (FIRST_DEFAULT_LAYER + 1)
#    define _DEFAULT_LAYER_2 (FIRST_DEFAULT_LAYER + 2)
#endif

enum custom_keycodes {
    DSK_LEFT = SAFE_RANGE,
    DSK_RIGHT,
    SCRN_CAP,
    BRW_BACK,
    BRW_FORWARD
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DSK_LEFT:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL));
        } else {
        }
        break;

    case DSK_RIGHT:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL));
        } else {
        }
        break;
    case SCRN_CAP:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) "4" SS_UP(X_LGUI)SS_UP(X_LSFT));
        } else {
        }
        break;
    case BRW_BACK:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL));
        } else {
        }
        break;
    case BRW_FORWARD:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) "4" SS_UP(X_LGUI)SS_UP(X_LSFT));
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬───────────┬───────────┬──────┬──────────┐   ┌───────────────────┬─────┬───────────┬───────────┬───┬──────┐
//    │ tab  │ q │     w     │     e     │  r   │    t     │   │         y         │  u  │     i     │     o     │ p │ bspc │
//    ├──────┼───┼───────────┼───────────┼──────┼──────────┤   ├───────────────────┼─────┼───────────┼───────────┼───┼──────┤
//    │ esc  │ a │ LCTL_T(s) │ LGUI_T(d) │  f   │    g     │   │         h         │  j  │ RGUI_T(k) │ RCTL_T(l) │ ; │  '   │
//    ├──────┼───┼───────────┼───────────┼──────┼──────────┤   ├───────────────────┼─────┼───────────┼───────────┼───┼──────┤
//    │ lalt │ z │     x     │     c     │  v   │    b     │   │         n         │  m  │     ,     │     .     │ / │  =   │
//    └──────┴───┴───────────┼───────────┼──────┼──────────┤   ├───────────────────┼─────┼───────────┼───────────┴───┴──────┘
//                           │   lgui    │ lsft │ MO(_NUM) │   │ LT(_SYMBOL, bspc) │ spc │    ent    │
//                           └───────────┴──────┴──────────┘   └───────────────────┴─────┴───────────┘
[_DEFAULT_LAYER_1] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_Q , KC_W         , KC_E         , KC_R    , KC_T     ,     KC_Y                 , KC_U   , KC_I         , KC_O         , KC_P    , KC_BSPC ,
  KC_ESC  , KC_A , LCTL_T(KC_S) , LGUI_T(KC_D) , KC_F    , KC_G     ,     KC_H                 , KC_J   , RGUI_T(KC_K) , RCTL_T(KC_L) , KC_SCLN , KC_QUOT ,
  KC_LALT , KC_Z , KC_X         , KC_C         , KC_V    , KC_B     ,     KC_N                 , KC_M   , KC_COMM      , KC_DOT       , KC_SLSH , KC_EQUAL,
                                  KC_LGUI      , KC_LSFT , MO(_NUM) ,     LT(_SYMBOL, KC_BSPC) , KC_SPC , KC_ENT
),

//    ┌──────┬───┬───────────┬───────────┬──────┬──────────┐   ┌───────────────────┬─────┬───────────┬───────────┬───┬──────┐
//    │ tab  │ q │     w     │     f     │  p   │    b     │   │         j         │  l  │     u     │     y     │ ; │ bspc │
//    ├──────┼───┼───────────┼───────────┼──────┼──────────┤   ├───────────────────┼─────┼───────────┼───────────┼───┼──────┤
//    │ esc  │ a │ LCTL_T(r) │ LGUI_T(s) │  t   │    g     │   │         m         │  n  │ RGUI_T(e) │ RCTL_T(i) │ o │  '   │
//    ├──────┼───┼───────────┼───────────┼──────┼──────────┤   ├───────────────────┼─────┼───────────┼───────────┼───┼──────┤
//    │ lalt │ z │     x     │     c     │  d   │    v     │   │         k         │  h  │     ,     │     .     │ / │  =   │
//    └──────┴───┴───────────┼───────────┼──────┼──────────┤   ├───────────────────┼─────┼───────────┼───────────┴───┴──────┘
//                           │   lgui    │ lsft │ MO(_NUM) │   │ LT(_SYMBOL, bspc) │ spc │    ent    │
//                           └───────────┴──────┴──────────┘   └───────────────────┴─────┴───────────┘
[_DEFAULT_LAYER_2] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_Q , KC_W         , KC_F         , KC_P    , KC_B     ,     KC_J                 , KC_L   , KC_U         , KC_Y         , KC_SCLN , KC_BSPC ,
  KC_ESC  , KC_A , LCTL_T(KC_R) , LGUI_T(KC_S) , KC_T    , KC_G     ,     KC_M                 , KC_N   , RGUI_T(KC_E) , RCTL_T(KC_I) , KC_O    , KC_QUOT ,
  KC_LALT , KC_Z , KC_X         , KC_C         , KC_D    , KC_V     ,     KC_K                 , KC_H   , KC_COMM      , KC_DOT       , KC_SLSH , KC_EQUAL,
                                  KC_LGUI      , KC_LSFT , MO(_NUM) ,     LT(_SYMBOL, KC_BSPC) , KC_SPC , KC_ENT
),

//    ┌─────┬─────┬─────┬──────┬──────┬──────────┐   ┌──────────┬─────┬─────┬───┬─────┬─────┐
//    │     │     │     │      │      │ SCRN_CAP │   │    =     │  1  │  2  │ 3 │     │     │
//    ├─────┼─────┼─────┼──────┼──────┼──────────┤   ├──────────┼─────┼─────┼───┼─────┼─────┤
//    │     │     │     │ btn1 │ btn2 │          │   │    0     │  4  │  5  │ 6 │     │     │
//    ├─────┼─────┼─────┼──────┼──────┼──────────┤   ├──────────┼─────┼─────┼───┼─────┼─────┤
//    │     │     │     │ ent  │ lgui │   lalt   │   │    -     │  7  │  8  │ 9 │  /  │     │
//    └─────┴─────┴─────┼──────┼──────┼──────────┤   ├──────────┼─────┼─────┼───┴─────┴─────┘
//                      │      │      │          │   │ MO(_NAV) │     │     │
//                      └──────┴──────┴──────────┘   └──────────┴─────┴─────┘
[_NUM] = LAYOUT_split_3x6_3(
  _______ , _______ , _______ , _______ , _______ , SCRN_CAP ,     KC_EQUAL , KC_1    , KC_2    , KC_3 , _______ , _______,
  _______ , _______ , _______ , KC_BTN1 , KC_BTN2 , _______  ,     KC_0     , KC_4    , KC_5    , KC_6 , _______ , _______,
  _______ , _______ , _______ , KC_ENT  , KC_LGUI , KC_LALT  ,     KC_MINUS , KC_7    , KC_8    , KC_9 , KC_SLSH , _______,
                                _______ , _______ , _______  ,     MO(_NAV) , _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬──────────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │  !  │  @  │  #  │  $  │    %     │   │  ^  │  &  │  *  │  (  │  )  │     │
//    ├─────┼─────┼─────┼─────┼─────┼──────────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  <  │  \  │  {  │  [  │    (     │   │  )  │  ]  │  }  │  /  │  >  │     │
//    ├─────┼─────┼─────┼─────┼─────┼──────────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │  `  │    ~     │   │  -  │  =  │  |  │     │     │     │
//    └─────┴─────┴─────┼─────┼─────┼──────────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
//                      │     │     │ MO(_NAV) │   │     │     │     │
//                      └─────┴─────┴──────────┘   └─────┴─────┴─────┘
[_SYMBOL] = LAYOUT_split_3x6_3(
  _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC  ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______,
  _______ , KC_LT   , KC_BSLS , KC_LCBR , KC_LBRC , KC_LPRN  ,     KC_RPRN , KC_RBRC , KC_RCBR , KC_SLSH , KC_GT   , _______,
  _______ , _______ , _______ , _______ , KC_GRV  , KC_TILD  ,     KC_MINS , KC_EQL  , KC_PIPE , _______ , _______ , _______,
                                _______ , _______ , MO(_NAV) ,     _______ , _______ , _______
),

//    ┌─────────┬──────────────┬───────────────┬─────┬───────────┬──────┐   ┌──────┬────────────────┬──────────────┬─────────┬─────┬─────────┐
//    │ QK_BOOT │ PDF(_QWERTY) │ PDF(_COLEMAK) │     │           │      │   │      │ kB_VOLUME_DOWN │ kB_VOLUME_UP │ kB_MUTE │     │ QK_BOOT │
//    ├─────────┼──────────────┼───────────────┼─────┼───────────┼──────┤   ├──────┼────────────────┼──────────────┼─────────┼─────┼─────────┤
//    │         │   DSK_LEFT   │               │     │ DSK_RIGHT │      │   │ left │      down      │      up      │  rght   │     │         │
//    ├─────────┼──────────────┼───────────────┼─────┼───────────┼──────┤   ├──────┼────────────────┼──────────────┼─────────┼─────┼─────────┤
//    │         │              │               │     │   lgui    │ lalt │   │      │                │              │         │     │         │
//    └─────────┴──────────────┴───────────────┼─────┼───────────┼──────┤   ├──────┼────────────────┼──────────────┼─────────┴─────┴─────────┘
//                                             │     │           │      │   │      │                │              │
//                                             └─────┴───────────┴──────┘   └──────┴────────────────┴──────────────┘
[_NAV] = LAYOUT_split_3x6_3(
  QK_BOOT , PDF(_QWERTY) , PDF(_COLEMAK) , _______ , _______   , _______ ,     _______ , KC_KB_VOLUME_DOWN , KC_KB_VOLUME_UP , KC_KB_MUTE , _______ , QK_BOOT,
  _______ , DSK_LEFT     , _______       , _______ , DSK_RIGHT , _______ ,     KC_LEFT , KC_DOWN           , KC_UP           , KC_RIGHT   , _______ , _______,
  _______ , _______      , _______       , _______ , KC_LGUI   , KC_LALT ,     _______ , _______           , _______         , _______    , _______ , _______,
                                           _______ , _______   , _______ ,     _______ , _______           , _______
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
