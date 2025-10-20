/*----------- bluetooth_com.h -----------*/

#pragma once

#include <WString.h>
#include <BLEDevice.h>
#include <BLE2902.h>

#include "config.h"
#include "serial_output.h"
#include "json_parser.h"
#include "modules.h"

#include "pairing_manager/pairing_manager.h"

void initBluetooth();
void sendEvent(const String& msg);