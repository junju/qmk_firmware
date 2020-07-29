#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _FN,
    _ADJUST,
};

/*enum custom_keycodes {
  RGB_RST = SAFE_RANGE
};*/

enum custom_keycodes { JP = SAFE_RANGE, US, UBUNTU, MAC, SHIFT, LOWER, RAISE, ADJUST, CSTM_0, CSTM_1, CSTM_2, CSTM_3, CSTM_4, CSTM_5, CSTM_6, CSTM_7, CSTM_8, CSTM_9, CIRC, AT, LBRC, RBRC, BSLS, AMPR, QUOT, LPRN, RPRN, EQL, TILD, PIPE, GRV, LCBR, PLUS, ASTR, RCBR, UNDS, MINS, SCLN, COMM, DOT, SLSH, EXLM, HASH, DLR, PERC, DEL, DESKDN, DESKUP, RGB_RST };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_QWERTY] = LAYOUT(
                                                                  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
                                                                  KC_ESC, CSTM_1, CSTM_2, CSTM_3, CSTM_4, CSTM_5, CSTM_6, CSTM_7, CSTM_8, CSTM_9, CSTM_0, KC_MINS, KC_EQL, GRV, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
                                                                  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
                                                                  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                                                                  SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SHIFT, MO(_FN),
                                                                  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_LCTRL, KC_LALT, KC_SPC, MO(_FN), KC_SPC, KC_RGUI, KC_UP, KC_DOWN
                                                                  //`---------------------------------------------|   |--------------------------------------------'
                                                                  ),

                                                              [_FN] = LAYOUT(
                                                                  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
                                                                  TG(_ADJUST), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
                                                                  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
                                                                  _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, _______, KC_PSCR, KC_SLCK, KC_PAUSE, KC_UP, _______, KC_BSPC,
                                                                  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
                                                                  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                                                                  _______, _______, _______, _______, _______, _______, _______, _______, KC_END, KC_PGDN, KC_DOWN, _______, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                                                                  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RIGHT
                                                                  //`---------------------------------------------|   |--------------------------------------------'
                                                                  ),

                                                              [_ADJUST] = LAYOUT(/* Base */
                                                                                 //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
                                                                                 TG(_ADJUST), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
                                                                                 //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
                                                                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                                 //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
                                                                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                                 //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                                                                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,
                                                                                 //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                                                                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_STOP, XXXXXXX
                                                                                 //`---------------------------------------------|   |--------------------------------------------'
                                                                                 )};

// A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
        case _FN:
            rgblight_set_effect_range(1, RGBLED_NUM-1);
            rgblight_sethsv_noeeprom(HSV_BLUE);
            // rgblight_disable();
            break;
        case _ADJUST:
            rgblight_set_effect_range(1, RGBLED_NUM-1);
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        default:  //  for any other layers, or the default layer
            // rgblight_enable();
            rgblight_set_effect_range(1, RGBLED_NUM-1);
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
    }
#endif
    return state;
}

#define JP_LAYOUT true
#define US_LAYOUT false
bool LAYOUT_STATUS = JP_LAYOUT;
bool SHIFT_PRESSED = false;

#define SEND_STRING_RESTORE(STR) (SHIFT_PRESSED ? SEND_STRING(STR SS_DOWN(X_LSHIFT)) : SEND_STRING(STR SS_UP(X_LSHIFT)))

#define KEY(CODE) (record->event.pressed ? SEND_STRING(SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define KEY_SHIFT(CODE) (record->event.pressed ? SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define KEY_UPSHIFT(CODE) (record->event.pressed ? SEND_STRING(SS_UP(X_LSHIFT) SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define SHIFT_DU(CODE_DOWN, CODE_UP) (SHIFT_PRESSED ? CODE_DOWN : CODE_UP)

#define CASE_US(CODE, US, JP)                   \
    case CODE:                                  \
        (LAYOUT_STATUS == JP_LAYOUT ? JP : US); \
        return false;

