#include "input.h"


void input_key_down(uint16_t keyCode) {
    INPUT inputDown = {0};
    inputDown.type = INPUT_KEYBOARD;
    inputDown.ki.wVk = keyCode;
    inputDown.ki.dwFlags = 0;
    SendInput(1, &inputDown, sizeof(INPUT));
}


void input_key_up(uint16_t keyCode) {
    INPUT inputUp = {0};
    inputUp.type = INPUT_KEYBOARD;
    inputUp.ki.wVk = keyCode;
    inputUp.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &inputUp, sizeof(INPUT));
}


void input_press_keys(uint16_t keys[]) {
    for (int i = 0; keys[i] != 0; i++)
        input_key_down(keys[i]);
    Sleep(20);
    for (int i = 0; keys[i] != 0; i++)
        input_key_up(keys[i]);
}
