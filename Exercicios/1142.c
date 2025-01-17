//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        if(i % 4 == 0){
            printf("PUM");
        }
        else{
            printf("%d", i);
        }

    }

    return 0;
}
