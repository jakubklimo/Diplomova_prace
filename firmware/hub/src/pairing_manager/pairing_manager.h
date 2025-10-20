/*----------- pairing_manager.h -----------*/

#pragma once

#include "config.h"
#include "app_state.h"
#include "serial_output.h"
#include "modules.h"
#include "message.h"

#include "bluetooth_com/bluetooth_com.h"
#include "espnow_com/espnow_com.h"

void startPairing();
void stopPairing();
void handlePairing();

void discoveryResponseHandle(const Message& msg, const uint8_t* mac);
void sendIdentifyRequest(uint32_t id);
void acceptModule(uint32_t id);