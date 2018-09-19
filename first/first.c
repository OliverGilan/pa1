#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int numberCount;
FILE *input;

int * seperateEvenOdd(int numbers[], int size);
int * sort(int *numbers, int *size);
void swap(int *a, int *b);

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
        printf("Could not open file!");
        return 1;
    }else{
        printf("File Opened \n");
    }

    //Gets item count from file and creates array
    rewind(input);
    char count = fgetc(input);
    numberCount = count - '0';
    printf("COUNT: %d \n", numberCount);
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

    for(int i=0;i<numberCount;i++){
        printf("Seperated Array[%d] is %d \n", i, array[i]);
    }
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
        if(numbers[i]%2==0 && numbers[i] != 0){
            even[j]=numbers[i];
            j++;
        }else{
            odd[k]=numbers[i];
            k++;
        }
    }

    // for(int i=0;i<j;i++){
    //     printf("E[%d] is %d, j = %d \n", i, even[i], j);
    // }
    // for(int i=0;i<k;i++){
    //     printf("O[%d] is %d, k = %d \n", i, odd[i], k);
    // }

    even = sort(even, &j);
    odd = sort(odd, &k);

    // for(int i=0;i<j;i++){
    //     printf("Sorted Even[%d] is %d, j = %d \n", i, even[i], j);
    // }
    // for(int i=0;i<k;i++){
    //     printf("Sorted Odd[%d] is %d, k = %d \n", i, odd[i], k);
    // }

    //Combines both sorted arrays back into one array
    for(int i=0; i<j;i++){
        numbers[i]=even[i];
        printf("Numbers[i]= %d \n", numbers[i]);
    }
    int l = 0;
    for(int i=j; i<j+k;i++){
        numbers[i]=odd[l];
        l++;
        printf("Numbers[i]=%d \n", numbers[i]);
    }

    return numbers;
}

//Sorts a given array in ascending order using bubble sort
int * sort(int *numbers, int *size){
    for(int i=0; i<*size;i++){
        for(int j=0; j<*size-1;j++){
            if(numbers[j] > numbers[j+1]){
                swap(&numbers[i],&numbers[i+1]);
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
