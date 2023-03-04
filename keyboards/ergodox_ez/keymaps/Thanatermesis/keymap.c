#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    SPECIAL, // special layer (combos)
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
    EPRM,
    EMOT_think,
    EMOT_eyes,
    EMOT_tongue,
    EMOT_monkm,
    EMOT_monke,
    EMOT_rofl1,
    EMOT_rofl2,
    EMOT_sung,
    EMOT_fire,
    EMOT_love,
    utf_a,
    utf_e,
    utf_i,
    utf_o,
    utf_u,
    utf_n,
    utf_c,
    bs_multi,
    lc_all_c,
    bash_devnull1,
    bash_devnull2,
    bash_devnull12,
    signature_niceday,
    donation_thx_important,
    signature_name,
    signature_email,
    signature_thankyou,
    signature_thx_support,
    website_elivecd,
    website_64bit_download,
    gui_selectline,
    arrowLm,
    arrowRm,
    arrowUm,
    arrowDm,
};

/*
Tap dance modes
enum {
    TD_LSHIFT,
    TD_RSHIFT,
};
*/

int repeat_amount_small = 3;
int repeat_amount_big = 8;
/*int mo_keys_pressed = 0*/

// needed to enable utf8/unicode, even if not used
const uint32_t PROGMEM unicode_map[] = {
};


// The most portable copy/paste keys (windows (mostly), linux, and some terminal emulators).
#define MK_CUT    LSFT(KC_DEL)  // shift + delete
#define MK_COPY   LCTL(KC_INS)  // ctrl + insert
#define MK_PASTE  LSFT(KC_INS)  // shift + insert

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

#define LED_BRIGHTNESS_LO       15
#define LED_BRIGHTNESS_MED1     30
#define LED_BRIGHTNESS_MED2     60
#define LED_BRIGHTNESS_MED3     100
#define LED_BRIGHTNESS_HI       255



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,   KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    LSFT(KC_6),             KC_EQUAL,       KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           LSFT(KC_SLASH),
  KC_TAB,   KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_PIPE,               LSFT(KC_SCOLON),  KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           LSFT(KC_1),
  KC_LCTRL, KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                            KC_H,    KC_J,    KC_K,    KC_L,              KC_SLASH,      MO(3),
  KC_LSFT,  KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    MO(3),                  LSFT(KC_MINUS), KC_N,    KC_M,   KC_COMMA, KC_DOT,         KC_MINUS,     KC_RSHIFT,
  SH_MON, LSFT(KC_COMMA), LSFT(KC_DOT),  LSFT(KC_GRAVE), KC_LALT,                                                   MO(1),   KC_SCOLON, KC_LBRC, KC_RBRACKET,       SH_MON,
                                                           bs_multi, MO(2),                KC_LGUI,   KC_RALT,
                                                                     OSL(3),               KC_RCTRL,
                                               MO(1), KC_BSPACE, KC_DELETE,                MO(2),  KC_ENTER, KC_SPACE
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  DF(0),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_GRAVE,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INSERT,
  KC_TRNS, KC_AT,   KC_AMPR, KC_PLUS, KC_DQUO, KC_QUOTE, KC_BSLS,     KC_TRNS, KC_PLUS, KC_PGUP, KC_HOME, KC_END,  KC_TRNS, KC_BSPACE,
  KC_TRNS, KC_ASTR, KC_DLR,  KC_LPRN, KC_RPRN,  KC_TRNS,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PLUS, KC_TRNS,
  KC_TRNS, KC_LCBR, KC_RCBR, KC_HASH, KC_PERC, KC_PIPE, KC_TRNS,      KC_TRNS, KC_TRNS, KC_PGDN,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                               KC_TRNS, KC_F11,      KC_F12, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NUMLOCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_MINUS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,   KC_PSCREEN, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS, KC_BSPACE,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_DELETE,
  KC_TRNS, KC_TRNS, MK_CUT,  MK_COPY, MK_PASTE, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_KP_0, KC_KP_0, KC_KP_DOT, KC_KP_ENTER, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),


