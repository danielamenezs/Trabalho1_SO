#include <unistd.h>

int main(){

char primeiro_char[3], segundo_char[3]; //dados lidos pela chamada
int primeiro_int = 0, segundo_int = 0; //variáveis para a conversão de char para int; = 0 para o lixo de memória

write(1, "Primeiro numero: ", 17); //escrever na tela
read(0, primeiro_char, 3); 

write(1, "Segundo numero: ", 16);
read(0, segundo_char, 3);

for(i = 0 ; primeiro_char[i] !='\n' && i<3 ; i++){
  primeiro_int = (primeiro_int * 10) + (primeiro_char - '0');
}

for(i = 0 ; segundo_char[i] !='\n' && i<3 ; i++){
  segundo_int = (segundo_int * 10) + (segundo_char - '0');
}



_exit(0)
}
