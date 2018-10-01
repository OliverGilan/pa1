#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){
    for(int i=1;i<argc;i++){
        // char *string = malloc(1*sizeof(strlen(argv[i])));
        char *string;
        string = argv[i];
        // printf("STRING: %s \n", argv[i]);
        if(tolower(*argv[i]) == 'a' || tolower(*argv[i]) == 'e' || tolower(*argv[i]) == 'i' || tolower(*argv[i]) == 'o' || tolower(*argv[i]) == 'u'){
            char *add="yay";
            char *new = calloc(strlen(string)+strlen(add)+1, sizeof(char));
            // if((new = malloc(strlen(string)+strlen(add)+1)) != NULL){
            //     new[0] = '\0';
            //     strcat(new,string);
            //     strcat(new, add);
            // }
            strcat(new,string);
            strcat(new, add);
            // new[strlen(new)] = '\0';
            // printf("%s", new);
            for(int j=0;j<strlen(new);j++){
                if(new[j] != '\0'){
                    printf("%c", new[j]);
                }
            }
            // printf(" ");
            free(new);
        }else{
            char *add="ay";
            char *ptr = &string[0];
            char *new = calloc(2*strlen(string)+strlen(add)+1, sizeof(char));
            // if((new = malloc(2*strlen(string)+strlen(add)+1)) != NULL){
            //     new[0] = '\0';
            //     strcat(new,string);
            // }
            // printf("NEW: %s\n", new);
            strcat(new, string);
            int i = 0;
            while((ptr[i] != 'a' && ptr[i] != 'e' && ptr[i] != 'i' && ptr[i] != 'o' && ptr[i] != 'u') 
                && i < strlen(string)){
                    // printf("%c ", ptr[i]);
                    char c = ptr[i];
                    strcat(new, &c);
                    // printf("NEWC: %s\n", ptr);
                    i++;
            }
            strcat(new, add);
            // new[strlen(new)] = '\0';
            char *temp = &new[i];

            // strcat(string, temp);
            // strcat(string, add);
            // printf("%s", temp);
            for(int j=0;j<strlen(temp);j++){
                if(temp[j] != '\0'){
                    printf("%c", temp[j]);
                }
            }
            // printf(" ");
            free(new);
        }
        if(i!=argc-1){
            printf(" ");
        }
        // printf("CHARACTER: %c\n", string[0]);
    }
    return 0;
}