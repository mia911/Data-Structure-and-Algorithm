//
//  QueueLinkedList.c
//  DFS_Graph
//
//  Created by mixmex on 8/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#include "QueueLinkedList.h"

NodeQueue *newNode(int k){
    NodeQueue *node = (NodeQueue *) malloc(sizeof(NodeQueue));
    if (node != NULL) {
        node->data = k;
        node->next = NULL;
    }
    return node;
}

QueueLinkedList * createQueue(){
    QueueLinkedList *queue = (QueueLinkedList *) malloc(sizeof(QueueLinkedList));
    if(queue != NULL){
        queue->front = queue->rear = NULL;
    }
    return queue;
}

int queueIsEmpty(QueueLinkedList *queue){
    return ((queue->front == queue->rear) && (queue->front==NULL));
}

void enQueue(QueueLinkedList *queue, int k){
    NodeQueue *node = newNode(k);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    
    queue->rear->next = node;
    queue->rear = node;
}

NodeQueue *deQueue(QueueLinkedList *queue){
    if (queueIsEmpty(queue)) {
        return NULL;
    }
    
    NodeQueue *node = queue->front;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return node;
}
