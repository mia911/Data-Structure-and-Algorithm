#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * Insert(struct Node *Root, int value) {
    if (Root == NULL) {
//        printf("%d\n", value);
        Root = (struct Node *) malloc(sizeof(struct Node));
        Root->data = value;
        Root->left = NULL;
        Root->right = NULL;
    } else {
//        printf("%d\n", value);
        if (value < Root->data) {
            Root->left = Insert(Root->left, value);
        } else {
            Root->right = Insert (Root->right, value);
        }
    }
    return Root;
}

void PreOrder(struct Node *Root) {
    if (Root) {
        printf("%d\n", Root->data);
        PreOrder(Root->left);
        PreOrder(Root->right);
    }
}

void InOrder (struct Node *Root) {
    if (Root) {
        InOrder(Root->left);
        printf("%d\n", Root->data);
        InOrder(Root->right);
    }
}

void PostOrder (struct Node *Root) {
    if (Root) {
        PostOrder(Root->left);
        PostOrder(Root->right);
        printf("%d\n", Root->data);
    }
}

int main() {
    struct Node *N = NULL;
    N = Insert(N, 30);
    Insert(N, 20);
    Insert(N, 40);
    Insert(N, 10);
    Insert(N, 25);
    Insert(N, 50);
    Insert(N, 60);
    
    printf("PreOrder: \n");
    PreOrder(N);
    printf("\n");
    
    printf("InOrder: \n");
    InOrder(N);
    printf("\n");
    
    printf("PostOrder: \n");
    PostOrder(N);
    printf("\n");
    return 0;
}


















