struct MediaMovel {
  float leituras[15];
  int quantidade = 0;
  int indice = 0;
};

float temperatura, temperatura_filtrada, pressao, pressao_filtrada, gas, gas_filtrado, distancia;
bool temperatura_leve, temperatura_critica, pressao_leve, pressao_critica, gas_leve, gas_critico, distancia_leve, distancia_critica;
String estado;

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
