#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

typedef struct cel{
    char lista[MAX];
    struct cel *next;
}celula;

void inserir(char aluno[], celula *head){
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->lista, aluno);
    nova->next = NULL;
  
  
    celula *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = nova;

}
void organiza(celula *head) {
    celula *p, *q;
    char temp[21];
    for (p = head->next; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(p->lista, q->lista) > 0) {
                strcpy(temp, p->lista);
                strcpy(p->lista, q->lista);
                strcpy(q->lista, temp);
            }
        }
    }
}

void liberarLista(celula *head) {
    celula *p = head;
    while (p != NULL) {
        celula *temp = p;
        p = p->next;
        free(temp);
    }
}

int main(void){

    celula *head = malloc(sizeof(celula));
    head->next = NULL;
    
    int k, n;
    scanf("%d %d", &n, &k);
    getchar();
    
    char aluno[21];
    //laco para inserir    
    for (int i = 0; i < n; i++) {
        gets(aluno);
        inserir(aluno, head);

    }    
    organiza(head);

    celula *p = head;
    for(int i = 0; i<=k; i++){
        if(i == k)
            printf("%s\n", p->lista);
        else
            p = p->next;     
    }

    liberarLista(head);
    return 0;
}
