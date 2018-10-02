//
//  AdjacencyListGraph.c
//  DFS_Graph
//
//  Created by mixmex on 8/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#include "AdjacencyListGraph.h"

AdjListNode * newAdjListNode(int dest){
    AdjListNode *newNode = (AdjListNode *) malloc(sizeof(AdjListNode));
    if(newNode != NULL){
        newNode->vertex_dest = dest;
        newNode->link = NULL;
    }
    return newNode;
}

AdjGraph * createGraph(int V, int isDirectGraph){
    AdjGraph *newGraph = (AdjGraph *) malloc(sizeof(AdjGraph));
    if(newGraph != NULL){
        newGraph->V = V;
        newGraph->isDirectGraph = isDirectGraph;
        newGraph->arrayAdjList = (AdjList *) malloc(V * sizeof(AdjList));
        
        for (int i=0; i<V; i++) {
            newGraph->arrayAdjList[i].head = NULL;
        }
    }
    return newGraph;
}

void addEdge(AdjGraph *G, int src, int dest){
    AdjListNode *newNodeS = newAdjListNode(dest);
    newNodeS->link = G->arrayAdjList[src].head;
    G->arrayAdjList[src].head = newNodeS;
    
    //With undirect graph, add edge from dest to src
    if(!G->isDirectGraph){
        AdjListNode *newNodeD = newAdjListNode(src);
        newNodeD->link = G->arrayAdjList[dest].head;
        G->arrayAdjList[dest].head = newNodeD;
    }
}

void printGraph(AdjGraph *G){
    int v;
    int V = G->V;
    for (v=0; v<V; v++) {
        AdjListNode *nodeCrawl = G->arrayAdjList[v].head;
        printf("\n Adjacency list of vertex %d head:", v);
        while (nodeCrawl != NULL) {
            printf(" -> %d", nodeCrawl->vertex_dest);
            nodeCrawl = nodeCrawl->link;
        }
        printf("\n");
    }
}
