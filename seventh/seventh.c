#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    char *temp = (char *)malloc(argc*sizeof(char *));
    int j = 0;
    for(int i = 1; i < argc; i++){
        char *word = argv[i];
        char c=word[strlen(word)-1];
        temp[j]=c;
        j++;

    }
    printf("%s", temp);
    free(temp);

    return 0;
}