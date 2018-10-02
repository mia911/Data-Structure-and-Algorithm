#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left, *right;
};

struct Node *Insert (struct Node *Root, int data) {
    if (Root == NULL) {
        Root = malloc(sizeof(struct Node));
        Root->value = data;
        Root->left = NULL;
        Root->right = NULL;
    } else {
        if (data < Root->value) {
            Root->left = Insert(Root->left, data);
        } else {
             Root->right = Insert(Root->right, data);
        }
    }
    
    return Root;
}

int FindMax (struct Node *Root) {
    struct Node *temp;
    int max = 0;
}

int main () {
    
}
