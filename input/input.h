#pragma once

#include <windows.h>
#include <stdint.h>


float input_get_windows_idle_time();

void input_key_down(uint16_t keyCode);
void input_key_up(uint16_t keyCode);
void input_press_keys(uint16_t keys[]);
