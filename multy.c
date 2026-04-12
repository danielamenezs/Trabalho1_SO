#include <unistd.h>

//o gemini indicou usar a função recursiva para conversão de int para char
//essa foi a única parte que eu não saquei muito bem como funciona ainda
//existem outros jeitos de fazer essa conversão, os quais eu não entendi nada, mas esse usou menos linhas
//vejam o que acham e se a gente faz um frankenstein dos nossos códigos
//eu compilei no C compiler e rodou 

void imprime_numero(int numero){
    if (numero / 10 > 0){
        imprime_numero(numero / 10); 
    }
    char digito = (numero % 10) + '0';
    write(1, &digito, 1);
}

int main(){

char primeiro_char[10], segundo_char[10];
int primeiro_int = 0, segundo_int = 0;

write(1, "Primeiro numero: ", 17);
read(0, primeiro_char, 10); 

write(1, "Segundo numero: ", 16);
read(0, segundo_char, 10);

for(int i = 0 ; primeiro_char[i] !='\n' && i<3 ; i++){
  primeiro_int = (primeiro_int * 10) + (primeiro_char[i] - '0');
}

for(int i = 0 ; segundo_char[i] !='\n' && i<3 ; i++){
  segundo_int = (segundo_int * 10) + (segundo_char[i] - '0');
}

int resultado = primeiro_int * segundo_int;
imprime_numero(resultado);
write(1, "\n", 1);

_exit(0);
}
