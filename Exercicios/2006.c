//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int main(void){
    int t, numeros[1000], total = 0;

    scanf("%d", &t);

    
    for(int i=0; i<=4; i++){
        scanf("%d", &numeros[i]);
    }
    for(int i=0; i<=4; i++){
        if(numeros[i]==t){
            total++;
        }
    }
    printf("%d\n", total);

    return 0;
}
