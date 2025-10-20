/*----------- roles.h -----------*/

#pragma once

#include <Arduino.h>

enum Role{
    UNKNOWN = 0,
    ALL = 1,
    START = 2,
    STOP = 3,
    LAP = 4
};

Role getRole(uint8_t role);
String getRoleString(uint8_t role);