 /* Copyright 2021 Caleb Lightfoot
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H

enum custom_keycodes {
    YEEHAW = SAFE_RANGE,
    SQUASHKB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
         KC_VOLU,
         KC_VOLD,
         KC_MPRV, YEEHAW, KC_UP, SQUASHKB,
 MO(1), KC_MNXT, KC_LEFT, KC_DOWN, KC_RIGHT,
        KC_MPLY, LCTL(KC_S),
             UG_TOGG
    ),

     [1] = LAYOUT(
        UG_HUEU,
        UG_HUED,
        UG_SATU, UG_VALU, UG_VALD, UG_SPDU,
KC_TRNS, UG_SATD, RGB_M_P, UG_NEXT, UG_SPDD,
        KC_TRNS, KC_TRNS,
             QK_BOOT
    ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case YEEHAW:
        if (record->event.pressed) {
            SEND_STRING("yeehaw!");
        }
        break;

    case SQUASHKB:
        if (record->event.pressed) {
            SEND_STRING("https://squashkb.com");
        }
        break;
    }
    return true;
};
