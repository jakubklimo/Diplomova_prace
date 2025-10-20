/*----------- state.cpp -----------*/

#include "esp32-hal-gpio.h"

#include "state.h"
#include "config.h"
#include "serial_output.h"
#include "led_utils.h"

static AppState currentState;

void initAppState(){
  currentState = STATE_NOTPARED;
  debugPrintf("Initializing App State: %s", appStateToString(currentState));
}

void setAppState(AppState state) {
  currentState = state;
  debugPrintf("App state changed to: %s", appStateToString(state));
}

AppState getAppState() {
  return currentState;
}

const char* appStateToString(AppState state) {
  switch (state) {
    case STATE_NOTPARED: return "STATE_NOTPARED";
    case STATE_PARED:    return "STATE_PARED";
    default:             return "UNKNOWN_STATE";
  }
}
