//
//  DFS_BFS.c
//  DFS_Graph
//
//  Created by mixmex on 8/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#include "DFS_BFS.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"

void depthFirstSearch(AdjGraph *graph, int v_start){
    printf("\n Depth First Search from %d: ", v_start);
    int v, V = graph->V;
    int visited[V];
    for (v=0; v<V; v++) {
        visited[v] = 0;
    }
    AdjList *arrayAdjList = graph->arrayAdjList;
    NodeStack *stack = NULL;
    push(&stack, v_start);
    
    while (!isEmpty(stack)) {
        int v_next = pop(&stack); //&: truyen vao dia chi cho pop: luu lai trang thai cua ham stack sau khi pop. *: khong luu lai
        if (!visited[v_next]) {
            visited[v_next] = 1;
            printf("%d ", v_next);
            
            AdjListNode *headVetex = arrayAdjList[v_next].head;
            while (headVetex != NULL) {
                if(!visited[headVetex->vertex_dest]){
                    push(&stack, headVetex->vertex_dest);
                }
                headVetex = headVetex->link;
            }
        }
    }
    printf("\n");
}

void breadthFirstSearch(AdjGraph *graph, int v_start){
    printf("\n Breadth First Search from %d: ", v_start);
    int v, V = graph->V;
    int visited[V];
    for(v=0; v<V; v++){
        visited[v] = 0;
    }
    AdjList *arrayAdjList = graph->arrayAdjList;
    QueueLinkedList *queue = createQueue();
    enQueue(queue, v_start);
    
    while (!queueIsEmpty(queue)) {
        int v_next = deQueue(queue)->data;
        if (!visited[v_next]) {
            visited[v_next] = 1;
            printf("%d ", v_next);
        
            AdjListNode *headVertex = arrayAdjList[v_next].head;
            while (headVertex != NULL) {
                if (!visited[headVertex->vertex_dest]) {
                    enQueue(queue, headVertex->vertex_dest);
                }
                headVertex = headVertex->link;
            }
        }
    }
    printf("\n");
}
