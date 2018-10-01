#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){
    for(int i=1;i<argc;i++){
        char *string = (char *)calloc(strlen(argv[i]), sizeof(char));
        string = argv[i];
        if(tolower(string[0]) == 'a' || tolower(string[0]) == 'e' || tolower(string[0]) == 'i' 
            || tolower(string[0]) == 'o' || tolower(string[0]) == 'u'){
            char *add="yay";
            char *new = calloc(strlen(string)+strlen(add)+1, sizeof(char));

            strcat(new,string);
            strcat(new, add);

            for(int j=0;j<strlen(new);j++){
                if(new[j] != '\0'){
                    printf("%c", new[j]);
                }
            }
            free(new);
        }else{
            char *add="ay";
            char *ptr = &string[0];
            char *new = (char *)calloc(2*strlen(string)+strlen(add)+1, sizeof(char));

            strcat(new, string);
            int i = 0;
            while((tolower(ptr[i]) != 'a' && tolower(ptr[i]) != 'e' && tolower(ptr[i]) != 'i' 
                && tolower(ptr[i]) != 'o' && tolower(ptr[i]) != 'u') 
                && i < strlen(string)){
                    char c = ptr[i];
                    int j = 0;
                    while(new[j] != '\0'){
                        j++;
                    }
                    new[j] = c;
                    new[j+1] = '\0';
                    i++;
            }
            strcat(new, add);
            char *temp = &new[i];

            for(int j=0;j<strlen(temp);j++){
                if(temp[j] != '\0'){
                    printf("%c", temp[j]);
                }
            }
            free(new);
        }
        if(i!=argc-1){
            printf(" ");
        }
    }
    return 0;
}