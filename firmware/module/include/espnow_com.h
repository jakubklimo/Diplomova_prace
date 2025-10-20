/*----------- espnow_com.h -----------*/

#pragma once

#include <WiFi.h>
#include <esp_now.h>

enum MessageType {
  DISCOVERY_REQUEST = 10,
  DISCOVERY_RESPONSE = 11,
  DISCOVERY_ACCEPT = 12,
  IDENTIFY_REQUEST = 13,
  DEFAULT_MESSAGE = 14
};

struct Message {
  uint8_t type;
  uint32_t senderId;
  uint8_t role;
};

void initEspNow();
void sendDiscoverResponse(const uint8_t* hubAddr);
void addHubPeer(const uint8_t* hubAddr);
void sendDefaultMessage();
void addTemporaryHubPeer(const uint8_t* hubAddr);
void deleteTemporaryHubPeer(const uint8_t* hubAddr);