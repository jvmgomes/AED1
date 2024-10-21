#include <stdio.h>

int primo(int n){
    int tipo;
    for(int i=2; i<n; i++){
        if(n%i==0){
            return 0;
        }
        else{
            tipo = 1;
        }
    }
    return tipo;

}

int main(void){
    int n;
    printf("Digite um numero:\n ");
    scanf("%d", &n);
    int result = primo(n);
    if(result==1)
        printf("Esse numero eh primo");
    else
        printf("Esse numero nao eh primo");   

    return 0;
}
