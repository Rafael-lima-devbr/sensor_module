#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20_PIN 4

OneWire oneWire(DS18B20_PIN);
DallasTemperature sensorTemperatura(&oneWire);


float temperatura;

void inicializar_temperatura() {
  OneWire onewire(DS18B20_PIN);

  sensorTemperatura.begin();
  while(sensorTemperatura.getDeviceCount() == 0) {
    Serial.println("Aguardando DS18B20...");
    delay(1000);
  }
  Serial.println("DS18B20 conectado!");
}

void medir_temperatura () {
  sensorTemperatura.requestTemperatures();
  temperatura = sensorTemperatura.getTempCByIndex(0);
}

void mostrar_temperatura() {
  medir_temperatura();
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}
