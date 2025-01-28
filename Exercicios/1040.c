#include <stdio.h>

int main(){
    float nota1, nota2, nota3, nota4, resultado, recuperacao;
    
    scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
    
    resultado = (nota1*2 + nota2*3 + nota3*4 + nota4*1) / 10;
    printf("Media: %.1f\n", resultado);
    
    if(resultado >= 7){
        printf("Aluno aprovado.\n");
    }
    else if(resultado < 5){
        printf("Aluno reprovado.\n");
    }
    else if(5 <= resultado && resultado <= 6.9){
        printf("Aluno em exame.\n");
        scanf("%f", &recuperacao);
        printf("Nota do exame: %.1f\n", recuperacao);
        resultado = (resultado + recuperacao) / 2;
        if(resultado >= 5){
            printf("Aluno aprovado.\n");
        }
        else if(resultado <= 4.9){
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n", resultado);
    }
    return 0;
}
