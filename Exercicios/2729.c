#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21001

typedef struct cel celula;
struct cel {
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

void imprimir(celula *head) {
    celula *p;
    for (p = head->next; p != NULL; p = p->next) {
        if (p->next == NULL)
            printf("%s\n", p->lista);
        else
            printf("%s ", p->lista);
    }
}

void removeDuplicados(celula *head) {
    celula *p, *q, *lixo;
    for (p = head->next; p != NULL && p->next != NULL; p = p->next) {
        q = p;
        while (q->next != NULL) {
            if (strcmp(p->lista, q->next->lista) == 0) {
                lixo = q->next;
                q->next = lixo->next;
                free(lixo);
            } else {
                q = q->next;
        
            }
        }
    }
}

void organiza(celula *head) {
    celula *p, *q;
    for (p = head->next; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(p->lista, q->lista) > 0) {
                char temp[MAX];
                strcpy(temp, p->lista);
                strcpy(p->lista, q->lista);
                strcpy(q->lista, temp);
            }
        }
    }
}

int main(void) {
    int n;
    char compra[MAX];
    char *item;

    celula *head = malloc(sizeof(celula));
    head->next = NULL;

    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        fgets(compra, MAX, stdin);
        compra[strcspn(compra, "\n")] = '\0';

        item = strtok(compra, " ");
        while (item != NULL) {
            inserir(item, head);
            item = strtok(NULL, " ");
        }
        removeDuplicados(head);
        organiza(head);

        imprimir(head);

        celula *temp;
        while (head->next != NULL) {
            temp = head->next;
            head->next = temp->next;
            free(temp);

        }
    }

    free(head);
    return 0;
}
