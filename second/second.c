#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nodeNum = 0;

struct listnode {
    int value;
    struct listnode *next;
};


int main(int argc, char** argv){
    char c;
    int d;
    struct listnode *head = NULL;

    FILE* file = fopen(argv[1], "r");
    if(file == NULL){
        printf("%s", "error");
        return 0;
    }

    while(fscanf(file, "%c %d ", &c, &d) == 2){
        // printf("%c %d\n", c, d);
        if(c == 'i'){
            struct listnode *ptr = head;
            struct listnode *prev = NULL;
            struct listnode *node = (struct listnode *) malloc(1 *sizeof(struct listnode));
            node->value = d;
            node->next=NULL;
            if(head == NULL || head->value > d){
                node->next = head;
                head = node;
                nodeNum++;
            }else{
                while(ptr != NULL){
                    if(ptr->value < d){
                        prev = ptr;
                        ptr = ptr->next;
                    }else if(ptr->value == d){
                        break;
                    }else if(ptr->value > d){
                        node->next = ptr;
                        prev->next = node;
                        nodeNum++;
                        break;
                    }
                }
                if(ptr == NULL){
                    prev->next = node;
                    nodeNum++;
                }
            }
        }else if(c=='d'){
            struct listnode *ptr = head;
            struct listnode *prev = NULL;
            while(ptr != NULL){
                if(ptr->value == d){
                    if(ptr == head){
                        head = ptr->next;
                        free(ptr);
                        nodeNum--;
                    }else{
                        prev->next=ptr->next;
                        free(ptr);
                        nodeNum--;
                    }
                }
                prev = ptr;
                ptr = ptr->next;
            }
            
        }
    }

    fclose(file);
    printf("%d\n",nodeNum);
    struct listnode *ptr = head;
    while(ptr != NULL){
        printf("%d\t", ptr->value);
        free(ptr);
        ptr = ptr->next;
    }

    return 0;
}