/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

/*
 * To flash new keymap:
 * Compile binary for the new keymap. Run the following from ~/tarunvirsingh/qmk_firmware directory:
 *   qmk compile -kb keychron/q4/q4_rev2_ansi_stm32l432 -km keychron
 * Put keyboard in bootloader mode by pressing fn1+ctrl (I.e. press QK_BOOT from _FN1 layer)
 * Flash the new binary on to the keyboard using QMK toolbox
 * Reset EEPROM using fn1+option (I.e. press EE_CLR from _FN1 layer)
 * The keyboard is ready to use.
 * You may now press fn1+tab to turn off the lighting.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

// clang-format off

enum layers {
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _BRC,
    _SYM,
    _NUM,
    _SCS,
    _NAV
};

// currently max layers has been set to 10 in q4/config.h. Increase if needed

// Layer Taps
#define BRC_S LT(_BRC, KC_S)
#define SYM_D LT(_SYM, KC_D)
#define NUM_F LT(_NUM, KC_F)
#define SCS_G LT(_SCS, KC_G)
#define NAV_SPC LT(_NAV, KC_SPC)
// Note that LM (which enables a layer with modifiers on, can not be achieved with a tap
// To do that, you add an LT, and specify one convenient key on that layer as the mod
// Eg. tap into sym layer with D, and use F as cmd.
// Or the other option is to use the cmd+sft that I use in the _SCS layer

// Right-hand home row mods
#define CTL_L RCTL_T(KC_L)

// Shortcuts
#define CS_I LSG(KC_I)
#define CS_M LSG(KC_M)
#define CS_P LSG(KC_P)
#define CS_LCBR LSG(KC_LBRC)
#define CS_RCBR LSG(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_61(
        KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_ESC,  KC_A,     BRC_S,   SYM_D,   NUM_F,   SCS_G,   KC_H,    KC_J,    KC_K,    CTL_L,   KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LOPTN, KC_LCMMD,                           NAV_SPC,                            KC_RCMMD, KC_1,     MO(_FN1), KC_RCTL),

    [WIN_BASE] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LWIN,  KC_LALT,                            KC_SPC,                             KC_RALT,  _______,  MO(_FN1), KC_RCTL),

    [_FN1] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        RGB_TOG, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, DT_UP,    DT_PRNT, DT_DOWN, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        QK_BOOT, EE_CLR,   _______,                            _______,                            _______,  _______,  _______,  _______),

    [_BRC] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_EQL,  KC_LBRC, KC_RBRC, _______, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_SYM] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_TILD, KC_AMPR, KC_ASTR, KC_TAB,  KC_PIPE,  _______,  _______,  _______,
        _______, _______,  _______, _______, KC_LCMD, _______, KC_UNDS, KC_DLR,  KC_PERC, KC_CIRC, KC_BSLS,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, KC_GRV,  KC_EXLM, KC_AT,   KC_HASH,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_NUM] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, KC_ASTR, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_DOT,  KC_7,    KC_8,    KC_9,    KC_PLUS,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_MINS,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,     KC_SLSH,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_SCS] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, TVSUSER, CS_I,    _______, CS_P,     _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, CS_LCBR, _______, _______, CS_RCBR, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, CS_M,    _______, _______,  _______,            _______,
        _______, _______,  _______,                            KC_BTN1,                            _______,  _______,  _______,  _______),

    [_NAV] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  KC_LOPT, KC_LSFT, KC_LCMD, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______)

};

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (!dip_switch_update_keychron(index, active)) {
        return false;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keychron(led_min, led_max)) {
        return false;
    }
    return true;
}
#endif // RGB_MATRIX_ENABLE
