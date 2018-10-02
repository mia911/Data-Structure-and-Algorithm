//
//  TreeADT.c
//  Tree
//
//  Created by MixMex on 2/12/17.
//  Copyright © 2017 MixMex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "TreeADT.h"

#define MAXSIZE 10

struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct Queue{
    int front, rear;
    int capacity;
    struct BinaryTreeNode *array;
};

struct Queue *CreateQueue(int size){
    struct Queue *Q = malloc(sizeof(struct Queue));
    if(!Q) return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity*sizeof(struct BinaryTreeNode));
    if(!Q->array){
        return NULL;
    }
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
        Q->array[Q->rear] = *node;
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
        data = &Q->array[Q->front];
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
        if(Q->array) free(Q->array);
        free(Q);
    }
}


void InsertInBinaryTree(struct BinaryTreeNode *root, int data){
    struct Queue *Q;
    struct BinaryTreeNode *temp;
    struct BinaryTreeNode *newNode;
    newNode = (struct BinaryTreeNode *) malloc(sizeof(struct BinaryTreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    
    if(!newNode){
        printf("Memory Error");
        return;
    }
    
    if(!root){
        root = newNode;
        return;
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
        }
        if (temp->right) {
            EnQueue(Q, temp->right);
        }else{
            temp->right = newNode;
            DeleteQueue(Q);
            return;
        }
    }
    DeleteQueue(Q);
}

void preOrder(struct BinaryTreeNode* root){
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
