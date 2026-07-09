#define GAS_PIN 33

float gas;
String nivel;

void inicializar_gas () {
  pinMode(GAS_PIN, INPUT);
}

void medir_gas () {
  int leitura;
  
  leitura = analogRead(GAS_PIN);
  gas = (leitura/4095.0)*100;
  if (gas < 30) nivel = "Muito baixa";
  else if (gas < 40) nivel = "Baixa";
  else if (gas < 60) nivel = "Moderada";
  else if (gas < 80) nivel = "Alta";
  else nivel = "Muito alta";
}

void mostrar_gas () {
  medir_gas();
  Serial.print("Índice de detecção de gases: ");
  Serial.print(gas);
  Serial.print("% | Nível: ");
  Serial.println(nivel);
}
