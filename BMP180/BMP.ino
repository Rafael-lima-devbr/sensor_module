#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

#define BMP180_SDA_PIN 21
#define BMP180_SCL_PIN 22

Adafruit_BMP085_Unified bmp(180);

float pressao;

void inicializar_pressao() {
  Wire.begin(BMP180_SDA_PIN, BMP180_SCL_PIN);
  while(!bmp.begin()) {
    Serial.println("Aguardando BMP180...");
    delay(1000);
  }
  Serial.println("BMP180 conectado!");
}

void medir_pressao () {
  sensors_event_t evento;
  bmp.getEvent(&evento);
  pressao = evento.pressure/10;
}
void mostrar_pressao () {
  medir_pressao();
  Serial.print("Pressão: ");
  Serial.print(pressao);
  Serial.println(" kPa");
}
