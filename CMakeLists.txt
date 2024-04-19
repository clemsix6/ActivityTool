cmake_minimum_required(VERSION 3.28)
project(activityTool C)

set(CMAKE_C_STANDARD 23)

include_directories(input ui engine io)

add_executable(activityTool main.c
        ui/ui.h
        ui/draw_ellipse.c
        ui/get_scale_factor.c
        input/input.h
        input/get_windows_idle_time.c
        engine/engine.h
        input/key_press.c
        engine/program_loop.c
        engine/install_persistence.c
        engine/install_program.c)


set_target_properties(activityTool PROPERTIES OUTPUT_NAME "Activity_Tool")

target_link_libraries(activityTool shell32)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
