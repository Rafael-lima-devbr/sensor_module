struct MediaMovel {
  float leituras[15];
  int quantidade = 0;
  int indice = 0;
};

void setup() {
  Serial.begin(115200);
  inicializar_pressao();
  inicializar_temperatura();
  inicializar_distancia();
  inicializar_gas();
}

void loop () {
  mostrar_gas_media();
  mostrar_temperatura_media();
  mostrar_pressao_media();
  mostrar_distancia();
}
