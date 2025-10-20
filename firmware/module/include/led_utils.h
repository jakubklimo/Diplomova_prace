/*----------- led_utils.h -----------*/

#pragma once
#include "state.h"

void initLEDs();

void startBlinking();
void updateLED(bool state);
void stopBlinking();
void lightLED();
void handleLED();