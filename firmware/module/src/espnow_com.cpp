/*----------- espnow_comm.h -----------*/

#include "config.h"
#include "state.h"
#include "espnow_com.h"
#include "serial_output.h"
#include "HardwareSerial.h"
#include "led_utils.h"

static uint8_t hubMac[6];

void onReceive(const uint8_t* mac, const uint8_t* data, int len) {
  if (len < sizeof(Message)) {
    debugPrintf("Received message too short: %d bytes", len);
    return;
  }

  const Message* msg = (const Message*)data;

  debugPrintf("Received message type: %d from: %02X:%02X:%02X:%02X:%02X:%02X",
              msg->type,
              mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

  switch (msg->type)
  {
    case DISCOVERY_REQUEST:
      sendDiscoverResponse(mac);
      break;

    case DISCOVERY_ACCEPT:
      addHubPeer(mac);
      break;

    case IDENTIFY_REQUEST:
      startBlinking();
      break;
  
    default:
      break;
  }
}

void initEspNow() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(false);

  if (esp_now_init() != ESP_OK) {
    serialPrint("Chyba při inicializaci ESP-NOW");
    return;
  }

  debugPrint("ESP-NOW initialized");

  esp_now_register_recv_cb(onReceive);
}

void sendDiscoverResponse(const uint8_t* hubAddr) {
  if(getAppState() == STATE_PARED) return;

  addTemporaryHubPeer(hubAddr);
  Message msg;
  msg.type = DISCOVERY_RESPONSE;
  msg.senderId = DEVICE_ID;
  msg.role = DEVICE_ROLE;

  esp_err_t result = esp_now_send(hubAddr, (uint8_t*)&msg, sizeof(msg));

  if(result == ESP_OK){
    debugPrint("Discovery response sent");
  }else{
    debugPrintf("Error sending discovery response: %d", result);
  }
  deleteTemporaryHubPeer(hubAddr);
}

void addHubPeer(const uint8_t* hubAddr){
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, hubAddr, 6);
  peerInfo.channel = ESPNOW_CHANNEL;
  peerInfo.encrypt = ESPNOW_ENCRYPTION;

  if (esp_now_add_peer(&peerInfo) == ESP_OK) {
    memcpy(hubMac, hubAddr, 6);
    setAppState(STATE_PARED);
    lightLED();
    debugPrint("Hub peer added successfully");
  } else {
    debugPrint("Failed to add hub peer");
  }
}

void sendDefaultMessage(){
  Message msg = {};
  msg.type = DEFAULT_MESSAGE;
  msg.senderId = DEVICE_ID;
  msg.role = DEVICE_ROLE;

  esp_err_t result = esp_now_send(hubMac, (uint8_t*)&msg, sizeof(msg));
  
  if (result == ESP_OK) {
    debugPrint("Default message sent");
  } else {
    debugPrintf("Error sending default message: %d", result);
  }
}

void addTemporaryHubPeer(const uint8_t* hubAddr){
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, hubAddr, 6);
  peerInfo.channel = ESPNOW_CHANNEL;
  peerInfo.encrypt = ESPNOW_ENCRYPTION;

  if (esp_now_add_peer(&peerInfo) == ESP_OK) {
    debugPrint("ESP-NOW - Temporary hub peer added successfully");
  } else {
    debugPrint("ESP-NOW - Failed to add hub peer");
  }
}

void deleteTemporaryHubPeer(const uint8_t* hubAddr){
  esp_err_t res = esp_now_del_peer(hubAddr);
  if (res == ESP_OK) {
    debugPrint("ESP-NOW - Temporary peer deleted after send");
  } else {
    debugPrintf("ESP-NOW - Failed to delete peer: %s", esp_err_to_name(res));
  }
}