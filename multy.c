#include <unistd.h>
int main(){
char primeiro_char[3], segundo_char[3];
int primeiro_int, segundo_int;
write(1, "Primeiro número: ", 3);
read(0, "Segundo número: ", 3);
}
