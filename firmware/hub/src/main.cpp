#include "config.h"
#include "serial_output.h"
#include "bluetooth_com/bluetooth_com.h"
#include "espnow_com/espnow_com.h"
#include "pairing_manager/pairing_manager.h"

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  initSerial();
  initBluetooth();
  initEspNow();
}

void loop() {
  handlePairing();
}