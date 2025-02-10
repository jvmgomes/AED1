//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int main() {

    int diasTotais, dias, meses, anos;

    scanf("%d", &diasTotais);

    anos = diasTotais / 365;
    meses = diasTotais % 365 /30;
    dias =  diasTotais % 365 % 30;

    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);


    return 0;
}
