/* Copyright 2022 dztech kbdfans
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[0] = LAYOUT( /* Base */
		    KC_ESC, KC_TAB,    KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL,
		    KC_F2,  KC_CAPS,   KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,  KC_HOME,
		    KC_F3,  KC_LSFT,   KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,   KC_END,
		    KC_F4,  KC_LCTL,   KC_LALT,            MO(1),        KC_SPC,         KC_RALT, KC_RCTL,                   KC_LEFT,  KC_DOWN, KC_RIGHT),

		[1] = LAYOUT( /* Left SPC */
		    KC_ESC, KC_TAB,    KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL,
		    KC_F2,  KC_CAPS,   KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,  KC_HOME,
		    KC_F3,  KC_LSFT,   KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,   KC_END,
		    KC_F4,  KC_LCTL,   KC_LALT,            KC_SPC,       MO(2),          KC_RALT, KC_RCTL,                   KC_LEFT,  KC_DOWN, KC_RIGHT),
 };