int RGB_current_mode;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // bool result = false;
    switch (keycode) {
        CASE_US(CSTM_0, KEY(0), SHIFT_DU(KEY_SHIFT(9), KEY(0)));
        CASE_US(CSTM_1, KEY(1), KEY(1));
        CASE_US(CSTM_2, KEY(2), SHIFT_DU(KEY_UPSHIFT(LBRACKET), KEY(2)));
        CASE_US(CSTM_3, KEY(3), KEY(3));
        CASE_US(CSTM_4, KEY(4), KEY(4));
        CASE_US(CSTM_5, KEY(5), KEY(5));
        CASE_US(CSTM_6, KEY(6), SHIFT_DU(KEY_UPSHIFT(EQUAL), KEY(6)));
        CASE_US(CSTM_7, KEY(7), SHIFT_DU(KEY_SHIFT(6), KEY(7)));
        CASE_US(CSTM_8, KEY(8), SHIFT_DU(KEY_SHIFT(QUOTE), KEY(8)));
        CASE_US(CSTM_9, KEY(9), SHIFT_DU(KEY_SHIFT(8), KEY(9)));
        CASE_US(DEL, KEY(DELETE), KEY_UPSHIFT(BSPACE));
        CASE_US(TILD, KEY_SHIFT(GRAVE), KEY_SHIFT(EQUAL));
        CASE_US(EXLM, KEY_SHIFT(1), KEY_SHIFT(1));
        CASE_US(AT, KEY_SHIFT(2), KEY(LBRACKET));
        CASE_US(HASH, KEY_SHIFT(3), KEY_SHIFT(3));
        CASE_US(DLR, KEY_SHIFT(4), KEY_SHIFT(4));
        CASE_US(PERC, KEY_SHIFT(5), KEY_SHIFT(5));
        CASE_US(CIRC, KEY_SHIFT(6), KEY(EQUAL));
        CASE_US(AMPR, KEY_SHIFT(7), KEY_SHIFT(6));
        CASE_US(ASTR, KEY_SHIFT(8), KEY_SHIFT(QUOTE));
        CASE_US(LPRN, KEY_SHIFT(9), KEY_SHIFT(8));
        CASE_US(RPRN, KEY_SHIFT(0), KEY_SHIFT(9));
        CASE_US(KC_LBRC, KEY(LBRACKET), SHIFT_DU(KEY_SHIFT(RBRACKET), KEY(RBRACKET)));
        CASE_US(KC_RBRC, KEY(RBRACKET), SHIFT_DU(KEY_SHIFT(NONUS_HASH), KEY(NONUS_HASH)));
        CASE_US(LCBR, KEY_SHIFT(LBRACKET), KEY_SHIFT(RBRACKET));
        CASE_US(RCBR, KEY_SHIFT(RBRACKET), KEY_SHIFT(NONUS_HASH));
        CASE_US(GRV, KEY(GRAVE), SHIFT_DU(KEY_SHIFT(EQUAL), KEY_SHIFT(LBRACKET)));
        CASE_US(KC_BSLS, KEY(BSLASH), SHIFT_DU(KEY_SHIFT(INT3), KEY(INT3)));
        // CASE_US(PIPE, KEY_SHIFT(BSLASH), KEY_SHIFT(INT3));
        CASE_US(KC_MINS, KEY(MINUS), SHIFT_DU(KEY_SHIFT(INT1), KEY(MINUS)));
        // CASE_US(UNDS, KEY_SHIFT(MINUS), KEY_SHIFT(INT1));
        CASE_US(KC_EQL, KEY(EQUAL), SHIFT_DU(KEY_SHIFT(SCOLON), KEY_SHIFT(MINUS)));
        // CASE_US(KC_PLUS, KEY_SHIFT(EQUAL), KEY_SHIFT(SCOLON));
        CASE_US(KC_SCLN, KEY(SCOLON), SHIFT_DU(KEY_UPSHIFT(QUOTE), KEY(SCOLON)));
        CASE_US(KC_QUOT, KEY(QUOTE), SHIFT_DU(KEY_SHIFT(2), KEY_SHIFT(7)));
#ifdef RGBLIGHT_ENABLE
        case RGB_MOD:
            if (record->event.pressed) {
                rgblight_mode(RGB_current_mode);
                rgblight_step();
                RGB_current_mode = rgblight_config.mode;
            }
            break;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
            }
            break;
#endif
        case JP:
            if (record->event.pressed) {
                LAYOUT_STATUS = JP_LAYOUT;
            }
            return false;
            break;
        case US:
            if (record->event.pressed) {
                LAYOUT_STATUS = US_LAYOUT;
            }
            return false;
            break;
            /*        case UBUNTU:
                        if (record->event.pressed) {
                            MACHINE_MODE = UBUNTU_MODE;
                        }
                        return false;
                        break;
                    case MAC:
                        if (record->event.pressed) {
                            MACHINE_MODE = MAC_MODE;
                        }
                        return false;
                        break;
                    case DESKDN:
                        if (record->event.pressed) {
                            if (MACHINE_MODE == UBUNTU_MODE) {
                                register_code(KC_LGUI);
                                tap_code(KC_PGDN);
                                unregister_code(KC_LGUI);
                            } else {
                                register_code(KC_LCTL);
                                tap_code(KC_LEFT);
                                unregister_code(KC_LCTL);
                            }
                        }
                        return false;
                        break;
                    case DESKUP:
                        if (record->event.pressed) {
                            if (MACHINE_MODE == UBUNTU_MODE) {
                                register_code(KC_LGUI);
                                tap_code(KC_PGUP);
                                unregister_code(KC_LGUI);
                            } else {
                                register_code(KC_LCTL);
                                tap_code(KC_RIGHT);
                                unregister_code(KC_LCTL);
                            }
                        }
                        return false;
                        break;*/
        case SHIFT:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSHIFT));
                SHIFT_PRESSED = true;
            } else {
                SEND_STRING(SS_UP(X_LSHIFT));
                SHIFT_PRESSED = false;
            }
            return false;
            break;
            /*case LOWER:
                if (record->event.pressed) {
                    layer_on(_LOWER);
                } else {
                    layer_off(_LOWER);
                }
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                return false;
                break;
            case RAISE:
                if (record->event.pressed) {
                    layer_on(_RAISE);
                } else {
                    layer_off(_RAISE);
                }
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                return false;
                break;
            case ADJUST:
                if (record->event.pressed) {
                    layer_on(_ADJUST);
                } else {
                    layer_off(_ADJUST);
                }
                return false;
                break;
            default:
                result = true;
                break;*/
    }

    return true;
}