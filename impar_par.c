#include <stdio.h>

int impar_par(int n){
    for(int i=0; i<n; i++){
        if(n%2==0){
            return "par";
        }
        else{
            return "impar";
        }
    }

}

int main(void){
    int n;
    printf("Digite um numero:\n ");
    scanf("%d", &n);
    printf("Esse numero eh %s", impar_par(n));

    return 0;
}
