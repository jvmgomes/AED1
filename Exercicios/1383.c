//João Vitor Moreira Gomes RA:176536
#include <stdio.h>

int rowcheck(int mat[9][9], int row){
    int achar[10] = {0};
    for(int j=0; j<9; j++){
        int numero = mat[row][j];
        if(numero<1 || numero>9 || achar[numero]==1)
            return 0;
        achar[numero] = 1;
    }
    return 1;
}

int colcheck(int mat[9][9], int col){
    int achar[10] = {0};
    for(int i=0; i<9; i++){
        int numero = mat[i][col];
        if(achar[numero] == 1)
            return 0;
        achar[numero] = 1;
    }
    return 1;
}

int threecheck(int mat[9][9], int row_menor, int col_menor){
    int achar[10] = {0};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int numero = mat[row_menor + i][col_menor + j];
            if(achar[numero]==1)
                return 0;
            achar[numero] = 1;
        }
    }
    return 1;
}   

int isValid(int mat[9][9]){

    for(int i=0; i<9; i+=3){
        for(int j=0; j<9; j+=3){
            if(!threecheck(mat, i, j)){
                return 0; 
            }
        }
    }
    for(int j=0; j<9; j++){
        if(!colcheck(mat, j)){
            return 0;
        }
    }

    for(int i=0; i<9; i++){
        if(!rowcheck(mat, i)){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int k, i, j, m;
    scanf("%d", &k);

    int mat[k][9][9];

    for(m = 0; m<k; m++){
        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                scanf("%d", &mat[m][i][j]); /*vetor de matriz para guardar as instancias*/
            }
        }
    

        printf("Instancia %d\n", m+1);
        if(isValid(mat[m]))
            printf("SIM\n");
        else
            printf("NAO\n");
    }
    return 0;
}
