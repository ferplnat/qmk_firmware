/*
Copyright 2020 Bryan Ong

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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_alice_split_bs(
        KC_GRV,    QK_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,        KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_BSPC,    KC_BSPC,
        KC_HOME,   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,      KC_LBRC,    KC_RBRC,    KC_BSLS,
        KC_END,    KC_RCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN,   KC_QUOT,    KC_ENT,
                   SC_LSPO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,    KC_SLSH,    SC_RSPC,    KC_LGUI,
                   KC_LCTL,                     KC_LALT, KC_SPC,  KC_RCTL,                       KC_SPC,  KC_RALT,                                             MO(_FN)
        ),
    [_FN] = LAYOUT_alice_split_bs(
        LSG(KC_S), _______,   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,    _______,     _______,     _______,   _______,
        BS_TOGG,   _______,   _______, _______, _______, _______, _______,                       _______, _______, _______,    _______,     _______,     _______,   _______,    _______,
        QK_BOOT,   _______,   _______, _______, _______, _______, _______,                       _______, _______, _______,    _______,     _______,     _______,   _______,
                   _______,   _______, _______, _______, _______, _______,                       _______, _______, _______,    RCS(KC_TAB), RCTL(KC_TAB),_______,   _______,    _______,
                   _______,                     _______, _______, _______,                       _______, _______,                                                  _______
        ),
};

uint8_t mod_state;
bool process_rctl_override(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    if ((mod_state & MOD_BIT(KC_RCTL)) != MOD_BIT(KC_RCTL)) {
        return true;
    }

    if (record->event.pressed) {
        del_mods(MOD_MASK_CTRL);
        register_code(keycode);
        set_mods(mod_state);

        // Stop further processing
        return false;
    } else {
        unregister_code(keycode);
        // Stop further processing
        return false;
    }
}

bool space_mins_on_caps_word(keyrecord_t *record) {
    if (!is_caps_word_on()) {
        return true;
    }

    if (record->event.pressed) {
        add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key
        register_code(KC_MINS);
        return false;
    } else {
        unregister_code(KC_MINS);
        return false;
    }
}

bool override_toggle_caps_word(void) {
    if (get_mods() != MOD_BIT(KC_RCTL)) {
        return true;
    }

    caps_word_toggle();
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
    // Other keys Overrides //
    case KC_SPC:
        return space_mins_on_caps_word(record);
    case KC_ENT:
        return process_rctl_override(KC_ESC, record);
    case KC_BSPC:
        return process_rctl_override(KC_DEL, record);
    // -- //

    // Support Space Cadet shift and regular shift //
    case KC_LSFT:
        return override_toggle_caps_word();
    case SC_LSPO:
        return override_toggle_caps_word();
    case KC_RSFT:
        return override_toggle_caps_word();
    case SC_RSPC:
        return override_toggle_caps_word();
    // -- //

    // QWERTY Overrides //
    case KC_I:
        return process_rctl_override(KC_HOME, record);
    case KC_O:
        return process_rctl_override(KC_END, record);
    case KC_H:
        return process_rctl_override(KC_LEFT, record);
    case KC_J:
        return process_rctl_override(KC_DOWN, record);
    case KC_K:
        return process_rctl_override(KC_UP, record);
    case KC_L:
        return process_rctl_override(KC_RGHT, record);
    // -- //

    // F-Row Overrides //
    case QK_GESC:
        if (is_caps_word_on()) {
            caps_word_toggle();
            return false;
        }
        return process_rctl_override(KC_GRV, record);
    case KC_1:
        return process_rctl_override(KC_F1, record);
    case KC_2:
        return process_rctl_override(KC_F2, record);
    case KC_3:
        return process_rctl_override(KC_F3, record);
    case KC_4:
        return process_rctl_override(KC_F4, record);
    case KC_5:
        return process_rctl_override(KC_F5, record);
    case KC_6:
        return process_rctl_override(KC_F6, record);
    case KC_7:
        return process_rctl_override(KC_F7, record);
    case KC_8:
        return process_rctl_override(KC_F8, record);
    case KC_9:
        return process_rctl_override(KC_F9, record);
    case KC_0:
        return process_rctl_override(KC_F10, record);
    case KC_MINS:
        return process_rctl_override(KC_F11, record);
    case KC_EQL:
        return process_rctl_override(KC_F12, record);
    // -- //
    }
    return true;
};
