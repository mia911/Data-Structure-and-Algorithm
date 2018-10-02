//
//  StackLinkedList.h
//  DFS_Graph
//
//  Created by mixmex on 8/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#ifndef StackLinkedList_h
#define StackLinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStack{
    int data;
    struct nodeStack *next;
}NodeStack;

int isEmpty(NodeStack *);
void push(NodeStack **, int);
int pop(NodeStack **);
int top(NodeStack *);

#endif /* StackLinkedList_h */