// Special / Macros
[SPECIAL] = LAYOUT_ergodox_pretty(
  // left hand
  EMOT_think, EMOT_rofl1, EMOT_rofl2, EMOT_sung, EMOT_tongue, EMOT_eyes, EMOT_love,   lc_all_c, bash_devnull1, bash_devnull2, bash_devnull12, KC_TRNS, KC_TRNS, KC_TRNS,
  EMOT_monkm, EMOT_monke, EMOT_fire, utf_e, KC_TRNS, KC_TRNS, KC_TRNS,                signature_niceday, signature_email, utf_u, utf_i, utf_o, signature_thankyou, signature_thx_support,
  KC_TRNS, utf_a, gui_selectline, KC_TRNS, KC_TRNS, KC_TRNS,                                 arrowLm, arrowDm, arrowUm, arrowRm, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, utf_c, KC_TRNS, KC_TRNS, KC_TRNS,                        signature_name, utf_n, donation_thx_important, KC_TRNS, KC_TRNS, website_elivecd, website_64bit_download,
  RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};


// backport this needed macro from updated QMK code
#define QK_MOMENTARY_GET_LAYER(kc) ((kc)&0x1F)

uint8_t layer_keys_pressed[SPECIAL] = {0}; // macro to know the amount of keys pressed for MO layer switching
uint8_t layer = 0; // layer number


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
        case QK_MOMENTARY...QK_MOMENTARY_MAX: // any MO key
           layer = QK_MOMENTARY_GET_LAYER(keycode); // check which layer this MO affects

           // increase / decrease the amount of keys pressed to set a layer
           if (record->event.pressed) layer_keys_pressed[layer]++;
           else layer_keys_pressed[layer]--;

           // turn the layer on/off
           if (layer_keys_pressed[layer]) layer_on(layer);
           else layer_off(layer); // deactivate layer only if there's no more remainig keys pressed

           return false;
        case VRSN:
           SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
           return true;
           break;
        case EPRM:
           if (record->event.pressed) {
                eeconfig_init();
           }
           return false;
           break;
        // spanish keyboard keys:
        case utf_a:
           if (record->event.pressed) { send_unicode_string("á"); }
           return true;
           break;
        case utf_e:
           if (record->event.pressed) { send_unicode_string("é"); }
           return true;
           break;
        case utf_i:
           if (record->event.pressed) { send_unicode_string("í"); }
           return true;
           break;
        case utf_o:
           if (record->event.pressed) { send_unicode_string("ó"); }
           return true;
           break;
        case utf_u:
           if (record->event.pressed) { send_unicode_string("ú"); }
           return true;
           break;
        case utf_n:
           if (record->event.pressed) { send_unicode_string("ñ"); }
           return true;
           break;
        case utf_c:
           if (record->event.pressed) { send_unicode_string("ç"); }
           return true;
           break;

        // emoticons
        case EMOT_think:
           if (record->event.pressed) {
                send_unicode_string("🤔");
           }
           return true;
           break;
        case EMOT_eyes:
           if (record->event.pressed) {
                send_unicode_string("🙄");
           }
           return true;
           break;
        case EMOT_tongue:
           if (record->event.pressed) {
                send_unicode_string("😝");
           }
           return true;
           break;
        case EMOT_monkm:
           if (record->event.pressed) {
                send_unicode_string("🙊");
           }
           return true;
           break;
        case EMOT_monke:
           if (record->event.pressed) {
                send_unicode_string("🙈");
           }
           return true;
           break;
        case EMOT_rofl1:
           if (record->event.pressed) {
                send_unicode_string("😂");
           }
           return true;
           break;
        case EMOT_rofl2:
           if (record->event.pressed) {
                send_unicode_string("🤣");
           }
           return true;
           break;
        case EMOT_sung:
           if (record->event.pressed) {
                send_unicode_string("😎");
           }
           return true;
           break;
        case EMOT_love:
           if (record->event.pressed) {
                send_unicode_string("❤");
           }
           return true;
           break;
        case EMOT_fire:
           if (record->event.pressed) {
                send_unicode_string("🔥");
           }
           return true;
           break;
        case bs_multi:
           if (record->event.pressed) {
                for (int i = 0; i < repeat_amount_big; i++) {
                     /*SEND_STRING(SS_TAP(X_BSPACE) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE));*/
                     SEND_STRING(SS_TAP(X_BSPACE));
                }
           }
           return true;
           break;
        case lc_all_c:
           if (record->event.pressed) {
                SEND_STRING("LC_ALL=C");
           }

           return true;
           break;
        case bash_devnull1:
           if (record->event.pressed) {
                SEND_STRING("1>/dev/null");
           }
           return true;
           break;
        case bash_devnull2:
           if (record->event.pressed) {
                SEND_STRING("2>/dev/null");
           }
           return true;
           break;
        case bash_devnull12:
           if (record->event.pressed) {
                SEND_STRING("1>/dev/null 2>&1");
           }
           return true;
           break;
         case signature_niceday:
           if (record->event.pressed) {
                SEND_STRING("Thank you and have a beautiful day,\n");
           }
           return true;
           break;
         case donation_thx_important:
           if (record->event.pressed) {
                SEND_STRING("First thanks a lot for your donation, it is very important for the survival and progress of the project\n");
           }
           return true;
           break;
         case signature_name:
           if (record->event.pressed) {
                SEND_STRING("Thanatermesis");
           }
           return true;
           break;
         case signature_email:
           if (record->event.pressed) {
                SEND_STRING("thanatermesis@gmail.com");
           }
           return true;
           break;
         case signature_thankyou:
           if (record->event.pressed) {
                SEND_STRING("Thank you,\n");
           }
           return true;
           break;
         case signature_thx_support:
           if (record->event.pressed) {
                SEND_STRING("Thank you a lot for your support and have a beautiful day,\n");
           }
           return true;
           break;
         case website_elivecd:
           if (record->event.pressed) {
                SEND_STRING("https://www.elivecd.org");
           }
           return true;
           break;
         case website_64bit_download:
           if (record->event.pressed) {
                SEND_STRING("https://www.elivecd.org/donation/download-beta-gathjucsan/");
           }
           return true;
           break;
         case gui_selectline:
           if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSHIFT) SS_TAP(X_END) SS_UP(X_LSHIFT ));
           }
           return true;
           break;
         case arrowLm:
           if (record->event.pressed) {
                for (int i = 0; i < repeat_amount_big; i++) {
                     SEND_STRING(SS_TAP(X_LEFT));
                }
           }
           return true;
           break;
         case arrowRm:
           if (record->event.pressed) {
                for (int i = 0; i < repeat_amount_big; i++) {
                     SEND_STRING(SS_TAP(X_RIGHT));
                }
           }
           return true;
           break;
         case arrowUm:
           if (record->event.pressed) {
                for (int i = 0; i < repeat_amount_small; i++) {
                     SEND_STRING(SS_TAP(X_UP));
                }
           }
           return true;
           break;
         case arrowDm:
           if (record->event.pressed) {
                for (int i = 0; i < repeat_amount_small; i++) {
                     SEND_STRING(SS_TAP(X_DOWN));
                }
           }
           return true;
           break;

         default:
           return true;
           break;
     }
}


// Tap Dance definitions.
// Update: not working due to Vial mode?
/*qk_tap_dance_action_t tap_dance_actions[] = {*/
    /*// Tap once for Escape, twice for Caps Lock*/
    /*[TD_LSHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),*/
    /*[TD_RSHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_RSHIFT, KC_CAPS),*/
/*};*/



// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    // make the led status compatible with shift and numlock
    led_t led_state = host_keyboard_led_state();
    /*
    if(led_state.caps_lock) {
        ergodox_right_led_1_on();
    } else {
        //uint8_t layer = get_highest_layer(layer_state);
        //if(layer != 1) {
             ergodox_right_led_1_off();
        //}
    }
    */
    if(led_state.num_lock) {
        ergodox_right_led_2_on();
    } else {
        uint8_t layer = get_highest_layer(layer_state);
        if(layer != 2) {
             ergodox_right_led_2_off();
        }
    }
}



// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            //ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            ergodox_right_led_2_set(LED_BRIGHTNESS_MED1);
            break;
        case 3:
            /*ergodox_right_led_3_on();*/
            ergodox_right_led_1_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};


