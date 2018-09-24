#include <stdio.h>
#include <stdlib.h>

void clean(int **, int, int);

int main(int argc, char **argv){
    FILE *input = fopen(argv[1], "r");
    if(input == NULL){
        printf("%s", "error");
        return 0;
    }
    //first matrix
    int a, b;
    fscanf(input, "%d %d", &a, &b);
    // int matrixOne[a][b];
    int **matrixOne = malloc(a*sizeof(*matrixOne));
    for(int i = 0; i<a;i++){
        matrixOne[i] = malloc(b*sizeof(*matrixOne[i]));
        for(int j = 0; j<b;j++){
            //Allocates and reads file into array spot
            // matrixOne[i][j] = (int)malloc(1*sizeof(int));
            fscanf(input, "%d", &matrixOne[i][j]);
            // printf("%d", matrixOne[i][j]);
        }
    }

    // for(int i=0;i<a;i++){
    //     for(int j = 0; j<b;j++){
    //         printf("matrixOne[%d][%d] = %d\n", i, j, matrixOne[i][j]);
    //     }
    // }

    //second matrix
    int c, d;
    fscanf(input, "%d %d", &c, &d);
    // int matrixTwo[c][d];
    int **matrixTwo = malloc(c*sizeof(*matrixTwo));
    // printf("CD: %d %d\n", c, d);
    for(int i = 0; i<c;i++){
        matrixTwo[i] = malloc(d*sizeof(*matrixTwo[i]));
        for(int j = 0; j<d;j++){
            //Allocates and reads file into array spot
            // matrixTwo[i][j] = (int)malloc(1*sizeof(int));
            fscanf(input, "%d", &matrixTwo[i][j]);
            // printf("%d", matrixTwo[i][j]);
        }
    }

    if(b!=c){
        printf("bad-matrix\n");
        clean(matrixOne, c, d);
        clean(matrixTwo, c, d);
        return 0;
    }

    // for(int i=0;i<c;i++){
    //     for(int j = 0; j<d;j++){
    //         printf("matrix2[%d][%d] = %d\n", i, j, matrixTwo[i][j]);
    //     }
    // }

    //Multiply matrices
    int **mtx = malloc(a*sizeof(*mtx));
    for(int i = 0; i<a;i++){
        mtx[i] = malloc(d*sizeof(*mtx[i]));
        for(int j=0;j<d;j++){
            // mtx[i][j] = (int)malloc(1*sizeof(int));
            int z = 0;
            for(int k=0;k<c;k++){
                z += matrixOne[i][k] * matrixTwo[k][j];
            }
            mtx[i][j]=z;
            printf("%d\t", mtx[i][j]);
        }
        printf("\n");
    }
    clean(matrixOne, a, b);
    clean(matrixTwo, c, d);
    clean(mtx, a, d);

    return 0;
}

void clean(int **matrix, int x, int y){
    for(int i=0;i<x;i++){
        free(matrix[i]);
    }
    free(matrix);
}