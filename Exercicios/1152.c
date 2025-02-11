//João Vitor Moreira Gomes RA:176536
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, peso;
}aresta;

int compararArestas(const void *a, const void *b)
{
    return ((aresta *)a)->peso - ((aresta *)b)->peso;
}

int find(int pai[], int x)
{
    if(pai[x] != x)
    {
        pai[x] = find(pai, pai[x]);
    }

    return pai[x];
}

void unirConjunto(int pai[], int rank[], int x, int y)
{
    int raizX = find(pai, x);
    int raizY = find(pai, y);

    if (raizX != raizY)
    {
        if (rank[raizX] > rank[raizY])
        {
            pai[raizY] = raizX;
        } else if (rank[raizX] < rank[raizY]) {
            pai[raizX] = raizY;
        } else {
            pai[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

int main(void){
    int m, n;
    while(scanf("%d %d", &m, &n) && (m != 0 || n != 0))
    {
        aresta arestas[n]; //cria vetor de n arestas do tipo aresta
        int custoTotal = 0; //custo total gato pelo grafo

        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso); //(u.v) par não ordenado, aresta
            custoTotal += arestas[i].peso;
        }
        qsort(arestas, n, sizeof(aresta), compararArestas);
    
        int pai[m], rank[m];
        for(int i=0; i<m; i++)
        {
            pai[i] = i;
            rank[i] = 0;
        }

        int mstCusto = 0; //Custo total da arvore geradora minima
        for(int i=0; i<n; i++)
        {
            if(find(pai, arestas[i].u) != find(pai, arestas[i].v))
            {
                unirConjunto(pai, rank, arestas[i].u, arestas[i].v);
                mstCusto += arestas[i].peso;
            }
            printf("%d\n", custoTotal - mstCusto);
        }
    }

    return 0;
}
