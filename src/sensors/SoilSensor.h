#ifndef SOILSENSOR_H
#define SOILSENSOR_H

#include <Arduino.h>

// Definición de pines y constantes
#define SOILSENSOR A0

// Configuración del rango de humedad del suelo
extern int maxSoilHumidity;
extern int minSoilHumidity;

// Inicializa el sensor de humedad del suelo
void initSoilSensor();

// Lee el valor de humedad del suelo
int readSoilHumidity();

#endif // SOILSENSOR_H
