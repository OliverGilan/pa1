#include <stdio.h>
#include <stdlib.h>

//TAKE CARE OF NEGATIVE NUMBERS with HASH FUNCTION

struct listnode{
    int value;
    struct listnode *next;
};

struct hash{
    int size;
    struct listnode **list;
};

void insert(struct hash*, int);
void search(struct hash*, int);
void clean(struct hash*);
int hash(int);

int main(int argc, char** argv){
    //Creates hashmap
    struct hash *map = (struct hash *)malloc(sizeof(struct hash));
    //Initializes size to 10,000
    map->size = 10000;
    map->list = (struct listnode**)malloc(map->size*sizeof(struct listnode));

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
        // printf("%c  %d \n", c, value);
        if(c=='i'){
            insert(map, value);
        }
        else if(c=='s'){
            search(map, value);
        }
    }
    fclose(file);

    clean(map);

    return 0;
}

void insert(struct hash *map, int key){
    int index = hash(key);
    // printf("%d \n", index);
    struct listnode *list = map->list[index];
    struct listnode *ptr = list;
    //Check for duplicate
    while(ptr){
        if(ptr->value == key){
            printf("duplicate \n");
            return;
        }
        ptr=ptr->next;
    }
    struct listnode *node = (struct listnode *)malloc(sizeof(struct listnode *));
    node->value=key;
    node->next=list;
    map->list[index]=node;
    printf("inserted \n");
}

void search(struct hash* map, int key){
    int index = hash(key);
    struct listnode *list = map->list[index];
    struct listnode *ptr = list;
    while(ptr){
        if(ptr->value==key){
            printf("present \n");
            return;
        }
        ptr=ptr->next;
    }
    printf("absent \n");
}

void clean(struct hash* map){
    free(map);
}

int hash(int key){
    int index = key % 10000;
    if(index < 0){
        index = 10000-index;
    }
    return index;
}