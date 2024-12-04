//João Vitor Moreira Gomes - RA: 176536
#include <stdio.h>

void Insertion (int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
    }
}

void Imprimir(int n, int v[]){
    for(int i=0; i<n; i++)
        printf("%d ", v[i]);
}

int main(void){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);

    Insertion(n, v);
    Imprimir(n, v);
}
