#include "ui.h"


float ui_get_scale_factor() {
    auto hMon = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTOPRIMARY);

    MONITORINFOEX miex;
    miex.cbSize = sizeof(MONITORINFOEX);
    GetMonitorInfo(hMon, (LPMONITORINFO) &miex);

    DEVMODE devMode;
    devMode.dmSize = sizeof(DEVMODE);
    EnumDisplaySettings(miex.szDevice, ENUM_CURRENT_SETTINGS, &devMode);

    auto horizontalScale = (float) devMode.dmPelsWidth / (float) (miex.rcMonitor.right - miex.rcMonitor.left) * 96.0f;
    auto verticalScale = (float) devMode.dmPelsHeight / (float) (miex.rcMonitor.bottom - miex.rcMonitor.top) * 96.0f;

    return ((horizontalScale + verticalScale) / 2.0f) / 96.0f;
}
