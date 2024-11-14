#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 999 

typedef struct cel celula;
struct cel
{
    char *lista;
    struct cel *next;
    
};

void inserir(char *compra, celula *head) {
    celula *nova = malloc(sizeof(celula));
    nova->lista = malloc(strlen(compra));
    strcpy(nova->lista, compra);
    nova->next = NULL;


    celula *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = nova;
}

/*void imprimir(celula *head){
    celula *p;
    for(p = head->next; p != NULL; p = p->next)
        printf ("%s\n", p->lista);

}
*/
void imprimir(celula *head) {
    celula *p = head->next;
    int first = 1;  // Variável para controle de espaço entre as palavras

    while (p != NULL) {
        if (!first) {
            printf(" ");
        }
        printf("%s", p->lista);
        first = 0;
        p = p->next;
    }
    printf("\n");
}


void buscaRemove(celula *head){
    celula *p, *q, *lixo;
    for(p = head->next; p != NULL && p->next != NULL; p = p->next){
        q = p;
        while(q->next != NULL){
            if(strcmp(p->lista, q->next->lista) == 0){
                lixo = q->next;
                q->next = lixo->next;
                free(lixo->lista);
                free(lixo);
            } else{
                q = q->next;

            }
        }
    }       
}
int main(void){
    int n;
    char compra[MAX];
    char *item;

    scanf("%d", &n);
    getchar();
    

 
    for(int i=0; i<n; i++){
        fgets(compra, MAX, stdin);
        celula *head;
        head = malloc(sizeof(celula));
        head->next = NULL;

        item = strtok(compra, " ");
        while(item != NULL){
            inserir(item, head);
            item = strtok(NULL, " ");
        }
        buscaRemove(head);
        imprimir(head);
        
        celula *p = head;
        while (p != NULL) {
            celula *temp = p;
            p = p->next;
            free(temp->lista);
            free(temp);
        }
    }       


    return 0;
}
