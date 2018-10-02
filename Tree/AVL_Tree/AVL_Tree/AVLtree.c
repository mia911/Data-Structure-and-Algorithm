//
//  AVLtree.c
//  AVL_Tree
//
//  Created by Trang Nguyen on 3/12/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "AVLtree.h"

int Height (AVLNode *root){
    if (!root) return -1;
    else return root->height;
}

int Max (int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

AVLNode *SingleRotateLeft(AVLNode *X){
    AVLNode *W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = Max(Height(X->left), Height(X->right)) + 1;
    W->height = Max(Height(W->left), X->height) + 1;
    return W;
}

AVLNode *SingleRotateRight(AVLNode *W) {
    AVLNode *X = W->right;
    W->right = X->left;
    X->left = W;
    W->height = Max(Height(W->right), Height(W->left)) + 1;
    X->height = Max(Height(X->right), W->height) + 1;
    return X;
}

AVLNode *DoubleRotateLeft (AVLNode *Z) {
    Z->left = SingleRotateRight(Z->left);
    return SingleRotateLeft(Z);
}

AVLNode *DoubleRotateRight (AVLNode *Z) {
    Z->right = SingleRotateLeft(Z->right);
    return SingleRotateLeft(Z);
}

AVLNode *Insert(AVLNode *root, AVLNode *parent, int data) {
    if (!root) {
        root = (AVLNode*) malloc (sizeof(AVLNode*));
        if (!root) {
            printf("Memory Error");
            return NULL;
        } else {
            root->data = data;
            root->height = 0;
            root->left = root->right = NULL;
        }
    } else if (data < root->data) {
        root->left = Insert(root->left, root, data);
        if ((Height(root->left) - Height(root->right)) == 2) {
            if (data < root->left->data) {
                root = SingleRotateLeft(root);
            } else {
                root = DoubleRotateLeft(root);
            }
        }
    } else if (data > root->data) {
        root->right = Insert(root->right, root, data);
        if ((Height(root->right) - Height(root->left)) == 2) {
            if (data < root->right->data) {
                root = SingleRotateRight(root);
            } else {
                root = DoubleRotateRight(root);
            }
        }
    }
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    return root;
}

void PreOrder (AVLNode *root) {
    if (!root) {
        printf("0 element\n");
    } else {
        printf("%d\n", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}






























