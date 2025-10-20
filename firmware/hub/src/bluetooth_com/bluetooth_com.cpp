/*----------- bluetooth_com.cpp -----------*/

#include "bluetooth_com.h"

#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890ab"
#define CHAR_COMMAND_UUID   "87654321-4321-4321-4321-ba0987654321"
#define CHAR_EVENT_UUID     "66666666-7777-8888-9999-aaaaaaaaaaaa"

BLEServer* pServer = nullptr;
BLECharacteristic* pCommandCharacteristic = nullptr;
BLECharacteristic* pEventCharacteristic   = nullptr;
bool deviceConnected = false;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) override {
    deviceConnected = true;
    debugPrint("BLE zařízení připojeno");
  }
  void onDisconnect(BLEServer* pServer) override {
    deviceConnected = false;
    debugPrint("BLE zařízení odpojeno");

    pServer->startAdvertising();
  }
};

class CommandCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic* pCharacteristic) override {
    String rxValue = pCharacteristic->getValue().c_str();
    if (rxValue.length() == 0) return;
    debugPrintf("Přijato z mobilu: %s", rxValue.c_str());

    auto kv = parseJson(rxValue);

    if (kv["cmd"] == "PAIR_ON"){
      startPairing();
      debugPrint("Zapínám párovací režim ESP-NOW.");
      sendEvent("PAIRING_STARTED");
    }
    else if(kv["cmd"] == "PAIR_OFF"){
      stopPairing();
      debugPrint("Vypínám párovací režim ESP-NOW.");
      sendEvent("PAIRING_STOPPED");
    }
    else if(kv["cmd"] == "IDENTIFY"){
      uint32_t id = kv.count("id") ? kv["id"].toInt() : 0;
      sendIdentifyRequest(id);
    }
    else if(kv["cmd"] == "CHANGE_ROLE"){
      uint32_t id = kv.count("id") ? kv["id"].toInt() : 0;
      uint8_t role = kv.count("role") ? kv["role"].toInt() : 0;
      updateModuleRole(id, getRole(role));
    }
    else if(kv["cmd"] == "ACCEPT"){
      uint32_t id = kv.count("id") ? kv["id"].toInt() : 0;
      acceptModule(id);
    }
  }
};

void initBluetooth(){
  BLEDevice::init("ESP32_Hub");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService* pService = pServer->createService(SERVICE_UUID);

  BLECharacteristic* pCommandCharacteristic = pService->createCharacteristic(
    CHAR_COMMAND_UUID,
    BLECharacteristic::PROPERTY_WRITE
  );
  pCommandCharacteristic->setCallbacks(new CommandCallbacks());

  pEventCharacteristic = pService->createCharacteristic(
    CHAR_EVENT_UUID,
    BLECharacteristic::PROPERTY_NOTIFY
  );
  pEventCharacteristic->addDescriptor(new BLE2902());

  pService->start();

  pServer->getAdvertising()->start();
  debugPrint("BLE reklamování spuštěno");
}

void sendEvent(const String& msg) {
  if (deviceConnected && pEventCharacteristic) {
    pEventCharacteristic->setValue(msg.c_str());
    pEventCharacteristic->notify();
    debugPrintf("BLE: Odeslán event: %s", msg.c_str());
  }
}