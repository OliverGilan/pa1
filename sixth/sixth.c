#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    for(int i=1;i<argc;i++){
        char *string = malloc(1*sizeof(strlen(argv[i])));
        string = argv[i];
        // printf("STRING: %s \n", string);
        if(*argv[i] == 'a' || *argv[i] == 'e' || *argv[i] == 'i' || *argv[i] == 'o' || *argv[i] == 'u'){
            char *add="yay";
            char *new;
            if((new = malloc(strlen(string)+strlen(add)+1)) != NULL){
                new[0] = '\0';
                strcat(new,string);
                strcat(new, add);
            }
            printf("%s ", new);
        }else{
            char *add="ay";
            char *ptr = &string[0];
            char *new;
            if((new = malloc(2*strlen(string)+strlen(add)+1)) != NULL){
                new[0] = '\0';
                strcat(new,string);
            }
            // printf("NEW: %s\n", new);
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
            char *temp = &new[i];

            // strcat(string, temp);
            // strcat(string, add);
            printf("%s ", temp);
        }
        // printf("CHARACTER: %c\n", string[0]);
    }
    return 0;
}