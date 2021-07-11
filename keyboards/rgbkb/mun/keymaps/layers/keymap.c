#include QMK_KEYBOARD_H
// To exclude accents, set UNICODE_ENABLE = no in rules.mk

enum keymap_layers {
    _QWERTY,
    _COLEMAK,
    _GAME,
    _FN,
    _ADJUST,
    _ACCENTS,
    _OTHER,
    _RESET1,
    _RESET2,
    _RESET3,
};

enum keymap_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE
};

// Default Layers
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK)
#define GAME     DF(_GAME)

// Momentary Layers
#define FN       MO(_FN)
#define ADJUST   MO(_ADJUST)
#define ACCENTS  MO(_ACCENTS)
#define OTHER    MO(_OTHER)
#define RESET1   MO(_RESET1)
#define RESET2   MO(_RESET2)
#define RESET3   MO(_RESET3)

#define FN_CAPS  LT(_FN, KC_CAPS)
#define FN_ESC   LT(_FN, KC_ESC)

// French chars
enum unicode_names {
  EAIG,
  EAIG_M,
  EGRV,
  EGRV_M,
  ECRC,
  ECRC_M,
  ETRM,
  ETRM_M,
  OCRC,
  OCRC_M,
  AGRV,
  AGRV_M,
  CCDL,
  CCDL_M,
};

const uint32_t PROGMEM unicode_map[] = {
  [EAIG]  = 0x00E9,     // 0  é
  [EAIG_M] = 0x00C9,    // 1  É
  [EGRV]  = 0x00E8,     // 2  è
  [EGRV_M] = 0x00C8,    // 3  È
  [ECRC]  = 0x00EA,     // 4  ê
  [ECRC_M] = 0x00CA,    // 5  Ê
  [ETRM]  = 0x00EB,     // 6  ë
  [ETRM_M] = 0x00CB,    // 7  Ë
  [OCRC]  = 0x00F4,     // 8  ô
  [OCRC_M] = 0x00D4,    // 9  Ô
  [AGRV]  = 0x00E0,     // 10 Â
  [AGRV_M] = 0x00C0,    // 11 À
  [CCDL]  = 0x00E7,     // 12 ç
  [CCDL_M] = 0x00C7,    // 13 Ç
};



