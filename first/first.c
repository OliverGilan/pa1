#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int numberCount;
FILE *input;

int * seperateEvenOdd(int numbers[], int size);
int * sort(int *, int);
void swap(int *, int *);

int main(int argc, char** argv)
{
    //Check for input file
    if(argc > 2){
        printf("Too many arguments! \n");
        return 0;
    }else if (argc < 2){
        printf("Input file needed! \n");
        return 0;
    }

    //Opens file
    input = fopen(argv[1], "r");
    if(input == NULL){
        printf("Could not open file!\n");
        return 1;
    }

    //Gets item count from file and creates array
    rewind(input);
    char count = fgetc(input);
    numberCount = count - '0';
    int *array = calloc(numberCount, sizeof(int));
    
    //Reads each character and adds it as integer to array
    for(int i = 0; i < numberCount; i++){
        fscanf(input, "%d", &array[i]);
    }
    
    //Closes file
    fclose(input);


    //Call function to seperate even and odd numbers
    //Returns sorted array of all numbers
    array = seperateEvenOdd(array, numberCount);


    //PRINTS SOLUTION
    for(int i=0;i<numberCount;i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}




//Separate evens and odds
int * seperateEvenOdd(int *numbers,int size){

    int *odd = calloc(size, sizeof(int));
    int *even = calloc(size, sizeof(int));

    int j=0;    //even counter
    int k=0;    //odd counter

    //Separates the even and odd numbers into separate arrays
    for(int i=0; i<size;i++){
        if(numbers[i]%2==0){
            even[j]=numbers[i];
            j++;
        }else{
            odd[k]=numbers[i];
            k++;
        }
    }

    // for(int i=0; i<size; i++){
    //     printf("EVEN: %d\n", even[i]);
    // }
    // for(int i=0; i<size; i++){
    //     printf("ODD: %d\n", odd[i]);
    // }
    //Sort both arrays
    even = sort(even, j);
    odd = sort(odd, k);

    // for(int i=0; i<size; i++){
    //     printf("EVEN: %d\n", even[i]);
    // }
    // for(int i=0; i<size; i++){
    //     printf("ODD: %d\n", odd[i]);
    // }

    //Combines both sorted arrays back into one array
    for(int i=0; i<j;i++){
        numbers[i]=even[i];
    }
    int l = 0;
    for(int i=j; i<j+k;i++){
        numbers[i]=odd[l];
        l++;
    }
    free(even);
    free(odd);
    return numbers;
}

//Sorts a given array in ascending order using bubble sort
int * sort(int *numbers, int size){

    for(int i=0; i<size-1;i++){
        for(int j=0; j<size-i-1;j++){
            if(numbers[j] > numbers[j+1]){
                swap(&numbers[j],&numbers[j+1]);
                // printf("SWAP %d <-> %d", numbers[j], numbers[j+1]);
            }
        }
    }
    return numbers;
}

//Swaps two array index values
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
