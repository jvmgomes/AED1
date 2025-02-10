//João Vitor Moreira Gomes RA:176536
#include <stdio.h>
#include <stdlib.h>

typedef struct ListaCelula
{
    int valor;
    struct ListaCelula *next;
}ListaCelula;

typedef struct ListadoIndice
{
    struct ListaCelula *lista;
}ListadoIndice;

typedef struct TabelaHash
{
    int indice;
    struct ListadoIndice *tabela;
}TabelaHash;

void inicializalista(ListadoIndice *l)
{
    l->lista = NULL;
}

void inicializaTabela(TabelaHash *tabela, int indice)
{
    tabela->indice = indice;
    tabela->tabela = (ListadoIndice *)malloc(indice * sizeof(ListadoIndice));

    for(int i=0; i<indice; ++i)
    {
        inicializalista(&(tabela->tabela[i]));
    }
}

int funcaoHash(TabelaHash *tabela, int valor)
{
    return valor % tabela->indice;
}

ListaCelula *insereElementoCelula(ListaCelula *atual, int valor)
{
    if(atual == NULL)
    {
        ListaCelula *nova = malloc(sizeof(ListaCelula));
        nova->valor = valor;
        nova->next = NULL;

        return nova;
    }
    else
    {
        atual->next = insereElementoCelula(atual->next, valor);
        return atual;
    }
}

void insereElementoLista(ListadoIndice *l, int valor)
{
    if(l == NULL)
    {
        l = (ListadoIndice *)malloc(sizeof(ListadoIndice));
    }
    l->lista = insereElementoCelula(l->lista, valor);
}
void insereElementoTabela(TabelaHash *tabela, int valor)
{
    int indice = funcaoHash(tabela, valor);
    insereElementoLista(&(tabela->tabela[indice]), valor);
}


void imprimeLista(ListadoIndice *l)
{
    if (l != NULL)
    {
        ListaCelula *atual = l->lista;

        while (atual != NULL)
        {
            printf("%d -> ", atual->valor);
            atual = atual->next;
        }
    }

    printf("\\\n");
}

void imprimeTabelaHash(TabelaHash *tabela)
{
    for (int i = 0; i < tabela->indice; ++i)
    {
        printf("%d -> ", i);
        imprimeLista(&(tabela->tabela[i]));
    }
}

void LimpaCelula(ListaCelula *atual)
{
    if (atual->next != NULL)
    {
        LimpaCelula(atual->next);
    }

    free(atual);
}

void LimpaLista(ListadoIndice *l)
{
    if (l->lista != NULL)
    {
        LimpaCelula(l->lista);
    }
}

void LimpaTabela(TabelaHash *tabela)
{
    for (int i = 0; i < tabela->indice; ++i)
    {
        LimpaLista(&(tabela->tabela[i]));
    }

    tabela->indice = 0;
    free(tabela->tabela);
}



int main(void)
{
    int n, m, c, num;
    TabelaHash th;

    scanf("%d", &n);

    for(int i=0; i<n; ++i)
    {   
        if(i)
            printf("\n");

        scanf("%d %d", &m, &c);

        inicializaTabela(&th, m);
        for(int i=0; i<c; ++i)
        {
            scanf("%d", &num);

            insereElementoTabela(&th, num);
        }
        imprimeTabelaHash(&th);

        LimpaTabela(&th);
    }
}
