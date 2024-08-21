#ifndef DHTSENSOR_H
#define DHTSENSOR_H

#include <DHT.h>
#include "constants.h"

class DHTSensor {
public:
    static void initialize();
    static float getTemperature();
    static float getHumidity();
private:
    static DHT dht;
};

#endif
