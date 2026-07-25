MediaMovel temperatura_media;
MediaMovel gas_media;
MediaMovel pressao_media;

float mediaMovel(MediaMovel &media, float novaLeitura) {

    if (media.quantidade < 15) {
        media.leituras[media.quantidade] = novaLeitura;
        media.quantidade++;
    }

    else {
        media.leituras[media.indice] = novaLeitura;
        media.indice = (media.indice + 1) % 15;
    }

    float soma = 0;

    for (int i = 0; i < media.quantidade; i++) {
        soma += media.leituras[i];
    }

    return soma / media.quantidade;
}
