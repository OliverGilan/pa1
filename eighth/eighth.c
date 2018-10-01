#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int value;
    int height;
    struct node *right;
    struct node *left;
};

void search(struct node*, int, char, int);
// struct node* insert(struct node*, struct node *, int, int);
struct node* insert(struct node*, int, int);
void clean(struct node*);


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
            // printf("VALUE: %d\n", v);
            if(root == NULL){
                root = insert(root, 1, v);
            }else{
                insert(root, 1, v);
            }
        }else if(c=='s'){
            // printf("RUNNING: %d\n", v);
            search(root, 1, c, v);
        }
        // printf("%c %d\n", c, v);
    }

    clean(root);

    return 0;
}


struct node *insert(struct node *node, int height, int value){
    // if(node != NULL){
    //     printf("%d -> ", node->value);
    // }
    if(node == NULL){
        struct node * temp = (struct node*)malloc(1*sizeof(struct node));
        temp->value = value;
        temp->left=NULL;
        temp->right=NULL;
        printf("inserted %d\n", height);
        return temp;
    }
    if(node->value > value){
        node->left = insert(node->left, height+1, value);
    }else if(node->value < value){
        node->right = insert(node->right, height+1, value);
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

void clean(struct node *root){
    if(root==NULL)
        return;
    clean(root->left);
    clean(root->right);
    free(root);
}