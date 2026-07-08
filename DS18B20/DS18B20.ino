#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20_PIN 4

OneWire onewire(DS18B20_PIN);
DallasTemperature sensorTemperatura(&onewire);

void setup() {
  Serial.begin(115200);
  sensorTemperatura.begin();
  while(sensorTemperatura.getDeviceCount() == 0) {
    Serial.println("Aguardando DS18B20...");
    delay(1000);
  }
  Serial.println("DS18B20 conectado!");
}

void loop () {
  sensorTemperatura.requestTemperatures();
  float temperatura = sensorTemperatura.getTempCByIndex(0);
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C");
}

