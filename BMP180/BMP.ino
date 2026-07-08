#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

#define BMP180_SDA_PIN 21
#define BMP180_SCL_PIN 22

Adafruit_BMP085_Unified bmp(180);

void setup() {
  Serial.begin(115200);
  Wire.begin(BMP180_SDA_PIN, BMP180_SCL_PIN);
  while(!bmp.begin()) {
    Serial.println("Aguardando BMP180...");
    delay(1000);
  }
  Serial.println("BMP180 conectado!");
}

void loop () {
  sensors_event_t evento;
  bmp.getEvent(&evento);
  float pressaoPa = evento.pressure * 100;
  Serial.print("Pressão: ");
  Serial.print(pressaoPa);
  Serial.println(" Pa");
}
