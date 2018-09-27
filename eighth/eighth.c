#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int value;
    int height;
    struct node *right;
    struct node *left;
};

struct node* search(struct node*, int, char, int);
struct node* insert(struct node*, int, char, int);

int main(int argc, char **argv){
    FILE *input;
    input = fopen(argv[1], "r");
    if(input == NULL){
        printf("%s", "error");
        return 0;
    }

    struct node* root = NULL;
    int size = 0;
    char c;
    int v;
    while(fscanf(input, "%c %d", &c, &v)){
        if(c='i'){
            root = insert(root, 1, c, v);
        }else if(c='s'){
            root = search(root, size, c, v);
        }
    }

    return 0;
}

struct node * insert(struct node* root, int height, char c, int value){
    if(root == NULL){
        struct node * temp = (struct node*)calloc(1*sizeof(struct node), 0);
        temp->value = value;
        temp->left=NULL;
        temp->right=NULL;
        temp->height=1;
        printf("inserted %d", temp->value);
        return temp;
    }else{
        struct node* ptr = root;
        struct node* prev = NULL;
        if(ptr == NULL){
            struct node * temp = (struct node*)calloc(1*sizeof(struct node), 0);
            temp->value = value;
            temp->left=NULL;
            temp->right=NULL;
            temp->height=height;
            if(prev->value > value){
                prev->left = temp;
                printf("inserted %d", temp->height);
                return root;
            }else if(ptr->value < value){
                prev->right = temp;
                printf("inserted %d", temp->height);
                return root;
            }
        }else if(ptr->value == value){
            printf("duplicate");
            return root;
        }else if(ptr->value > value){
            return search(root->left, height+1, c, value);
        }else{
            return search(root->right, height+1, c, value);
        }
    }
}

struct node * search(struct node* root, int size, char c, int value){
    
}