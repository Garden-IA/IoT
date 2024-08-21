#include "DisplayManager.h"

Adafruit_SSD1306 DisplayManager::display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void DisplayManager::initialize() {
    if (!display.begin(SSD1306_I2C_ADDRESS, 0x3D)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.clearDisplay();
}

void DisplayManager::update(float temperature, float humidity) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Temp: ");
    display.print(temperature);
    display.print(" C");
    display.setCursor(0, 10);
    display.print("Humidity: ");
    display.print(humidity);
    display.print(" %");
    display.display();
}
