#include <stdio.h>
#include <stdlib.h>

int numberCount;
FILE *input;

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
    int count = fgetc(input);
    printf("COUNT: %d \n", count);
    int array[count];
    
    //Reads each character and adds it as integer to array
    for(int i = 0; i<count;i++){
        int c = (int) fgetc(input);
        if(feof(input)){
            break;
        }else{
            array[i] = c;
        }
    }

    //Closes file
    fclose(input);

    for(int i=0;i<argc;i++){
        printf("#%d is %s \n", i, argv[i]);
    }
    return 0;
}
