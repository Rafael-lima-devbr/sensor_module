#define GAS_PIN 33

void inicializar_gas () {
  pinMode(GAS_PIN, INPUT);
}

void medir_gas () {
  int leitura;
  leitura = analogRead(GAS_PIN);
  gas = (leitura/4095.0)*100;
  gas_filtrado = mediaMovel(gas_media, gas);
}

void mostrar_gas_atual () {
  medir_gas();
  Serial.print("Índice de detecção de gases: ");
  Serial.print(gas);
  Serial.println(" ppm");
}

void mostrar_gas_media () {
  medir_gas();
  Serial.print("Índice de detecção médio de gases: ");
  Serial.print(gas_filtrado);
  Serial.println(" ppm");
}
