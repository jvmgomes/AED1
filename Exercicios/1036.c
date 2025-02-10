//João Vitor Moreira Gomes RA:176536
#include <stdio.h>
#include <math.h> 
 
int main() {
 
    double a, b, c, r1, r2;
    scanf("%lf %lf %lf", &a, &b, &c);
    
    r1 = (-b + sqrt(b*b-4*a*c))/(2*a);
    r2 = (-b - sqrt(b*b-4*a*c))/(2*a);
    
    if(2*a==0 || (b*b-4*a*c)<0){
        printf("Impossivel calcular\n");
    }
    else{
        printf("R1 = %.5lf\n", r1);
        printf("R2 = %.5lf\n", r2);
    }
    
    return 0;
}
