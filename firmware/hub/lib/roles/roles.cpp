/*----------- roles.cpp -----------*/

#include "roles.h"

Role getRole(uint8_t role){
    switch (role) {
        case Role::ALL:   return ALL;
        case Role::START: return START;
        case Role::STOP:  return STOP;
        case Role::LAP:   return LAP;
        default:          return UNKNOWN;
    }
}

String getRoleString(uint8_t role){
    switch (role) {
        case Role::ALL:   return "ALL";
        case Role::START: return "START";
        case Role::STOP:  return "STOP";
        case Role::LAP:   return "LAP";
        default:          return "UNKNOWN";
    }
}