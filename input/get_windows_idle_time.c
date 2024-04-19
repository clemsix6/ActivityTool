#include "input.h"


float input_get_windows_idle_time() {
    LASTINPUTINFO lastInputInfo;
    lastInputInfo.cbSize = sizeof(LASTINPUTINFO);
    GetLastInputInfo(&lastInputInfo);

    DWORD currentTickCount = GetTickCount();
    DWORD idleTime = currentTickCount - lastInputInfo.dwTime;

    return (float)idleTime / 1000.0f;
}
