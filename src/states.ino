void analise_Estado() {
  String criticos = "";
  String atencoes = "";

  // DISTÂNCIA
  if (distancia < 50) {
    criticos += "DISTÂNCIA, ";
    distancia_critica = true;
    distancia_leve = false;
  } else if (distancia < 100) {
    atencoes += "DISTÂNCIA, ";
    distancia_leve = true;
    distancia_critica = false;
  } else {
    distancia_leve = false;
    distancia_critica = false;
  }

  // TEMPERATURA
  if (temperatura_filtrada < -20 || temperatura_filtrada > 45) {
    criticos += "TEMPERATURA, ";
    temperatura_critica = true;
    temperatura_leve = false;
  } else if (temperatura_filtrada < 0 || temperatura_filtrada > 35) {
    atencoes += "TEMPERATURA, ";
    temperatura_leve = true;
    temperatura_critica = false;
  } else {
    temperatura_leve = false;
    temperatura_critica = false;
  }

  // PRESSÃO
  if (pressao_filtrada < 70 || pressao_filtrada > 150) {
    criticos += "PRESSÃO, ";
    pressao_critica = true;
    pressao_leve = false;
  } else if (pressao_filtrada < 80 || pressao_filtrada > 120) {
    atencoes += "PRESSÃO, ";
    pressao_leve = true;
    pressao_critica = false;
  } else {
    pressao_leve = false;
    pressao_critica = false;
  }

  // GÁS
  if (gas_filtrado >= 2100) {
    criticos += "GÁS, ";
    gas_critico = true;
    gas_leve = false;
  } else if (gas_filtrado >= 300) {
    atencoes += "GÁS, ";
    gas_critico = false;
    gas_leve = true;;
  } else {
    gas_critico = false;
    gas_leve = false;
  }




  if (criticos.length() > 0) {
    criticos.remove(criticos.length() - 2);
  }

  if (atencoes.length() > 0) {
    atencoes.remove(atencoes.length() - 2);
  }



  if (criticos.length() == 0 && atencoes.length() == 0) {
    estado = "NORMAL";
  } else {
    estado = "";

    if (criticos.length() > 0) {
      estado += "CRÍTICO: " + criticos;
    }

    if (atencoes.length() > 0) {
      if (estado.length() > 0) {
        estado += " | ";
      }

      estado += "ATENÇÃO: " + atencoes;
    }
  }
}

void mostrar_Estado() {
  analise_Estado();
  Serial.println(estado);
}
