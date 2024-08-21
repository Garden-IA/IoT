#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <WiFi.h>
#include "config.h"

class NetworkManager {
public:
    static void connectToWiFi();
private:
    static void onWiFiConnect();
};

#endif
