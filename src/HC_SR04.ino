#define HC_SR04_TRIG_PIN 18
#define HC_SR04_ECHO_PIN 5

float distancia;
long duracao;

void inicializar_distancia() {
  pinMode(HC_SR04_TRIG_PIN, OUTPUT);
  pinMode(HC_SR04_ECHO_PIN, INPUT);
}

void medir_distancia () {
  digitalWrite(HC_SR04_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(HC_SR04_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(HC_SR04_TRIG_PIN, LOW);
  duracao = pulseIn(HC_SR04_ECHO_PIN, HIGH);
  distancia = duracao * 0.0343/2;
}

void mostrar_distancia () {
  medir_distancia();
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
}
