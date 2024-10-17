#include <stdio.h>

int hm(int *minutos, int *horas) {
    int t;

    if(*minutos >= 60) {
        *horas = *minutos / 60;
        t = *minutos % 60;
        printf("Isso corresponde a %d horas e %d minutos", *horas, t);
    }
    else {
        t = *minutos;
        printf("Isso corresponde a %d minutos", t);
    }
    return t;
}

int main(void){
    int m, h=0;

    printf("Digite os minutos totais:\n");
    scanf("%d", &m);

    int *minutos=&m;
    int *horas=&h;

    int result = hm(minutos, horas);
    return 0;
}
