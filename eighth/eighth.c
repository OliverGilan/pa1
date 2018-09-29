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

// struct node *insert(struct node * root, struct node * prev, int height, int value){
//     if(root == NULL){
//         struct node * temp = (struct node*)calloc(1*sizeof(struct node), 0);
//         temp->value = value;
//         temp->left=NULL;
//         temp->right=NULL;
//         temp->height=height;
//             printf("inserted %d\n", height);
//             return temp;
//         // if(prev == NULL){
//         //     printf("inserted %d\n", height);
//         //     return temp;
//         // }else if(prev->value > value){
//         //     prev->left = temp;
//         //     printf("PREV: %d\n", prev->value);
//         //     printf("inserted %d\n", height);
//         //     return root;
//         // }else if(prev->value < value){
//         //     prev->right = temp;
//         //     printf("PREV: %d\n", prev->value);
//         //     printf("inserted %d\n", height);
//         //     return root;
//         // }
//     }else if(root->value > value){
//         printf("ROOT: %d\n", root->value);
//         root->left = insert(root->left, root, height+1, value);
//         printf("ROOTLEFT: %d\n", root->left->value);
//     }else if(root->value < value){
//         printf("ROOT: %d\n", root->value);
//         root->right = insert(root->right, root, height+1, value);
//     }else if(root->value == value){
//         printf("duplicate");
//     }
//     return root;
// }
// struct node * insert(struct node* root, int height, char c, int value){
//     if(root->value == 0){
//         printf("%d\n", root->value);
//         struct node * temp = (struct node*)calloc(1*sizeof(struct node), 0);
//         temp->value = value;
//         temp->left=NULL;
//         temp->right=NULL;
//         temp->height=1;
//         printf("inserted %d\n", temp->height);
//         return temp;
//     }else{
//         struct node* ptr = root;
//         struct node* prev = NULL;
//         if(ptr == NULL){
//             struct node * temp = (struct node*)calloc(1*sizeof(struct node), 0);
//             temp->value = value;
//             temp->left=NULL;
//             temp->right=NULL;
//             temp->height=height;
//             printf("%d\n", height);
//             // if(prev->value > value){
//             //     prev->left = temp;
//             //     printf("inserted %d\n", temp->height);
//             //     return root;
//             // }else if(ptr->value < value){
//             //     prev->right = temp;
//             //     printf("inserted %d\n", temp->height);
//             //     return root;
//             // }
//             return root;
//         }else if(ptr->value == value){
//             printf("duplicate\n");
//             return root;
//         }else if(ptr->value > value){
//             return insert(root->left, height+1, c, value);
//         }else{
//             return insert(root->right, height+1, c, value);
//         }
//     }
//     return root;
// }

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