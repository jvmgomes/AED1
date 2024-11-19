#include <stdio.h>
#include <stdlib.h>

int bubblesort(int vet[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(vet[j] > vet[j+1]){
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i < n; i++)
        printf("%d ", vet[i]);
}

int main(void){
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    bubblesort(vet, n);
    return 0;
}
