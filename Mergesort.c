#include <stdio.h>
#include <stdlib.h>

void Intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) 
            w[k++] = v[i++];
        else 
            w[k++] = v[j++];
    }
    while (i < q) 
        w[k++] = v[i++];
    while (j < r) 
        w[k++] = v[j++];
    for (i = p; i < r; i++) 
        v[i] = w[i-p];
    free (w);
}
void Mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        Mergesort (p, q, v);
        Mergesort (q, r, v);
        Intercala (p, q, r, v);
    }
}

void Imprimir(int n, int v[]){
    for(int i=0; i<n; i++)
        printf("%d ", v[i]);
}

int main(void){
    int n, p;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);

    p = 0;

    Mergesort(p, n, v);
    Imprimir(n, v);

}
