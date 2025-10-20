/*----------- serial_output.h -----------*/

#pragma once

void initSerial();
void serialPrint(const char* msg);
void debugPrint(const char* msg);
void debugPrintf(const char* format, ...);