#include "src/config/Constants.h"
#include "src/config/Config.h"
#include "src/sensors/DHTSensor.h"
#include "src/display/DisplayManager.h"
#include "src/network/NetworkManager.h"
#include "src/sensors/SoilSensor.h"
#include "src/setup/SetupManager.h"
#include "src/ota/OTA.h"

void setup() {
    Serial.begin(115200);

    // Configuración inicial
    SetupManager::initialize();

    // Configurar red
    NetworkManager::connectToWiFi();

    // Inicializar el sensor DHT
    DHTSensor::initialize();

    // Inicializar la pantalla OLED
    DisplayManager::initialize();

    // Inicializar la funcionalidad OTA
    OTA::initialize();

    // Inicializar el sensor de tierra
    SoilSensor::initialize();
}

void loop() {
    // Manejar actualizaciones OTA
    OTA::handle();

    // Leer los datos del sensor DHT
    float temperature = DHTSensor::getTemperature();
    float humidity = DHTSensor::getHumidity();

    // Leer los datos del sensor de tierra
    float soilHumidity = SoilSensor::readSoilHumidity();

    // Actualizar la pantalla con los nuevos datos
    DisplayManager::update(temperature, humidity);

    // Esperar un tiempo antes de la siguiente lectura
    delay(2000);
}
