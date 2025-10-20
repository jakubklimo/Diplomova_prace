/*----------- modules.cpp -----------*/

#include "modules.h"

static std::vector<Module> modules;

bool registerModuleIfNew(uint32_t id, Role role, const uint8_t* mac){
    for(const auto &m : modules){
        if(m.id == id){
            return false;
        }
    }

    Module module;
    module.id = id;
    module.baseRole = role;
    module.assignedRole = START;
    memcpy(module.mac, mac, 6);
    module.paired = false;

    modules.push_back(module);

    debugPrintf("MODULES: Přidán nový modul ID=%lu, role=%u", id, role);
    return true;
}

Module* findModuleById(uint32_t id){
    for(auto &m : modules){
        if(m.id == id){
            return &m;
        }
    }
    return nullptr;
}

bool updateModuleRole(uint32_t id, Role newRole){
    for(auto &m : modules){
        if(m.id == id){
            if (m.baseRole != ALL){
                debugPrintf("MODULES: Modul %lu má fixní roli %s, změna zakázána", id, getRoleString(m.baseRole));
                return false;
            }

            m.assignedRole = newRole;
            debugPrintf("MODULES: Modul %lu změněn na roli %s", id, getRoleString(newRole));
            return true;
        }
    }
    return false;
}

bool setModulPaired(uint32_t id){
    for(auto &m : modules){
        if(m.id == id){
            m.paired = true;
            debugPrintf("MODULES: Modul %lu spárován", id);
            return true;
        }
    }
    return false;
}