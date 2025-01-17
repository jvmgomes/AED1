//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int main(){
    double num;
    int positivos = 0;

    for(int i=0; i<6; i++){
        scanf("%lf", &num);
        if(num != 0){
            if(num > 0){
                positivos++;
            }
        }
    }
    printf("%d valores positivos\n", positivos);


    return 0;
}
