/*----------- sensor_input.h -----------*/

#pragma once

#include "esp_attr.h"

void IRAM_ATTR sensorInterrupt();
void setupSensorInput();
void handleSensorEvent();