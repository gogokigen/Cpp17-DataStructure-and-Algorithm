#include <stdio.h>

int main(){
    int **matrix;
    int r = 50, c = 40, i = 0, j = 0, k = 0;
    

    matrix = (int**)malloc(sizeof(int*) * r);
    for(int i = 0; i < r; i++){
        matrix[i] = (int*)malloc(sizeof(int)*c);
    }


    for(int j = 0; j < r; j++){
        for(int k = 0; k < c; k++){
            matrix[j][k] =  j + k;
        }
    }
    for(int j = 0; j < r; j++){
        for(int k = 0; k < c; k++){
            printf("matrix[%d][%d] = %d \n", j, k, matrix[j][k] );
        }
    }
    return 0;
}
