/*----------- serial_output.h -----------*/

#pragma once

#include "config.h"
#include <stdarg.h>
#include <HardwareSerial.h>

void initSerial();
void serialPrint(const char* msg);
void debugPrint(const char* msg);
void debugPrintf(const char* format, ...);