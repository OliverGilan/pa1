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

    //Gets file from arguments
    input = argv[1];
    //Gets item count from file and creates array
    char array[fgetc(input)];

    
    
    return 0;
}
