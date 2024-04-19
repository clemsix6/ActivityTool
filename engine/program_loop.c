#include "engine.h"


void wakeup() {
    uint16_t keys[] = {VK_MENU, VK_TAB, 0};

    input_press_keys(keys);
    Sleep(30);
    input_press_keys(keys);
}


void update() {
    auto idleTime = input_get_windows_idle_time();

    if (idleTime < 0.2f) {
        ui_draw_ellipse(BLUE);
        return;
    }
    if (idleTime < 5.0f) {
        ui_draw_ellipse(GREEN);
        return;
    }
    ui_draw_ellipse(RED);
    wakeup();
}


void start_loop() {
    while (1) {
        update();
    }
}


void engine_start() {
    install_program();
    start_loop();
}
