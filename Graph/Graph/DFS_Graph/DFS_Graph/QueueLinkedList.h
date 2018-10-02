//
//  QueueLinkedList.h
//  DFS_Graph
//
//  Created by mixmex on 8/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#ifndef QueueLinkedList_h
#define QueueLinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeQueue{
    int data;
    struct nodeQueue *next;
}NodeQueue;

typedef struct queue{
    NodeQueue *front, *rear;
} QueueLinkedList;

QueueLinkedList * createQueue();
int queueIsEmpty(QueueLinkedList *);
void enQueue(QueueLinkedList *, int);
NodeQueue *deQueue(QueueLinkedList *);

#endif /* QueueLinkedList_h */
