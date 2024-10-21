#include <stdio.h>

int maiorValor(int v[], int n){
    int maior = v[0];
    for(int i=1;i < n; i++){    
        if(v[i]>maior){
            maior = v[i];
        }
    } 

    return maior;
}


int main(){
    int n;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    int v[n];
    printf("Digite os elementos do vetor:\n");
    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    printf("O maior valor do vetor eh: %d\n", maiorValor(v, n));

    return 0;
}