// initialize unicode mode
void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_WINC);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | `~/ESC | 1      | 2      | 3      | 4      | 5      |   -    |  |    =   | 6      | 7      | 8      | 9      | 0      | Bckspc |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Tab    | Q      | W      | E      | R      | T      |   [    |  |    ]   | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | FN/Caps| A      | S      | D      | F      | G      |   DN   |  |   UP   | H      | J      | K      | L      | :      | '      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Shift( | Z      | X      | C      | V      | B      |   (    |  |    )   | N      | M      | ,      | .      | /      | )Shift |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Ctrl   | Win    | Alt    | RGBTOG | FN     | Space  | Bksp   |  | Enter  | Space  | Space  | FN     | Alt    | Win    | Ctrl   |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     *      Encoder 1         Encoder 2                                                                  Encoder 3         Encoder 4
     * .-----------------------------------.                                                        .-----------------------------------.
     * | VolUp  | VolDn  | VolUp  | VolDn  |                                                        | PgUp   | PgDn   | PgUp   | PgDn   |
     * |--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
     * | VolDn  | VolUp  | Next   | Play   | Prev   | Touch Encoder          Touch Encoder | RgbHuI | RgbHuD | RgbMdD | RgbTog | RgbMdI |
     * '--------+--------+--------+--------+--------'                                      '--------+--------+--------+--------+--------'
     */
    [_QWERTY] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,   KC_EQL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,   KC_RBRC,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    ACCENTS,   OTHER,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN,   KC_RPRN,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
        KC_LCTL, KC_LGUI, KC_LALT, RGB_TOG, ADJUST,  KC_SPC,  KC_DEL,    KC_ENT,    KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_RCTL,

        KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD,                                                          KC_PGUP, KC_PGDN, KC_PGUP, KC_PGDN,
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                        RGB_HUI, RGB_HUD, RGB_RMOD,RGB_TOG, RGB_MOD
    ),

    [_COLEMAK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______, _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, KC_F1,   KC_F5,   _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F2,   KC_F6,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F3,   KC_F7,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F4,   KC_F8,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_PGUP,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, TCH_TOG, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, RESET,   _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, GAME,
        _______, RGB_RMOD,_______, RGB_MOD, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_NLCK, QWERTY, COLEMAK,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),
///*
/* ACCENTS (+ NUMPAD)
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * |        |        |        |        |        |        |        |  |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | 1      | 2      | 3      | ê Ê    | é É    |        |  |        | é É    | ê Ê    | 1      | 2      | 3      |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | 4      | 5      | 6      | ô Ô    | è È    |   XX   |  |   XX   | è È    | ô Ô    | 4      | 5      | 6      | '      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | 7      | 8      | 9      | ç Ç    | à Â    |        |  |        | à Â    | ç Ç    | 7      | 8      | 9      |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | 0      |        |        |        |        |        |  |        |        |        |        |        |        |        |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     *      Encoder 1         Encoder 2                                                                  Encoder 3         Encoder 4
     * .-----------------------------------.                                                        .-----------------------------------.
     * | VolUp  | VolDn  | VolUp  | VolDn  |                                                        | PgUp   | PgDn   | PgUp   | PgDn   |
     * |--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
     * | VolDn  | VolUp  | Next   | Play   | Prev   | Touch Encoder          Touch Encoder | RgbHuI | RgbHuD | RgbMdD | RgbTog | RgbMdI |
     * '--------+--------+--------+--------+--------'                                      '--------+--------+--------+--------+--------'
     */
    [_ACCENTS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    XP(4,5), XP(0,1), _______, _______, XP(0,1), XP(4,5), KC_1,    KC_2,    KC_3,    _______,
        _______, KC_4,    KC_5,    KC_6,    XP(8,9), XP(2,3), _______, _______, XP(2,3), XP(8,9), KC_4,    KC_5,    KC_6,    _______,   
        _______, KC_7,    KC_8,    KC_9,  XP(12,13),XP(10,11),_______, _______,XP(10,11),XP(12,13),KC_7,   KC_8,    KC_9,    _______,
        _______, KC_0,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),
///*
    [_OTHER] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    XP(4,5), XP(0,1), _______, _______, XP(0,1), XP(4,5), KC_1,    KC_2,    KC_3,    _______,
        _______, KC_4,    KC_5,    KC_6,    XP(8,9), XP(2,3), _______, _______, XP(2,3), XP(8,9), KC_4,    KC_5,    KC_6,    _______,   
        _______, KC_7,    KC_8,    KC_9,  XP(12,13),XP(10,11),_______, _______,XP(10,11),XP(12,13),KC_7,   KC_8,    KC_9,    _______,
        RESET1 , KC_0,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    RESET1 ,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_RESET1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RESET2 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET2 ,   
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_RESET2] = LAYOUT(
        RESET3 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET3 ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_RESET3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, RESET  , RESET  , RESET  , RESET  , _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),
//*/
};

void keyboard_post_init_user() {
    if (!touch_encoder_toggled())
        touch_encoder_toggle();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

#if defined(OLED_DRIVER_ENABLE)
static void render_icon(void) {
    static const char PROGMEM font_icon[] = {
        0x9b,0x9c,0x9d,0x9e,0x9f,
        0xbb,0xbc,0xbd,0xbe,0xbf,
        0xdb,0xdc,0xdd,0xde,0xdf,0
    };
    oled_write_P(font_icon, false);
}

static void render_rgb_menu(void) {
    static char buffer[53] = {0};
    snprintf(buffer, sizeof(buffer), "Hue   %3d Satur %3d Value %3d Speed %3d Mode  %3d ", 
    rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode);
    oled_write(buffer, false);
}

static void render_layer(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERT"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk "), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("GAME"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN   "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ  "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

static void render_leds(void)
{
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUMLK")     : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPLK")    : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRLK")  : PSTR("     "), false);
}

static void render_touch(void)
{
    // Host Touch LED Status
    oled_write_P(!touch_encoder_toggled() ? PSTR("TOUCH")  : PSTR("     "), false);
    oled_write_P(touch_encoder_calibrating() ? PSTR("CLBRT")  : PSTR("     "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer();
        oled_write_P(PSTR("     "), false);
        render_leds();
        oled_write_P(PSTR("     "), false);
        render_touch();
        oled_set_cursor(0, 12);
        render_icon();
    }
    else {
        render_rgb_menu();
        oled_set_cursor(0, 12);
        render_icon();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
#endif
