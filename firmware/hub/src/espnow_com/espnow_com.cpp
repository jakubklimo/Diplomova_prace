/*----------- espnow_comm.h -----------*/

#include "espnow_com.h"

uint8_t broadcastAddress[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

void onReceive(const uint8_t* mac, const uint8_t* data, int len) {
  if (len < sizeof(Message)) {
    debugPrintf("ESP_NOW - Received message too short: %d bytes", len);
    return;
  }

  const Message* msg = (const Message*)data;

  debugPrintf("ESP_NOW - Received message type: %d from MAC: %02X:%02X:%02X:%02X:%02X:%02X",
              msg->type,
              mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

  switch(msg->type){
    case DISCOVERY_RESPONSE:
      discoveryResponseHandle(*msg, mac);
      break;
    default:
      break;
  }
}

void initEspNow() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    serialPrint("ESP_NOW - Chyba při inicializaci ESP-NOW");
    return;
  }

  debugPrint("ESP_NOW - initialized");

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = CHANNEL;
  peerInfo.encrypt = ENCRYPTION;

  if (esp_now_add_peer(&peerInfo) == ESP_OK) {
    debugPrint("ESP_NOW - BroadcastAddress added");
  }else{
    debugPrint("ESP_NOW - Failed to add broadcast peer");
  }

  esp_now_register_recv_cb(onReceive);
}

void sendMessage(const uint8_t* destMac, const Message& msg) {
  esp_err_t result = esp_now_send(destMac, (const uint8_t*)&msg, sizeof(msg));

  if(result == ESP_OK){
    debugPrint("ESP_NOW - Message send");
  }else{
    debugPrintf("ESP_NOW - Error sending discovery response: %s", esp_err_to_name(result));
  }
}

void sendDiscovery(){
  Message msg{DISCOVERY_REQUEST, DEVICE_ID, ROLE_HUB};
  sendMessage(broadcastAddress, msg);
}

void addPeer(const uint8_t* mac){
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, mac, 6);
  peerInfo.channel = CHANNEL;
  peerInfo.encrypt = ENCRYPTION;

  if (esp_now_add_peer(&peerInfo) == ESP_OK) {
    debugPrint("ESP-NOW - Temporary hub peer added successfully");
  } else {
    debugPrint("ESP-NOW - Failed to add hub peer");
  }
}

void deletePeer(const uint8_t* mac){
  esp_err_t res = esp_now_del_peer(mac);
  if (res == ESP_OK) {
    debugPrint("ESP-NOW - Temporary peer deleted after send");
  } else {
    debugPrintf("ESP-NOW - Failed to delete peer: %s", esp_err_to_name(res));
  }
}