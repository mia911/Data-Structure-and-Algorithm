#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left, *right;
};

struct Node * Insert(struct Node *Root, int value) {
    if (Root == NULL) {
        Root = (struct Node *) malloc(sizeof(struct Node));
        Root->value = value;
        Root->left = NULL;
        Root->right = NULL;
    } else {
        if (value < Root->value) {
            Root->left = Insert(Root->left, value);
        } else {
            Root->right = Insert (Root->right, value);
        }
    }
    return Root;
}

int FindMax (struct Node *root) {
    int val, left, right, max= 0;
    if (root != NULL) {
        val = root->value;
        left = FindMax(root->left);
        right = FindMax(root->right);
        
        //Find the largest of the three values
        if (left > right) {
            max = left;
        } else {
            max = right;
        }
        
        if(val > max)
            max = val;
    }
    return max;
}

void preOrder (struct Node *root) {
    if (!root) {
        return;
    }
    printf("%d\n", root->value);
    preOrder(root->left);
    preOrder(root->right);
}

int main () {
    struct Node *Q = NULL;
    Q = Insert(Q, 1);
    Insert(Q, 2);
    Insert(Q, 3);
    Insert(Q, 4);
    Insert(Q, 5);
    Insert(Q, 6);
    preOrder(Q);
    int max = FindMax(Q);
    printf("Max is: %d\n", max);
    return 0;
}
