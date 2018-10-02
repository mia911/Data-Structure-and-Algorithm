#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * Insert(struct Node *Root, int value) {
    if (Root == NULL) {
        Root = (struct Node *) malloc(sizeof(struct Node));
        Root->data = value;
        Root->left = NULL;
        Root->right = NULL;
    } else {
        if (value < Root->data) {
            Root->left = Insert(Root->left, value);
        } else {
            Root->right = Insert (Root->right, value);
        }
    }
    return Root;
}

struct Node *Find (struct Node *root, int value) {
    if (!root) return NULL;
    else {
        if (value < root->data) {
            return Find(root->left, value);
        } else if (value > root->data) {
            return Find(root->right, value);
        }
        return root;
    }
}

struct Node *FindMax (struct Node *root) {
    if (!root) return NULL;
    else {
        if (root->right == NULL) {
            return root;
        } else {
            return FindMax(root->right);
        }
    }
}

struct Node *FindMin (struct Node *root) {
    if (!root) return NULL;
    else {
        if (root->left == NULL) {
            return root;
        } else {
            return FindMin(root->left);
        }
    }
}

void PreOrder(struct Node *Root) {
    if (Root) {
        printf("%d\n", Root->data);
        PreOrder(Root->left);
        PreOrder(Root->right);
    }
}

struct Node *Delete (struct Node *root, int data) {
    struct Node *temp;
    if (root == NULL) {
        printf ("Element not there in tree\n");
    } else if (data < root->data) {
        root->left = Delete(root->left, data);
    } else if (data > root->data) {
        root->right = Delete(root->right, data);
    } else {
        if (root->left && root->right) {
            temp = FindMax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, root->data);
        } else {
            temp = root;
            if (root->left == NULL) {
                root = root->right;
            } else if (root->right == NULL) {
                root = root->left;
            }
            free(temp);
        }
    }
    return root;
}

int main () {
    struct Node *N = NULL;
    N = Insert(N, 30);
    Insert(N, 20);
    Insert(N, 40);
    Insert(N, 10);
    Insert(N, 25);
    Insert(N, 50);
    Insert(N, 60);
    Insert(N, 15);
    
    PreOrder(N);
    
    Delete(N, 30);
    
    printf("\n");
    
    PreOrder(N);
    return 0;
}




































