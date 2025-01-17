//João Vitor Moreira Gomes - RA:176536
#include <stdio.h>

int main(void){
    int N, res;
    scanf("%d", &N);
    for(int i=1;i<11;i++){
        res = N * i;
        printf("%d x %d = %d\n", i, N, res);
    }
    return 0;
}
