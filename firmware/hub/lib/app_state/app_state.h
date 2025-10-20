/*----------- app_state.h -----------*/
#pragma once

#include "config.h"
#include "serial_output.h"

enum AppState{
    STATE_IDLE,
    STATE_PAIRING
};

void setAppState(AppState state);
AppState getAppState();
const char* appStateToStr(AppState state);