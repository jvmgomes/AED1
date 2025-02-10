//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int main(void){
    int codigo, quant;
    double total;
    scanf("%d %d", &codigo, &quant);

    if(codigo==1){
        total += 4.00;
    }
    else if(codigo==2){
        total += 4.50;
    }
    else if(codigo==3){
        total += 5.00;
    }
    else if(codigo==4){
        total += 2.00;
    }
    else if(codigo==5){
        total += 1.50;
    }
    total *= quant;
    printf("Total: R$ %.2lf\n", total);

    return 0;
}
