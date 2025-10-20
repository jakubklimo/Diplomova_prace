/*----------- modules.h -----------*/

#pragma once

#include <Arduino.h>
#include <vector>

#include "config.h"
#include "serial_output.h"
#include "roles.h"

struct Module{
    uint32_t id;
    Role baseRole;
    Role assignedRole;
    uint8_t mac[6];
    bool paired;
};

bool registerModuleIfNew(uint32_t id, Role role, const uint8_t* mac);
Module* findModuleById(uint32_t id);
bool updateModuleRole(uint32_t id, Role newRole);
bool setModulPaired(uint32_t id);