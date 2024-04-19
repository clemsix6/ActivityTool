#pragma once

#include <windows.h>

#define ELLIPSE_SIZE 7


#define BLUE RGB(0, 161, 241)
#define GREEN RGB(124, 187, 0)
#define RED RGB(246, 83, 20)


float ui_get_scale_factor();

void ui_draw_ellipse(COLORREF color);
