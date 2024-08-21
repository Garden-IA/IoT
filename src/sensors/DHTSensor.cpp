#include "DHTSensor.h"

DHT DHTSensor::dht(DHT_PIN, DHT11);

void DHTSensor::initialize() {
    dht.begin();
}

float DHTSensor::getTemperature() {
    return dht.readTemperature();
}

float DHTSensor::getHumidity() {
    return dht.readHumidity();
}
