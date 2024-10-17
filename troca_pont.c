#include <stdio.h>
#include <errno.h> /*biblioteca de erros possiveis de acontecer envolvendo arquivos*/

int troca(int *i, int *j){
    int temp;
    temp = *i;
    *i=*j;
    *j = temp;
    printf("%d, %d, %d, %d\n", *i, *j, i, j);
}

int main(void) {
    int valor1=3 , valor2=5;

    int *i=&valor1;
    int *j=&valor2;
    int result = troca(i, j);
    printf("%d, %d", valor1, valor2);

    return 0;
}
