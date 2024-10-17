#include <stdio.h>

int main(void) {
    FILE *arquivo;
    char nome[30];
    arquivo = fopen("arquivo_teste", "w");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Escreva o nome de alguem\n");
    scanf("%s", nome);

    fprintf(arquivo, "%s", nome);

    fclose(arquivo);
    printf("Dados gravados com sucesso!");
    return 0;
}
