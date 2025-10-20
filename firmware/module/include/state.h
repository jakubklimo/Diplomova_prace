/*----------- state.h -----------*/

#pragma once

enum AppState { STATE_NOTPARED, STATE_PARED};

void initAppState();

void setAppState(AppState state);
AppState getAppState();

const char* appStateToString(AppState state);