/*----------- config.h -----------*/

#pragma once

// ===== Main settings =====
#define DEVICE_ID                   0000000UL

// ===== Device roles =====
#define ROLE_HUB                    0

// ===== Serial =====
#define SERIAL_SPEED                115200
#define SERIAL_ENABLED

#ifdef SERIAL_ENABLED
    #define DEBUG_ENABLED
#endif

// ===== Hardware =====

// ===== ESP-NOW =====
#define CHANNEL                     0
#define ENCRYPTION                  false
#define DISCOVERY_INTERVAL_MS       2000