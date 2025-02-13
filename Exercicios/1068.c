//João Vitor Moreira Gomes RA:176536
#include <string.h>
#include <stdio.h>

int main(){
    char express[1001];
    int i, tam, parenteses;

    while(scanf("%s\n", &express) != EOF){
        parenteses = 0;
        tam = strlen(express);

        for(i = 0; i < tam; ++i){
            if(express[i] == '('){
                ++parenteses;
            }else if(express[i] == ')'){
                if(parenteses > 0)  --parenteses;
                else                break;
            }
        }

        if(i == tam && parenteses == 0) printf("correct\n");
        else                            printf("incorrect\n");
    }

    return 0;
}
