#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int numberCount;
FILE *input;

void seperateEvenOdd(int numbers[], int size);

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
    int array[numberCount];
    memset(array, 0, numberCount);
    
    //Reads each character and adds it as integer to array
    for(int i = 0; i < numberCount; i++){
        fscanf(input, "%d", &array[i]);
    }
    
    //Closes file
    fclose(input);


    //Call function to seperate even and odd numbers
    seperateEvenOdd(array, numberCount);

    for(int i=0;i<numberCount;i++){
        printf("Array[%d] is %d \n", i, array[i]);
    }
    return 0;
}

void seperateEvenOdd(int numbers[],int size){
    //Separate evens and odds

    int *odd = calloc(size, sizeof(int));
    int *even = calloc(size, sizeof(int));

    int j=0;
    int k=0;

    for(int i=0; i<size;i++){
        if(numbers[i]%2==0){
            even[j]=numbers[i];
            j++;
        }else{
            odd[k]=numbers[i];
            k++;
        }
    }

    for(int i=0;i<j;i++){
        printf("E[%d] is %d \n", i, even[i]);
    }
    for(int i=0;i<k;i++){
        printf("O[%d] is %d \n", i, odd[i]);
    }
}
