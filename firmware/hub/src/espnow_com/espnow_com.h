/*----------- espnow_com.h -----------*/

#pragma once

#include <WiFi.h>
#include <esp_now.h>

#include "config.h"
#include "serial_output.h"
#include "pairing_manager/pairing_manager.h"
#include "message.h"

void initEspNow();
void sendMessage(const uint8_t* destMac, const Message& msg);
void sendDiscovery();

void addPeer(const uint8_t* mac);
void deletePeer(const uint8_t* mac);