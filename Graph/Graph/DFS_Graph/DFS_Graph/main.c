//
//  main.c
//  DFS_Graph
//
//  Created by mixmex on 8/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#include <stdio.h>
#include "AdjacencyListGraph.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "DFS_BFS.h"

int main(int argc, const char * argv[]) {
    int V = 5;
    int isDirect = 1; //1: co huong, 0: vo huong
    AdjGraph *graph = createGraph(V, isDirect);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printGraph(graph);
    
    breadthFirstSearch(graph, 0);
    depthFirstSearch(graph, 0);
    
//    NodeStack *root = NULL;
//    push(&root, 1);
//    push(&root, 2);
//    
//    printf("%d", pop(&root));
    
//    QueueLinkedList *queue = createQueue();
//    enQueue(queue, 1);
//    enQueue(queue, 2);
//    NodeQueue *n = deQueue(queue);
//    printf("%d", n->data);

    return 0;
}
