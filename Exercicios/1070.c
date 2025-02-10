//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int main(void){
    int x;
    scanf("%d", &x);
    for(int i=x; i<x+12; i++)
        if(i%2!=0){
            printf("%d\n", i);
        }
    return 0;
}
