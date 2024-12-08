//João Vitor Moreira Gomes - RA:176536
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel{

    int presente;
    struct cel *next;
};

typedef struct cel celula;

void inserir(int y, celula *p){
    
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->presente = y;
    nova->next = p->next;
    p->next = nova;
}

void removerPilha(celula *p) {
    if (p->next != NULL) {
        celula *lixo = p->next;
        p->next = lixo->next;
        free(lixo);
    }
}

int main(void){
    celula *head = malloc(sizeof(celula));
    head->next = NULL;

    celula *menorAtual = malloc(sizeof(celula));
    menorAtual->next = NULL;

    char frase[20], push[20] = "PUSH", min[20] = "MIN", pop[20] = "POP";
    int n, k;
    scanf("%d", &n);
    getchar();

    for(int i=0; i<n; i++){
        scanf("%s", &frase);
        if(strcmp(frase, push) == 0){
            scanf("%d", &k);
            inserir(k, head);
            if(menorAtual->next == NULL || k <= menorAtual->next->presente)
                inserir(k, menorAtual);
        }
        else if(strcmp(frase, min) == 0){
            if(menorAtual->next != NULL)
                printf("%d\n", menorAtual->next->presente);
            else
                printf("EMPTY\n");
        }
            
        else if(strcmp(frase, pop) == 0){
            if(head->next == NULL)
                printf("EMPTY\n");
            else if(head->next->presente == menorAtual->next->presente)
                removerPilha(menorAtual);
            removerPilha(head);
        }
    }
    free(head);

    return 0;
}
