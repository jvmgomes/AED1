//João VItor Moreira Gomes RA:176536
#include <stdio.h>
#include <string.h>

int main() {
    char jon[1001], medico[1001];

    // Lê as entradas
    scanf("%s", jon);
    scanf("%s", medico);

    // Calcula os comprimentos das partes "a" de cada string
    int len_jon = strlen(jon) - 1; // Subtrai 1 para ignorar o 'h'
    int len_medico = strlen(medico) - 1; // Subtrai 1 para ignorar o 'h'

    // Compara os comprimentos
    if (len_jon >= len_medico) {
        printf("go\n");
    } else {
        printf("no\n");
    }

    return 0;
}
