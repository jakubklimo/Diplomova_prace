/*----------- config.h -----------*/
#pragma once

// ===== Main settings =====
#define DEVICE_ID                   1000000UL

// ===== Device roles =====
#define ROLE_ALL                    1
#define ROLE_START                  2
#define ROLE_STOP                   3
#define DEVICE_ROLE                 ROLE_ALL

// ===== Serial settings =====
#define SERIAL_SPEED                115200
#define SERIAL_ENABLED

#ifdef SERIAL_ENABLED
    #define DEBUG_ENABLED
#endif

// ===== Hardware pins & timings =====
#define SENSOR_PIN                  25

#define LED_MAIN_PIN                17
#define LED_MAIN_INTERVAL_MS        250
#define LED_MAIN_DURATION_MS        5000

// ===== ESP-NOW settings =====
#define ESPNOW_CHANNEL              0
#define ESPNOW_ENCRYPTION           false
#define DISCOVERY_INTERVAL_MS       3000
#define DISCOVERY_DURATION_MS       32000
