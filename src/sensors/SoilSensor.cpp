#include "SoilSensor.h"

// Inicializa las constantes para el sensor de humedad del suelo
int maxGroundHumidity = 270; // Ajustar según calibración
int minGroundHumidity = 706; // Ajustar según calibración

void initSoilSensor() {
    pinMode(SOILSENSOR, INPUT);
}

int readSoilHumidity() {
    int sensorValue = analogRead(SOILSENSOR);
    return sensorValue;
}
