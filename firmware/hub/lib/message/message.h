/*----------- message.h -----------*/

#pragma once

#include <cstdint>

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