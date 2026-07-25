#define GAS_PIN 33

float gas, gas_filtrado;
String nivel;

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
  if (gas < 30) nivel = "Muito baixa";
  else if (gas < 40) nivel = "Baixa";
  else if (gas < 60) nivel = "Moderada";
  else if (gas < 80) nivel = "Alta";
  else nivel = "Muito alta";
  Serial.print("Índice de detecção de gases: ");
  Serial.print(gas);
  Serial.print("% | Nível: ");
  Serial.println(nivel);
}

void mostrar_gas_media () {
  medir_gas();
  if (gas_filtrado < 30) nivel = "Muito baixa";
  else if (gas_filtrado < 40) nivel = "Baixa";
  else if (gas_filtrado < 60) nivel = "Moderada";
  else if (gas_filtrado < 80) nivel = "Alta";
  else nivel = "Muito alta";
  Serial.print("Índice de detecção médio de gases: ");
  Serial.print(gas_filtrado);
  Serial.print("% | Nível: ");
  Serial.println(nivel);
}
