#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "constants.h"

class DisplayManager {
public:
    static void initialize();
    static void update(float temperature, float humidity);
private:
    static Adafruit_SSD1306 display;
};

#endif
