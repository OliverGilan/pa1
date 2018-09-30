#include <stdio.h>
#include <stdlib.h>

int addRows(int **, int, int);
int addCols(int **, int, int);
int addDiags(int **, int, int);
void clean(int **, int);
int checkNums(int **, int);

int main(int argc, char **argv){
    FILE* input = fopen(argv[1], "r");
    if(input == NULL){
        printf("%s", "error");
        return 0;
    }
    int n = 0;
    fscanf(input, "%d", &n);
    
    int **matrix = malloc(n*sizeof(matrix));
    for(int i = 0; i<n;i++){
        matrix[i]=malloc(n*sizeof(matrix[i]));
        for(int j =0; j<n;j++){
            fscanf(input, "%d", &matrix[i][j]);
        }
    }
    fclose(input);

    // for(int i = 0; i<n;i++){
    //     for(int j =0; j<n;j++){
    //         printf("%d  ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    int rtotal = 0;
    for(int i = 0; i<n; i++){
        rtotal += matrix[0][i];
    }

    int result = addRows(matrix, n, rtotal);
    if(result != 1){
        printf("not-magic");
        return 0;
    }

    result = addCols(matrix, n, rtotal);
    if(result != 1){
        printf("not-magic");
        return 0;
    }

    result = addDiags(matrix, n, rtotal);
    if(result != 1){
        printf("not-magic");
        return 0;
    }
    result = checkNums(matrix, n);
    if(result != 1){
        printf("not-magic");
        return 0;
    }

    printf("magic");
    clean(matrix, n);

    return 0;
}

int addRows(int **mtx, int n, int total){
    int rtotal = 0;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            rtotal += mtx[i][j];
        }
        if(rtotal != total){
            return 0;
        }
        rtotal = 0;
    }
    return 1;
}

int addCols(int **mtx, int n, int total){
    int ctotal = 0;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            ctotal += mtx[j][i];
        }
        if(ctotal != total){
            return 0;
        }
        ctotal = 0;
    }
    return 1;
}

int addDiags(int **mtx, int n, int total){
    int dtotal = 0;
    for(int i = 0; i<n; i++){
        dtotal += mtx[i][i];
    }

    if(dtotal != total){
        return 0;
    }
    dtotal = 0;

    for(int i = 0; i<n; i++){
        dtotal += mtx[i][n-i-1];
    }

    if(dtotal != total){
        return 0;
    }
    return 1;
}

void clean(int **mtx, int n){
    for(int i =0; i<n; i++){
        free(mtx[i]);
    }
    free(mtx);
}

int checkNums(int **mtx, int n){
    // printf("running\n");
    int size = n * n;
    int *array = (int *)malloc(size*sizeof(int));
    int k = 0;
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            array[k] = mtx[i][j];
            k++;
            // printf("%d\n", mtx[i][j]);
            // printf("%d\n", array[k]);
        }
    }
    // for(int i=0;i<n; i++){
    //     for(int j=0;j<n;j++){

    //     }
    // }
    for(int i=0; i < n*n-1; i++){
        for(int j = i+1; j<n*n; j++){
            if(array[i] == array[j]){
                return 0;
            }
        }
    }
    return 1;
}