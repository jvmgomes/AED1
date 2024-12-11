//João Vitor Moreira Gomes - RA:176536
#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *next;
}celula;

void Insere_fila(int y, celula *head){
    celula *nova_fila = malloc(sizeof(celula));
    
    
    nova_fila->valor = y;
    nova_fila->next = NULL;
    
    celula *p = head; //inserção dos numeros no final da lista
    while(p->next != NULL)
        p = p->next;

    p->next = nova_fila;  
}

int Remove(celula *head){
    if(head->next != NULL){
        celula *p = head->next;
        head->next = p->next;
        int x = p->valor;
        free(p);
        return x;
    }
}

void Inserir_pilha(int y, celula *head){
    celula *nova_pilha = malloc(sizeof(celula));
    nova_pilha->valor = y;
    nova_pilha->next = head->next; 
    head->next = nova_pilha;
}

void Inserir_fila_p(int y, celula *head){
    celula *nova_fila_p = malloc(sizeof(celula));
    nova_fila_p->valor = y;
    if(head->next == NULL || head->next->valor < y){
        nova_fila_p->next = head->next;
        head->next = nova_fila_p;
    } else {
        celula *p = head->next;
        while(p->next != NULL && p->next->valor >= y){
            p = p->next;
        }
        nova_fila_p->next = p->next;
        p->next = nova_fila_p;
    }

}

int main(void){
    int n, comando, num, is_queue, is_stack, is_queue_p;
    celula *fila = malloc(sizeof(celula));
    fila->next = NULL;

    celula *pilha = malloc(sizeof(celula));
    pilha->next = NULL;

    celula *fila_p = malloc(sizeof(celula));
    fila_p->next = NULL;

    is_queue = 1;
    is_stack = 1;
    is_queue_p = 1;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &comando);
        if(comando == 1){
            scanf("%d", &num);
            Insere_fila(num, fila);
            Inserir_pilha(num, pilha);
            Inserir_fila_p(num, fila_p);
        } else if(comando == 2){
            scanf("%d", &num);
            if(fila == NULL || Remove(fila) != num)
                is_queue = 0;
            if(pilha == NULL || Remove(pilha) != num)
                is_stack = 0;            
            if(fila_p == NULL || Remove(fila_p) != num)
                is_queue_p = 0;
        }
    }
    if(is_queue + is_stack + is_queue_p > 1)
        printf("not sure\n");
    else if (is_stack) 
        printf("stack\n");
    else if(is_queue)
        printf("queue\n");
    else if (is_queue_p)
        printf("priority queue\n");
    else 
        printf("impossible\n");
    
    return 0;
}
