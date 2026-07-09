void setup() {
  Serial.begin(115200);
  inicializar_pressao();
  inicializar_temperatura();
  inicializar_distancia();
  inicializar_gas();
}

void loop () {
  mostrar_pressao();
  mostrar_temperatura();
  mostrar_distancia();
  mostrar_gas();
}
