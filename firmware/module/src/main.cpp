#include <Arduino.h>
#include "serial_output.h"
#include "led_utils.h"
#include "state.h"
#include "espnow_com.h"
#include "sensor_input.h"

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  initSerial();
  initLEDs();
  initAppState();
  initEspNow();
  setupSensorInput();
}

void loop() {
  handleLED();
  handleSensorEvent();
}