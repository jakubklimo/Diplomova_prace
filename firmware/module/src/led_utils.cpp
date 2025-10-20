/*----------- led_utils.cpp -----------*/

#include "led_utils.h"
#include "esp32-hal-gpio.h"
#include "config.h"

static uint32_t blinkDuration = 0;
static uint32_t blinkInterval = 0;
static uint32_t blinkStartTime = 0;
static uint32_t lastToggleTime = 0;
static bool blinking = false;
static bool ledState = false;

static bool lighting = false;
static uint32_t lightStartTime = 0;
static uint32_t lightDuration = 0;

void initLEDs(){
  pinMode(LED_MAIN_PIN, OUTPUT);
}

void updateLED(bool state){
  digitalWrite(LED_MAIN_PIN, state ? HIGH : LOW);
  ledState = state;
}

void startBlinking(){
  blinkDuration = LED_MAIN_DURATION_MS;
  blinkInterval = LED_MAIN_INTERVAL_MS;
  blinkStartTime = millis();
  lastToggleTime = millis();
  blinking = true;
  ledState = true;
  updateLED(ledState);
}

void lightLED() {
    stopBlinking();
    lighting = true;
    lightStartTime = millis();
    lightDuration = LED_MAIN_DURATION_MS;
    updateLED(true);
}

void stopBlinking(){
  blinking = false;
  updateLED(false);
}

void handleLED(){
  uint32_t now = millis();

  if (lighting) {
      if (now - lightStartTime >= lightDuration) {
          lighting = false;
          updateLED(false);
      }
      return;
  }

  if (!blinking) return;

  if (now - blinkStartTime >= blinkDuration) {
      stopBlinking();
      return;
  }

  if (now - lastToggleTime >= blinkInterval) {
      ledState = !ledState;
      updateLED(ledState);
      lastToggleTime = now;
  }
}