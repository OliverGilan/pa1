#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int value;
    struct node *right;
    struct node *left;
    struct node *parent;
};

int search(struct node*, int, char, int);
struct node* insert(struct node*, struct node *, int, int);
void delete(struct node*, struct node*, int);
void deleteChild(struct node*, struct node*, int);
struct node* findMin(struct node *);
void clean(struct node*);

struct node* root = NULL;

int main(int argc, char **argv){
    FILE *input;
    input = fopen(argv[1], "r");
    if(input == NULL){
        printf("%s", "error");
        return 0;
    }

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
            int r = search(root, 1, c, v);
            if(r == 0){
                printf("absent\n");
            }else{
                printf("present %d\n", r);
            }
        }else if(c=='d'){
            int r = search(root, 1, c, v);
            if(r == 0){
                printf("fail\n");
            }else{
                delete(root, NULL, v);
            }
        }
    }

    clean(root);

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

int search(struct node* root, int height, char c, int value){
    int r = 0;
    if(root == NULL){
        return 0;
    }else if(root->value == value){
        return height;
    }else if(root->value > value){
        r = search(root->left, height+1, c, value);
    }else if(root->value < value){
        r = search(root->right, height+1, c, value);
    }
    return r;
}

void delete(struct node* node, struct node* parent, int value){
    if(node != NULL){
        if(node->value == value){
            if(node->right != NULL && node ->left != NULL){
                struct node* minimum = findMin(node->right);
                node->value = minimum->value;
                deleteChild(node->right, node, minimum->value);
                printf("success\n");
                return;
            }if(node->right == NULL){
                if(parent == NULL){
                    root = node->left;
                    free(node);
                }
                else if(parent->value > value){
                    parent->left = node->left;
                    free(node);
                }
                else{
                    parent->right = node->left;
                    free(node);
                }
                printf("success\n");
                return;
            }else{
                if(parent == NULL){
                    root = node->right;
                    free(node);
                }
                else if(parent->value > value){
                    parent->left = node->right;
                    free(node);
                }
                else{
                    parent->right = node->right;
                    free(node);
                }
                printf("success\n");
                return;
            }
        }
    }else{
        return;
    }
    delete(node->left, node, value);
    delete(node->right, node, value);
}

struct node* findMin(struct node * root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

void deleteChild(struct node* node, struct node* parent, int value){
    if(node != NULL){
        if(node->value == value){
            if(node->right != NULL && node ->left != NULL){
                struct node* minimum = findMin(node->right);
                node->value = minimum->value;
                deleteChild(node->right, node, minimum->value);
                return;
            }if(node->right == NULL){
                if(parent->value > value){
                    parent->left = node->left;
                    free(node);
                }
                else{
                    parent->right = node->left;
                    free(node);
                }
                return;
            }else{
                if(parent->value > value){
                    parent->left = node->right;
                    free(node);
                }
                else{
                    parent->right = node->right;
                    free(node);
                }
                return;
            }
        }
    }else{
        return;
    }
    deleteChild(node->left, node, value);
    deleteChild(node->right, node, value);
}

void clean(struct node *root){
    if(root==NULL)
        return;
    clean(root->left);
    clean(root->right);
    free(root);
}