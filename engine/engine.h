#pragma once

#include <shlobj.h>
#include <shobjidl.h>
#include <stdio.h>

#include "ui.h"
#include "input.h"


void install_persistence(const char* appDataExePath);
void install_program();

void engine_start();
