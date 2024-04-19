#include "ui.h"


void ui_draw_ellipse(COLORREF color) {
    auto hdcDesktop = GetDC(NULL);
    auto savedDC = SaveDC(hdcDesktop);

    auto scaleFactor = ui_get_scale_factor();
    auto scaledEllipseSize = (int) (ELLIPSE_SIZE * scaleFactor);

    auto hBrush = CreateSolidBrush(color);
    auto hPen = CreatePen(PS_SOLID, 1, color);

    SelectObject(hdcDesktop, hBrush);
    SelectObject(hdcDesktop, hPen);

    auto hRgn = CreateEllipticRgn(0, 0, scaledEllipseSize, scaledEllipseSize);
    FillRgn(hdcDesktop, hRgn, hBrush);

    RestoreDC(hdcDesktop, savedDC);
    DeleteObject(hBrush);
    DeleteObject(hPen);
    DeleteObject(hRgn);
    ReleaseDC(NULL, hdcDesktop);
}
