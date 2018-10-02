//
//  StackLinkedList.c
//  DFS_Graph
//
//  Created by mixmex on 8/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#include "StackLinkedList.h"
#include <limits.h>

NodeStack *createNode(int data){
    NodeStack *node = (NodeStack *) malloc(sizeof(NodeStack));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

int isEmpty(NodeStack *root){
    return !root;
}

void push(NodeStack **root, int data){
    NodeStack *node = createNode(data);
    if (node != NULL) {
        node->next = *root;
        *root = node;
    }
}

int pop(NodeStack **root){
    if (isEmpty(*root)) {
        return INT_MIN;
    }
    NodeStack *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int top(NodeStack *root){
    if (isEmpty(root)) {
        return INT_MIN;
    }
    return root->data;
}
