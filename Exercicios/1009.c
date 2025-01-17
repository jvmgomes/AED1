//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int main(void){
    char nome[20];
    double salario, vendas, bonus; 
    scanf("%s", &nome);
    scanf("%lf", &salario);
    scanf("%lf", &vendas);

    bonus = vendas * 0.15;
    salario = salario + bonus;
    printf("TOTAL = R$ %.2lf\n", salario);
    return 0;
}
