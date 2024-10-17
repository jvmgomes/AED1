#include <stdio.h>
#include <errno.h> /*biblioteca de erros possiveis de acontecer envolvendo arquivos*/

int main(void) {
    FILE *arquivo;
    arquivo = fopen("arquivo_teste_2", "w");
    if(arquivo == NULL) {
        perror("Erro na funcao fopen"); /* mostrara uma mensagem de erro caso algo de errado ao abrir o arquivo*/
    }
    else {
        for(int c=1; c <=10; c++) {
            fprintf(arquivo, "%d", c);
            if(errno) perror("Erro com a funcao fprintf"); /* mostrara uma mensagem de erro caso algo de errado ao gravar o arquivo*/
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    return 0;
}
