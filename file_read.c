#include <stdio.h>
#include <errno.h> /*biblioteca de erros possiveis de acontecer envolvendo arquivos*/

int main(void) {
    FILE *arquivo;
    arquivo = fopen("arquivo_teste", "r");
    int num;
    if(arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    else {
        while(fscanf(arquivo, "%d", &num) != EOF) {
            if(errno)
                perror("Erro na leitura do arquivo");
            else
                fprintf(stdout, "Numero %d\n", num);
        }
    }
    fclose(arquivo);
    return 0;
}
