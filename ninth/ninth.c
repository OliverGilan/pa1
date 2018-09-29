#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int value;
    struct node *right;
    struct node *left;
    struct node *parent;
};

void search(struct node*, int, char, int);
struct node* insert(struct node*, struct node *, int, int);
void delete(struct node*, struct node*);

int main(int argc, char **argv){
    FILE *input;
    input = fopen(argv[1], "r");
    if(input == NULL){
        printf("%s", "error");
        return 0;
    }

    struct node* root = NULL;
    char c;
    int v;
    while(fscanf(input, "%c %d ", &c, &v) == 2){
        if(c=='i'){
            if(root == NULL){
                root = insert(root, NULL, 1, v);
            }else{
                insert(root, NULL, 1, v);
            }
        }else if(c=='s'){
            search(root, 1, c, v);
        }
    }

    

    return 0;
}

struct node *insert(struct node *node, struct node *parent,int height, int value){
    if(node == NULL){
        struct node * temp = (struct node*)malloc(1*sizeof(struct node));
        temp->value = value;
        temp->parent = parent;
        temp->left=NULL;
        temp->right=NULL;
        printf("inserted %d\n", height);
        return temp;
    }
    if(node->value > value){
        node->left = insert(node->left, node, height+1, value);
    }else if(node->value < value){
        node->right = insert(node->right, node, height+1, value);
    }else if(node->value==value){
        printf("duplicate\n");
    }
    return node;
}

void search(struct node* root, int height, char c, int value){
    if(root == NULL){
        printf("absent\n");
        return;
    }else if(root->value == value){
        printf("present %d\n", height);
        return;
    }else if(root->value > value){
        search(root->left, height+1, c, value);
    }else if(root->value < value){
        search(root->right, height+1, c, value);
    }
    return;
}

void delete(struct node* node, struct node* parent){

}