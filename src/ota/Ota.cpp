#include <ArduinoOTA.h>
#include "OTA.h"
#include "config/config.h"

void OTA::initialize() {
    ArduinoOTA.setHostname("plant-monitor");
    ArduinoOTA.setPassword("securepassword");

    ArduinoOTA.onStart([]() {
        String type;
        switch (ArduinoOTA.getCommand()) {
            case OTA_SIZE: type = "sketch"; break;
            case OTA_AUTH: type = "auth"; break;
            case OTA_UPGRADE: type = "firmware"; break;
            default: type = "unknown"; break;
        }
        Serial.println("Inicio OTA: " + type);
    });

    ArduinoOTA.onEnd([]() {
        Serial.println("Fin OTA");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progreso OTA: %u%%\r", (progress / (total / 100)));
    });

    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error OTA [%u]: ", error);
        switch (error) {
            case OTA_AUTH_ERROR: Serial.println("Autenticación fallida"); break;
            case OTA_BEGIN_ERROR: Serial.println("Inicio fallido"); break;
            case OTA_CONNECT_ERROR: Serial.println("Conexión fallida"); break;
            case OTA_RECEIVE_ERROR: Serial.println("Recepción fallida"); break;
            case OTA_END_ERROR: Serial.println("Fin fallido"); break;
        }
    });

    ArduinoOTA.begin();
}

void OTA::handle() {
    ArduinoOTA.handle();
}
