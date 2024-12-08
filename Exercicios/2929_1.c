//Menos eficiente
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel{

    int presente;
    struct cel *next;
};

typedef struct cel celula;

void inserir(int num, celula *head){
    celula *nova = malloc(sizeof(celula));
    nova->presente = num;
    nova->next = NULL;

    celula *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = nova;
}

int retornaMenor(celula *head){
    celula *p = head->next;
    if(p == NULL)
        return -1;
    int menor = p->presente;
    for(; p != NULL; p = p->next){

        if(p->presente < menor){
            menor = p->presente;
        }
    }
    return menor;
}

void removerPilha(celula *head){
    if(head->next == NULL)
        return;
    
    celula *p = head;
    celula *q = NULL;

    while(p->next != NULL){
        q = p;
        p = p->next;

    }

    if(q != NULL)
        q->next = NULL;

    free(p);
    
}

int main(void){
    celula *head = malloc(sizeof(celula));
    head->next = NULL;

    char frase[20], push[20] = "PUSH", min[20] = "MIN", pop[20] = "POP";
    int n, k;
    scanf("%d", &n);
    getchar();

    for(int i=0; i<n; i++){
        scanf("%s", &frase);
        if(strcmp(frase, push) == 0){
            scanf("%d", &k);
            inserir(k, head);
        }
        else if(strcmp(frase, min) == 0)
            if(head->next == NULL)
                printf("EMPTY\n");
            else    
                printf("%d\n", retornaMenor(head));
        else if(strcmp(frase, pop) == 0)
            removerPilha(head);
        else
            printf("EMPTY\n");
            
    }
    free(head);

    return 0;
}
