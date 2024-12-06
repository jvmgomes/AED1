//João VItor Moreira Gomes - RA: 176536
#include <stdio.h>

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++)
        if (v[k] <= c) {
        t = v[j], v[j] = v[k], v[k] = t;
        j++;
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void Quicksort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
    }
}

void Imprimir(int n, int v[]){
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);

    Quicksort(0, n, v);
    Imprimir(n, v);


    return 0;
}
