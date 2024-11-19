#include <stdio.h>
#include <stdlib.h>

typedef struct cel celula;
struct cel {
    int valor;
    struct cel *next;
};

void inserir(int num, celula *head){
    celula *nova = malloc(sizeof(celula));
    
    
    nova->valor = num;
    nova->next = NULL;
    
    celula *p = head; //inserção dos numeros no final da lista
    while(p->next != NULL)
        p = p->next;

    p->next = nova;    
}

void busca_remove (int num, celula *head){
    celula *p = head;
    celula *q = head->next;

    while(p != NULL && p->valor != num){    //quando p->valor igual num ele para e o remove
        q=p;
        p = p->next;
    }
    
    if(p != NULL){
        q->next = p->next;
        free(p);    
    }
}

void imprimir(celula *head){
    celula *p;
    for(p = head->next; p != NULL; p = p->next){
        if(p->next == NULL)
            printf("%d\n", p->valor);
        else
            printf("%d ", p->valor);
    }

}

int main(void){
    int n, m, num_n, num_m; /*n é o numero de pessoas na fila e m o numero de pessoas que saem da fila*/

    celula *head = (celula *)malloc(sizeof(celula)); //gera uma cabeça
    head->next = NULL;

    scanf("%d", &n); 
    for(int i=0; i<n; i++){
        scanf("%d", &num_n);
        inserir(num_n, head); //inserção dos itens na lista encadeada
    }

    scanf("%d",&m);
    for(int j=0; j<m; j++){
        scanf("%d",&num_m);
        busca_remove(num_m, head); //busca dos itens dentro da lista e suas respectivas remoções
    }

    imprimir(head); //impressão da lista atualizada

    free(head);
    return 0;
}
