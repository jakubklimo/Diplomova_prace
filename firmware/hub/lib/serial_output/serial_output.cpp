/*----------- serial_output.cpp -----------*/

#include "serial_output.h"

void initSerial() {
  #ifdef SERIAL_ENABLED
    Serial.begin(SERIAL_SPEED);
    delay(500);
    debugPrint("Debug mód aktivní");
  #endif
}

void serialPrint(const char* msg){
  #ifdef SERIAL_ENABLED
    Serial.println(msg);
  #endif
}

void debugPrint(const char* msg){
  #if defined(SERIAL_ENABLED) && defined(DEBUG_ENABLED)
    Serial.print("[DEBUG] ");
    Serial.println(msg);
  #endif
}

void debugPrintf(const char* format, ...) {
  #if defined(SERIAL_ENABLED) && defined(DEBUG_ENABLED)
    Serial.print("[DEBUG] ");
    char buf[128];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);
    Serial.println(buf);
  #endif
}