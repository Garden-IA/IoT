# 🌿 Proyecto de Monitorización de Plantas

## 📜 Descripción

Este proyecto tiene como objetivo crear un dispositivo para monitorizar el estado de una planta o maceta. Utilizando un sensor de temperatura y humedad DHT y una pantalla OLED, el dispositivo muestra en tiempo real la temperatura y humedad del entorno de la planta. Además, se conecta a una red Wi-Fi para permitir futuras ampliaciones, como la integración con servicios en la nube o la visualización remota de datos.

## 🛠️ Requisitos

- **Hardware:**
  - Placa de desarrollo (Arduino, ESP32, etc.)
  - Sensor de temperatura y humedad DHT (DHT11 o DHT22)
  - Pantalla OLED (128x64)
  - Conexiones y cables adecuados
- **Software:**
  - IDE de Arduino o similar

## 📚 Librerías Utilizadas

- [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library): Para la lectura de datos del sensor DHT.
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library): Biblioteca base para gráficos.
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306): Para manejar la pantalla OLED.
- [WiFi Library](https://www.arduino.cc/en/Reference/WiFi): Para la conexión a redes Wi-Fi (en el caso de usar una placa compatible como ESP32).
- [Arduino OTA](https://www.arduino.cc/en/Reference/ArduinoOTA): Para actualizaciones remotas vía Wi-Fi.

## 🤝 Contribuciones

Las contribuciones al proyecto son bienvenidas. Si tienes alguna mejora, corrección o sugerencia, por favor, sigue estos pasos:

1. Haz un fork del repositorio.
2. Crea una nueva rama (`git checkout -b feature/nueva-caracteristica`).
3. Realiza tus cambios y asegúrate de probar el código.
4. Haz commit de tus cambios (`git commit -am 'Añadida nueva característica'`).
5. Envía un pull request.

## 👤 Autor

Este proyecto ha sido desarrollado por [Tu Nombre](https://github.com/tu-nombre).

## 📦 Instalación

1. **Clona el repositorio:**

```bash
git clone https://github.com/tu-nombre/proyecto-monitorizacion-plantas.git
```

2. Abre el proyecto en el IDE de Arduino:

- Navega hasta la carpeta proyecto-monitorizacion-plantas.
- Abre el archivo main.ino con el IDE de Arduino.

3. Instala las librerías necesarias:

- Abre el gestor de librerías en el IDE de Arduino (Sketch > Include Library > Manage Libraries...).
- Busca e instala las librerías mencionadas en la sección de Librerías Utilizadas.

4. Configura los parámetros de red:

- Modifica el archivo src/config/config.h con el SSID y la contraseña de tu red Wi-Fi.

5. Carga el código inicial a tu placa:

- Selecciona el tipo de placa y el puerto en el IDE de Arduino.
- Carga el código al dispositivo (Sketch > Upload).

## 🔄 Actualización Remota (OTA)

Para habilitar las actualizaciones remotas del firmware a través de Wi-Fi, sigue estos pasos:

1. Configura OTA en el código:

- Asegúrate de que la librería ArduinoOTA esté incluida en el archivo src/main.cpp.

```cpp
#include <ArduinoOTA.h>
```

- Configura y comienza la inicialización de OTA en el setup() del archivo src/main.cpp:

```cpp
void setup() {
    // Inicializa la conexión Wi-Fi y otros componentes
    // ...

    // Configuración de OTA
    ArduinoOTA.setHostname("nombre-del-dispositivo");
    ArduinoOTA.setPassword("contraseña-segura");
    ArduinoOTA.onStart([]() {
        String type;
        switch (ArduinoOTA.getCommand()) {
            case ArduinoOTA size = 0; break;
        }
    });
    ArduinoOTA.onEnd([]() {
        String type;
        switch (ArduinoOTA.getCommand()) {
            case ArduinoOTA size = 0; break;
        }
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progreso: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error [%u]: ", error);
    });
    ArduinoOTA.begin();
}
```

2. Sube el código inicial:

- Conecta tu placa al ordenador y sube el código inicial a través del cable USB.

3. Realiza actualizaciones OTA:

- Conéctate a la misma red Wi-Fi que el dispositivo.
- En el IDE de Arduino, selecciona la opción de carga de OTA (Tools > Port) para encontrar tu dispositivo.
- Selecciona tu dispositivo y carga el nuevo código como lo harías normalmente.

## 🚀 Uso

1. Conecta el hardware:

- Conecta el sensor DHT y la pantalla OLED a tu placa según los pines especificados en el código (DHT_PIN, I2C address).

2. Energiza el dispositivo:

- Conecta tu placa a una fuente de alimentación adecuada.

3. Visualiza los datos:

- Una vez cargado el código y conectada la placa a la red Wi-Fi, la pantalla OLED mostrará la temperatura y humedad actuales del entorno de la planta.

4. Monitoreo remoto:

- En futuras actualizaciones, podrás integrar el dispositivo con servicios en la nube para monitoreo remoto y alertas.

5. Actualizaciones de firmware OTA:

- Realiza actualizaciones de firmware sin necesidad de conectar el dispositivo físicamente mediante el proceso de OTA descrito anteriormente.

¡Esperamos que encuentres útil este proyecto para el cuidado de tus plantas!
