//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node {
//    int value;
//    struct Node *left, *right;
//};
//
//struct Queue {
//    int front, rear;
//    int capacity;
//    struct Node **array;
//};
//
//struct Queue *CreateQueue (int size) {
//    struct Queue *Q = malloc(sizeof(struct Queue));
//    Q->capacity = size;
//    Q->front = Q->rear = -1;
//    Q->array = (struct Node **) malloc(size * sizeof(struct Node));
//    return Q;
//}
//
//int IsEmptyQueue (struct Queue *Q) {
//    if (Q->front == -1) {
//        return 1;
//    } else {
//        return 0;
//    }
//}
//
//int IsFullQueue (struct Queue *Q) {
//    if (Q->rear == (Q->capacity - 1)) {
//        return 1;
//    } else {
//        return 0;
//    }
//}
//
////void IncreaseSize (struct Queue *Q) {
////    Q->capacity *= 2;
////    Q = realloc(Q->array, Q->capacity * sizeof(struct Node));
////}
//
//void EnQueue (struct Queue *Q, struct Node *node) {
////    if (IsFullQueue(Q)) {
////        IncreaseSize(Q);
////    }
//    Q->rear += 1;
//    Q->array[Q->rear] = (struct Node *) malloc (sizeof(struct Node));
//    Q->array[Q->rear] = node;
//    if (Q->front == -1) {
//        Q->front = Q->rear;
//    }
//}
//
//struct Node *DeQueue (struct Queue *Q) {
//    struct Node *data;
//    if (IsEmptyQueue(Q)) {
//        printf("Queue is Empty\n");
//        return 0;
//    } else {
//        data = Q->array[Q->front];
//        if (Q->front == Q->rear) {
//            Q->front = Q->rear = -1;
//        } else {
//            Q->front += 1;
//        }
//    }
//    return data;
//}
//
//void DeleteQueue (struct Queue *Q) {
//    if (Q) {
//        if (Q->array) {
//            Q->array = NULL;
//        }
//        free (Q);
//    }
//}
//
//struct Node *InsertBinaryTree (struct Node *root, int data) {
//    struct Queue *Q;
//    struct Node *temp, *newNode;
//    newNode = (struct Node *) malloc (sizeof (struct Node));
//    newNode->value = data;
//    newNode->left = newNode->right = NULL;
//    
//    if (!root) {
//        root = newNode;
//        return root;
//    }
//    
//    Q = CreateQueue (10);
//    EnQueue(Q, root);
//    while (!IsEmptyQueue(Q)) {
//        temp = DeQueue(Q);
//        
//        if (temp->left != NULL) {
//            EnQueue(Q, temp->left);
//        } else {
//            temp->left = newNode;
//            DeleteQueue(Q);
//            return root;
//        }
//        
//        if (temp->right != NULL) {
//            EnQueue(Q, temp->right);
//        } else {
//            temp->right = newNode;
//            DeleteQueue(Q);
//            return root;
//        }
//    }
//    DeleteQueue(Q);
//    return root;
//}
//
//void preOrder (struct Node *root) {
//    if (root == NULL) {
//        return;
//    }
//    printf("%d\n", root->value);
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//int main () {
//    struct Node *root;
//    root = InsertBinaryTree(root, 1);
//    InsertBinaryTree(root, 2);
//    InsertBinaryTree(root, 3);
//    InsertBinaryTree(root, 4);
//    InsertBinaryTree(root, 5);
//    InsertBinaryTree(root, 6);
//    InsertBinaryTree(root, 7);
//    preOrder(root);
//    return 0;
//}
//
//


//
//  TreeADT.c
//  Tree
//
//  Created by MixMex on 2/12/17.
//  Copyright © 2017 MixMex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct Queue{
    int front, rear;
    int capacity;
    struct BinaryTreeNode **array;
};

struct Queue *CreateQueue(int size){
    struct Queue *Q = malloc(sizeof(struct Queue));
    if(!Q) return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = (struct BinaryTreeNode **) malloc(Q->capacity*sizeof(struct BinaryTreeNode));
//    if(!Q->array){
//        return NULL;
//    }
    return Q;
}

int IsEmptyQueue(struct Queue *Q){
    return (Q->front == -1);
}

int IsFullQueue(struct Queue *Q){
    return ((Q->rear + 1) % (Q->capacity) == Q->front);
}

int QueueSize(struct Queue *Q){
    return ((Q->capacity - Q->front + Q->rear + 1) % (Q->capacity));
}

void EnQueue(struct Queue *Q, struct BinaryTreeNode *node){
    if(IsFullQueue(Q)){
        printf("Queue Overflow");
    }else{
        Q->rear = (Q->rear + 1) % (Q->capacity);
        Q->array[Q->rear] = (struct BinaryTreeNode *) malloc(sizeof(struct BinaryTreeNode));
        Q->array[Q->rear] = node;
        if(Q->front == -1){
            Q->front = Q->rear;
        }
    }
}

struct BinaryTreeNode * DeQueue(struct Queue *Q){
    struct BinaryTreeNode *data;
    if(IsEmptyQueue(Q)){
        printf("Queue is Empty");
        return 0;
    }else{
        data = Q->array[Q->front];
        if(Q->front == Q->rear){
            Q->front = Q->rear = -1;
        }else{
            Q->front = (Q->front + 1) % (Q->capacity);
        }
    }
    return data;
}

void DeleteQueue(struct Queue *Q){
    if(Q){
        if(Q->array) Q->array = NULL;
        free(Q);
    }
}


struct BinaryTreeNode * InsertInBinaryTree(struct BinaryTreeNode *root, int data){
    struct Queue *Q;
    struct BinaryTreeNode *temp;
    struct BinaryTreeNode *newNode;
    newNode = (struct BinaryTreeNode *) malloc(sizeof(struct BinaryTreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    
    if(!newNode){
        printf("Memory Error");
        return NULL;
    }
    
    if(!root){
        root = newNode;
        return root;
    }
    
    Q = CreateQueue(MAXSIZE);
    EnQueue(Q, root);
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        if (temp->left) {
            EnQueue(Q, temp->left);
        }else{
            temp->left = newNode;
            DeleteQueue(Q);
            return root;
        }
        if (temp->right) {
            EnQueue(Q, temp->right);
        }else{
            temp->right = newNode;
            DeleteQueue(Q);
            return root;
        }
    }
    DeleteQueue(Q);
    return root;
}

void preOrder(struct BinaryTreeNode* root){
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct BinaryTreeNode * root;
    
    root = InsertInBinaryTree(root, 0);
    InsertInBinaryTree(root, 1);
    InsertInBinaryTree(root, 2);
    InsertInBinaryTree(root, 3);
    InsertInBinaryTree(root, 4);
    preOrder(root);
    printf("\n");
    return 0;
}
