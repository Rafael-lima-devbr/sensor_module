#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20_PIN 4

OneWire oneWire(DS18B20_PIN);
DallasTemperature sensorTemperatura(&oneWire);

void inicializar_temperatura() {
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
  temperatura_filtrada = mediaMovel(temperatura_media, temperatura);
}

void mostrar_temperatura_atual() {
  medir_temperatura();
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}

void mostrar_temperatura_media() {
  medir_temperatura();
  Serial.print("Temperatura média: ");
  Serial.print(temperatura_filtrada);
  Serial.println(" °C");
}
