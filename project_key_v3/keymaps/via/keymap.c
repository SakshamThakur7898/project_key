#include QMK_KEYBOARD_H

enum layers {
    LAYER_BASE,
    LAYER_HOLD,
    LAYER_PREMIERE,
    LAYER_PHOTOSHOP,
    LAYER_SHAPR3D,
    LAYER_OBS

};

    enum custom_keycodes {
        PremierePro = SAFE_RANGE,
        Photoshop,
        OBS,
        Shapr3d,
        Screenshot,
        chatgpt,
        undo,
        redo,
        copy,
        paste
    };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        OBS,   PremierePro,     Photoshop,
        Shapr3d,   Screenshot,        chatgpt,
        KC_SYSTEM_SLEEP,   KC_NO,             MO(LAYER_HOLD)
    ),
    [LAYER_HOLD] = LAYOUT(
        TG(LAYER_OBS),   TG(LAYER_PREMIERE),     TG(LAYER_PHOTOSHOP),
        TG(LAYER_SHAPR3D),   KC_E,                    KC_F,
        KC_G,   KC_SYSTEM_POWER,                    KC_A
    ),
    [LAYER_PREMIERE] = LAYOUT(
        KC_Q,       KC_W,    KC_C,
        KC_DEL,     copy,    paste,
        undo,       redo,   TO(0)
    ),
  
    [LAYER_SHAPR3D] = LAYOUT(
        KC_ESC,       KC_L,    KC_M,
        KC_DEL,     KC_O,    KC_S   ,
        undo,       redo,   TO(0)
    ),
    [LAYER_SHAPR3D] = LAYER_PHOTOSHOP(
        KC_ESC,       KC_L,    KC_M,
        KC_DEL,     KC_O,    KC_S   ,
        undo,       redo,   TO(0)
    ),
    [LAYER_OBS] = LAYOUT(
        KC_F1,       KC_F2,    KC_F3,
        KC_F4,     KC_F5,    KC_F6,
        KC_F7,       KC_F8,   TO(0)
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Screenshot:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "Snipping Tool" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case PremierePro:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "premiere pro" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case Photoshop:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "Photoshop" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case Shapr3d:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "Shapr3d" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case OBS:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "OBS" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case chatgpt:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "Brave" SS_DELAY(100) SS_TAP(X_ENT) SS_DELAY(1000) "chatgpt.com" SS_TAP(X_ENT));
            }
            break;
            case undo:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(100) SS_TAP(X_Z) SS_DELAY(100) SS_UP(X_LCTL));
            }
            break;
            case redo:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(100) SS_DOWN(X_LSFT) SS_DELAY(100) SS_TAP(X_Z) SS_DELAY(100) SS_UP(X_LSFT) SS_UP(X_LCTL));
            }
            break;
            case copy:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_UP(X_LCTL));
            }
    }
    return true;
};