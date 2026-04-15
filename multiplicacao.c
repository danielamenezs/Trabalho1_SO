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

int main() {
    char entradaA[20];
    char entradaB[20];
    char numeroATexto[20];
    char numeroBTexto[20];
    char resultadoTexto[20];
    char mensagem[100];

    int numeroA;
    int numeroB;
    int resultado;
    int bytesLidosA;
    int bytesLidosB;
    int arquivo;
    int tamanhoMensagem = 0;

    write(1, "digite o primeiro numero: ", 26);
    bytesLidosA = read(0, entradaA, 19);
    if (bytesLidosA <= 1) return 1;
    entradaA[bytesLidosA - 1] = '\0';

    write(1, "digite o segundo numero: ", 25);
    bytesLidosB = read(0, entradaB, 19);
    if (bytesLidosB <= 1) return 1;
    entradaB[bytesLidosB - 1] = '\0';

    numeroA = transformarTextoEmNumero(entradaA);
    numeroB = transformarTextoEmNumero(entradaB);
    resultado = numeroA * numeroB;

    transformarNumeroEmTexto(numeroA, numeroATexto);
    transformarNumeroEmTexto(numeroB, numeroBTexto);
    transformarNumeroEmTexto(resultado, resultadoTexto);

    tamanhoMensagem = juntarTexto(mensagem, tamanhoMensagem, "resultado da multiplicacao: ");
    tamanhoMensagem = juntarTexto(mensagem, tamanhoMensagem, numeroATexto);
    tamanhoMensagem = juntarTexto(mensagem, tamanhoMensagem, " x ");
    tamanhoMensagem = juntarTexto(mensagem, tamanhoMensagem, numeroBTexto);
    tamanhoMensagem = juntarTexto(mensagem, tamanhoMensagem, " = ");
    tamanhoMensagem = juntarTexto(mensagem, tamanhoMensagem, resultadoTexto);
    tamanhoMensagem = juntarTexto(mensagem, tamanhoMensagem, "\n");

    write(1, mensagem, tamanhoMensagem);

    arquivo = open("resultado.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(arquivo, mensagem, tamanhoMensagem);
    close(arquivo);

    return 0;
}
