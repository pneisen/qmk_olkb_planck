#include QMK_KEYBOARD_H

enum planck_layers { _BASE, _LOWER, _RAISE, _FN };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | FN   |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    KC_LCTL, KC_LGUI, KC_LALT, FN,      LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   *  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   /  |   1  |   2  |   3  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |   0  |   .  |   =  |      |
 * `-----------------------------------------------------------------------------------'
 */
 [_LOWER] = LAYOUT_planck_grid(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_BSPC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR,  KC_4,     KC_5,    KC_6,     KC_MINS,  XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH,  KC_1,     KC_2,    KC_3,     KC_PLUS,  RSFT_T(KC_ENT),
    _______, XXXXXXX, _______, _______, _______, KC_SPC,  KC_SPC,   _______,  KC_0,    KC_DOT,   KC_EQL,   XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   ~  |   /  |   {  |   [  |   ]  |   }  |   \  |   -  |   =  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   _  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
*/
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,   KC_EXLM, KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    XXXXXXX,  XXXXXXX, KC_TILD,  KC_SLSH,  KC_LCBR,  KC_LBRC,  KC_RBRC,  KC_RCBR, KC_BSLS, KC_MINS, KC_EQL,  KC_PIPE,
    XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, RSFT_T(KC_ENT),
    _______,  XXXXXXX, _______,  _______,  _______,  KC_SPC,   KC_SPC,   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* fn
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Sleep |      |  F11 |  F12 | Mute | Vol- |Vol + | Next |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | Calc |      | Boot |      |      |      |      |  Up  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      | Ctrl | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
*/
[_FN] = LAYOUT_planck_grid(
    XXXXXXX,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    XXXXXXX,  XXXXXXX, KC_SLEP, XXXXXXX, KC_F11,   KC_F12,   KC_MUTE,  KC_VOLD, KC_VOLU, KC_MPLY, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX,  QK_BOOT,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   RSFT_T(KC_ENT),
    XXXXXXX,  _______, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,   KC_SPC,   XXXXXXX, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
),

/* clang-format on */
};
