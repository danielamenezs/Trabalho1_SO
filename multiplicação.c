#include <unistd.h>
#include <fcntl.h>

int transformarTextoEmNumero(char *entrada) {
    int posicao = 0;
    int valor = 0;

    while (entrada[posicao] >= '0' && entrada[posicao] <= '9') {
        valor = valor * 10 + (entrada[posicao] - '0');
        posicao++;
    }

    return valor;
}

int transformarNumeroEmTexto(int valor, char *saida) {
    char numerosAoContrario[20];
    int totalDigitos = 0;
    int posicaoSaida = 0;
    int i;

    if (valor == 0) {
        saida[0] = '0';
        saida[1] = '\0';
        return 1;
    }

    while (valor > 0) {
        numerosAoContrario[totalDigitos++] = (valor % 10) + '0';
        valor /= 10;
    }

    for (i = totalDigitos - 1; i >= 0; i--) {
        saida[posicaoSaida++] = numerosAoContrario[i];
    }

    saida[posicaoSaida] = '\0';
    return posicaoSaida;
}

int juntarTexto(char *mensagem, int posicaoAtual, char *trecho) {
    int i = 0;

    while (trecho[i] != '\0') {
        mensagem[posicaoAtual++] = trecho[i++];
    }

    return posicaoAtual;
}
