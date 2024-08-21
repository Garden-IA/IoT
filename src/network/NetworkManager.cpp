#include "NetworkManager.h"

void NetworkManager::connectToWiFi() {
    WiFi.begin(Config::SSID, Config::PASSWORD);
    Serial.print("Connecting to ");
    Serial.print(Config::SSID);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void NetworkManager::onWiFiConnect() {
    // Callback function if needed
}
