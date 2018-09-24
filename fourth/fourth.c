#include <stdio.h>
#include <stdlib.h>

int *multiply(int, int, int *, int *);

int main(int argc, char **argv){
    FILE *input = fopen(argv[1], "r");
    if(input == NULL){
        printf("%s", "error");
        return 0;
    }
    //first matrix
    int a, b;
    fscanf(input, "%d %d", &a, &b);
    int matrixOne[a][b];
    for(int i = 0; i<a;i++){
        for(int j = 0; j<b;j++){
            //Allocates and reads file into array spot
            matrixOne[i][j] = (int)malloc(1*sizeof(int));
            fscanf(input, "%d", &matrixOne[i][j]);
            printf("%d", matrixOne[i][j]);
        }
    }

    for(int i=0;i<a;i++){
        for(int j = 0; j<b;j++){
            printf("matrixOne[%d][%d] = %d\n", i, j, matrixOne[i][j]);
        }
    }

    //second matrix
    int c, d;
    fscanf(input, "%d %d", &c, &d);
    int matrixTwo[c][d];
    printf("CD: %d %d\n", c, d);
    for(int i = 0; i<c;i++){
        for(int j = 0; j<d;j++){
            //Allocates and reads file into array spot
            matrixTwo[i][j] = (int)malloc(1*sizeof(int));
            fscanf(input, "%d", &matrixTwo[i][j]);
            printf("%d", matrixTwo[i][j]);
        }
    }

    for(int i=0;i<c;i++){
        for(int j = 0; j<d;j++){
            printf("matrix2[%d][%d] = %d\n", i, j, matrixTwo[i][j]);
        }
    }

    //Multiply matrices
    int mtx[a][d];
    for(int i = 0; i<a;i++){
        for(int j=0;j<d;j++){
            mtx[i][j] = (int)malloc(1*sizeof(int));
            for(int m = i; m<a;m++){
                int z = 0;
                for(int n = 0; n<b;n++){
                    // printf("BEFORE: %d\n", matrixOne[m][n]);
                    z += matrixOne[m][n] * matrixTwo[n][m];
                    // printf("AFTER: %d\n", matrixTwo[n][m]);
                }
                // printf("Z: %d\n", z);
                mtx[i][j] = z;
                break;
            }
            printf("%d\t", mtx[i][j]);
        }
        // printf("\n");
    }

    // int *finalMtx = multiply(a, d, &matrixOne, &matrixTwo);

    return 0;
}

// int * multiply(int x, int y, int *mtx1, int *mtx2){
//     int finalMtx[x][y];

    
// }