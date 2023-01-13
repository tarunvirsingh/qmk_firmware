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
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

// clang-format off

enum layers {
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _NUM,
    _SY1,
    _SY2,
    _NV0, // base
    _NV1, // cmd
    _NV2, // shift
    _NV3, // cmd+shift
    _BRC,
    _SCS
};

// currently max layers has been set to 12 in q4/config.h. Increase if needed

// Layer Taps
#define NUM_SPC LT(_NUM, KC_SPC)
#define SY1_D LT(_SY1, KC_D)
#define SY2_S LT(_SY2, KC_S)
#define BRC_F LT(_BRC, KC_F)
#define NV0_E LT(_NV0, KC_E)
#define NV1_R LT(_NV1, KC_R)
#define NV2_V LT(_NV2, KC_V)
#define NV3_C LT(_NV3, KC_C)
#define SCS_G LT(_SCS, KC_G)

// Left-hand home row mods
// #define GUI_F LGUI_T(KC_F)
// #define SFT_D LSFT_T(KC_D)
// #define CTL_S LCTL_T(KC_S)

// Right-hand home row mods
// #define GUI_J RGUI_T(KC_J)
// #define SFT_K RSFT_T(KC_K)
#define CTL_L RCTL_T(KC_L)

// Navigation
#define S_LEFT S(KC_LEFT)
#define S_RGHT S(KC_RIGHT)
#define S_UP S(KC_UP)
#define S_DOWN S(KC_DOWN)

#define C_LEFT G(KC_LEFT)
#define C_RGHT G(KC_RIGHT)
#define C_UP G(KC_UP)
#define C_DOWN G(KC_DOWN)

#define CS_LEFT LSG(KC_LEFT)
#define CS_RGHT LSG(KC_RIGHT)
#define CS_UP LSG(KC_UP)
#define CS_DOWN LSG(KC_DOWN)

// Shortcuts
#define CS_M LSG(KC_M)
#define CS_P LSG(KC_P)
#define CS_LCBR LSG(KC_LBRC)
#define CS_RCBR LSG(KC_RBRC)
#define C_GRV G(KC_GRV)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    NV0_E,   NV1_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        _______, KC_A,     SY2_S,   SY1_D,   BRC_F,   SCS_G,   KC_H,    KC_J,    KC_K,    CTL_L,   KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    NV3_C,   NV2_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LOPTN, KC_LCMMD,                           NUM_SPC,                            KC_RCMMD, KC_1,     MO(_FN1), KC_RCTL),

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

    [_NUM] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_GRV,  KC_1,    KC_2,    KC_3,    _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, KC_0,    KC_7,    KC_8,    KC_9,     _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_SY1] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, KC_UNDS, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, KC_EQL,  KC_MINS, KC_PLUS, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_SY2] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_PIPE, KC_DLR,  KC_PERC, KC_CIRC, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, KC_BSLS, KC_AMPR, KC_ASTR, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_NV0] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_NV1] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, C_UP,    _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_BSPC, C_LEFT,  C_DOWN,  C_RGHT,  _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_NV2] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, S_UP,    _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_BSPC, S_LEFT,  S_DOWN,  S_RGHT, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_NV3] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, CS_UP,   _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_BSPC, CS_LEFT, CS_DOWN, CS_RGHT, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),
    [_BRC] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, KC_GRV,  KC_LBRC, KC_RBRC, _______, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_SCS] = LAYOUT_ansi_61(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, CS_LCBR, CS_RCBR, _______, CS_P,     _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, C_GRV,   _______, _______, _______, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, _______, CS_M,    _______, _______,  _______,            _______,
        _______, _______,  _______,                            KC_BTN1,                            _______,  _______,  _______,  _______)


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
