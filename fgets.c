//
// Created by jvmgo on 10/10/2024.
//
#include <stdio.h>

int main(void) {
    FILE *arquivo;
    char *resultado, nome[100];
    arquivo = fopen("arquivo_teste", "r");
    if(arquivo == NULL) {
        printf("Erro na leitura do arquivo");
        return 1;
    }
    while(!feof(arquivo)) {/*(!feof), enquanto nao for o fim do arquivo*/
        resultado = fgets(nome, 100, arquivo); 
        if(resultado) printf("%s", nome);
    }
    fclose(arquivo);
    
    return 0;
}
