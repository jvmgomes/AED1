//João Vitor Moreira Gomes - RA:176536
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void Insertion (int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
    }
}

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

void GeraVetorAleatorio(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10000; // Valores aleatórios entre 0 e 9999
    }
}

int main(void) {
    int n, *v, *copia, *copia_dois;
    clock_t inicio, fim; // Variáveis para medir o tempo
    double tempo_insertion, tempo_merge, tempo_quick;
     
    scanf("%d", &n);

    v = malloc(n * sizeof(int));
    copia = malloc(n * sizeof(int)); // Para manter uma cópia do vetor original
    for (int tamanho = 0; tamanho <= n; tamanho += 20000) {
        GeraVetorAleatorio(tamanho, v);

        // Copia o vetor para ser reutilizado
        for (int i = 0; i < tamanho; i++) copia[i] = v[i];

        inicio = clock();
        Insertion(tamanho, v);
        fim = clock();
        tempo_insertion = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Restaurar o vetor original
        for (int i = 0; i < tamanho; i++) v[i] = copia[i];

        inicio = clock();
        Mergesort(0, tamanho, v);
        fim = clock();
        tempo_merge = (double)(fim - inicio) / CLOCKS_PER_SEC;

        for(int i = 0; i < tamanho; i++) v[i] = copia[i];

        inicio = clock();
        Quicksort(0, tamanho, v);
        fim = clock();
        tempo_quick = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("%d %.6f %.6f %.6f\n", tamanho, tempo_insertion, tempo_merge, tempo_quick);
    }

    free(v);
    free(copia);
    return 0;
}
