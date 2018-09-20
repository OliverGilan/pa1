#include <stdio.h>
#include <stdlib.h>

struct listnode{
    int value;
    struct listnode *next;
};

void insert(struct listnode*, int);
void search(struct listnode, int);

int main(int argc, char** argv){
    struct listnode *map[10000];
    char c;
    int value;

    //Opens file
    FILE* file = fopen(argv[1], "r");
    if(file == NULL){
        printf("%s", "error");
        return 0;
    }

    //Read file
    while(fscanf(file, "%c %d ", &c, &value) == 2){
        if(c=='i'){
            insert(map, value);
        }else if(c=='s'){
            
        }

    }

    return 0;
}

void insert(struct listnode *map, int key){
    int index = key % 10000;
    if(&map[index] == NULL){
        struct listnode *node = (struct listnode *) malloc(1*sizeof(struct listnode *));
        map[index] = *node;
        printf("inserted");
    }else{
        struct listnode *ptr = &map[index];
        while(ptr!= NULL){
            if(ptr->value == key){
                printf("duplicate");
                return;
            }
            ptr = ptr->next;
        }
        struct listnode *node = (struct listnode *) malloc(1*sizeof(struct listnode *));
        node->next = &map[index];
        map[index] = *node;
        printf("inserted");
    }
}

// void search(struct hash* map, int key){

// }
