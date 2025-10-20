/*----------- pairing_manager.cpp -----------*/

#include "pairing_manager.h"

static unsigned long lastDiscoveryTime = 0;

void startPairing(){
    if(getAppState() == STATE_PAIRING) return;

    setAppState(STATE_PAIRING);
    lastDiscoveryTime = millis();
    sendDiscovery();

    debugPrint("pairing - Zahajuji párovací režim");
}

void stopPairing(){
    if(getAppState() == STATE_IDLE) return;

    setAppState(STATE_IDLE);

    debugPrint("Pairing - Párovací režim ukončen");
}

void handlePairing(){
    if(getAppState() != STATE_PAIRING) return;

    unsigned long now = millis();
    if(now - lastDiscoveryTime > DISCOVERY_INTERVAL_MS){
        lastDiscoveryTime = now;

        sendDiscovery();
    }
}

void discoveryResponseHandle(const Message& msg, const uint8_t* mac){
    if(getAppState() != STATE_PAIRING) return;

    bool newModule = registerModuleIfNew(msg.senderId, getRole(msg.role), mac);

    if(newModule){
        std::map<String, String> data;
        data["cmd"] = "NEW_MODULE";
        data["id"] = msg.senderId;
        data["role"] = msg.role;
        data["paired"] = false;
        String out = createJson(data);
        sendEvent(out);
    }
}

void sendIdentifyRequest(uint32_t id){
    Module* mod = findModuleById(id);
    if(mod){
        addPeer(mod->mac);
        Message msg{IDENTIFY_REQUEST, DEVICE_ID, ROLE_HUB};
        sendMessage(mod->mac, msg);
        deletePeer(mod->mac);
    }else{
        debugPrint("Pairing - Identify modul nenalezen.");
    }
}

void acceptModule(uint32_t id){
    Module* mod = findModuleById(id);
    if(mod){
        addPeer(mod->mac);
        Message msg{DISCOVERY_ACCEPT, DEVICE_ID, ROLE_HUB};
        setModulPaired(id);
        sendMessage(mod->mac, msg);
    }else{
        debugPrint("Pairing - Accept modul nenalezen.");
    }
}