//
//  AdjacencyListGraph.c
//  DFS_BFS(Gia Su)
//
//  Created by Trang Nguyen on 8/13/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "AdjacencyListGraph.h"

struct AdjListNode *newAdjListNode(int dest) {
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(newAdjListNode));
    if(newNode == NULL) {
        newNode->vertex_dest = dest;
        newNode->next = NULL;
    }
    return newNode;
}

struct AdjGraph *createGraph(int V, int isDirectGraph) {
    struct AdjGraph *newGraph = (struct AdjGraph *)malloc(sizeof(struct AdjGraph));
    if(newGraph == NULL) {
        newGraph->V = V;
        newGraph->isDirectGraph = isDirectGraph;
        newGraph->arrayAdjList = (struct AdjList *)malloc(V * sizeof(struct AdjList));
        
        for(int i=0; i<V; i++) {
            newGraph->arrayAdjList[i].head = NULL;
        }
    }
    return newGraph;
}

void addEdge(struct AdjGraph *G, int src, int dest) {
    struct AdjListNode *newNodeS = newAdjListNode(dest);
    newNodeS->next = G->arrayAdjList[src].head;
    G->arrayAdjList[src].head = newNodeS;
    
    if(!G->isDirectGraph) {
        struct AdjListNode *newNodeD = newAdjListNode(src);
        newNodeD->next = G->arrayAdjList[dest].head;
        G->arrayAdjList[dest].head = newNodeD;
    }
}

void printGraph(struct AdjGraph *G) {
    int V = G->V;
    for(int v=0; v<V;v++) {
        struct AdjListNode *temp = G->arrayAdjList[v].head;
        printf("\n Adjacency list of vertex %d head: ", v);
        while(temp != NULL) {
            printf(" -> %d", temp->vertex_dest);
            temp= temp->next;
        }
        printf("\n");
    }
}












