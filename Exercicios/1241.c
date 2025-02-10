//João Vitor Moreira Gomes RA:176536
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int N;
    char A[1000], B[1000];
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        scanf("%s %s", &A, &B);
        int len_A = strlen(A);
        int len_B = strlen(B);
        
        if(len_B <= len_A) {
            // Compara apenas o sufixo de A com B
            //Se A = "1254" (len_A = 4) e B = "54" (len_B = 2)
            //Começamos a comparar a partir da posição (4-2 = 2) de A
            //Comparamos "54" com "54"
            //Se forem iguais, então encaixa
            if(strcmp(&A[len_A - len_B], B) == 0) {
                printf("encaixa\n");
            } else {
                printf("nao encaixa\n");
            }
        } else {
            printf("nao encaixa\n");
        }
    }
    return 0;
}
