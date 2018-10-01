#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){
    for(int i=1;i<argc;i++){
        char *string = (char *)calloc(strlen(argv[i]), sizeof(char));
        // char *string;
        string = argv[i];
        // printf("STRING: %s \n", string);
        if(tolower(string[0]) == 'a' || tolower(string[0]) == 'e' || tolower(string[0]) == 'i' 
            || tolower(string[0]) == 'o' || tolower(string[0]) == 'u'){
                // printf("RUNNING\n");
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
            // printf("RUNNING 2\n");
            char *add="ay";
            char *ptr = &string[0];
            char *new = (char *)calloc(2*strlen(string)+strlen(add)+1, sizeof(char));
            // if((new = malloc(2*strlen(string)+strlen(add)+1)) != NULL){
            //     new[0] = '\0';
            //     strcat(new,string);
            // }
            // printf("NEW: %s\n", new);
            strcat(new, string);
            // printf("%s\n", new);
            int i = 0;
            while((tolower(ptr[i]) != 'a' && tolower(ptr[i]) != 'e' && tolower(ptr[i]) != 'i' 
                && tolower(ptr[i]) != 'o' && tolower(ptr[i]) != 'u') 
                && i < strlen(string)){
                    char c = ptr[i];
                    // printf("C: %c\n", c);
                    int j = 0;
                    while(new[j] != '\0'){
                        // printf("new[i]: %c\n", new[j]);
                        j++;
                    }
                    new[j] = c;
                    new[j+1] = '\0';
                    // printf("NEWC: %s\n", new);
                    i++;
            }
            strcat(new, add);
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