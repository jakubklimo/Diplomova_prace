/*----------- sensor_input.cpp -----------*/

#include "sensor_input.h"
#include "config.h"
#include "serial_output.h"
#include "espnow_com.h"
#include "state.h"
#include "Arduino.h"
#include "esp32-hal-gpio.h"

static volatile bool sensorTriggered = false;

void IRAM_ATTR sensorInterrupt(){
  sensorTriggered = true;
}

void setupSensorInput(){
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), sensorInterrupt, FALLING);
}

void handleSensorEvent(){
  if(!sensorTriggered || getAppState() != STATE_PARED) return;

  sensorTriggered = false;

  sendDefaultMessage();
}