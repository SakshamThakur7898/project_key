#include QMK_KEYBOARD_H

enum custom_keycodes
{
    Copy, Paste
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
    [0] = LAYOUT(
        Copy,   Paste,      KC_3,
        KC_4,   KC_5,      KC_6,
        KC_7,   KC_8,      KC_9
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case Copy:
        if (record->event.pressed)
        {
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_C) SS_DELAY(100) SS_UP(X_LCTL));
        }
        else
        {

        }
        break;

        case Paste:
        if (record->event.pressed)
        {
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_V) SS_DELAY(100) SS_UP(X_LCTL));
        }
        else
        {

        }
        break;

    }
    return true;
};

