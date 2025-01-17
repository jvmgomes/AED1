//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int main(){
    double num, media;
    int positivos = 0;

    for(int i=0; i<6; i++){
        scanf("%lf", &num);
        if(num != 0){
            if(num > 0){
                positivos++;
                media += num;
            }
        }
    }
    media = media / positivos;
    printf("%d valores positivos\n", positivos);
    printf("%lf\n", media);


    return 0;
}
