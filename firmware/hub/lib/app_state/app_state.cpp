/*----------- app_state.cpp -----------*/

#include "app_state.h"

static AppState currentState = STATE_IDLE;

void setAppState(AppState state){
    currentState = state;
    debugPrintf("Přepínám stav na %s", appStateToStr(state));
}

AppState getAppState(){
    return currentState;
}

const char* appStateToStr(AppState state) {
    switch(state) {
        case AppState::STATE_IDLE:          return "STATE_IDLE";
        case AppState::STATE_PAIRING:        return "STATE_PAIRING";
        default:                            return "UNKNOWN";
    }
}