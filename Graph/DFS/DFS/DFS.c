//
//  DFS.c
//  DFS
//
//  Created by Trang Nguyen on 8/5/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "DFS.h"

struct Graph *AdjMatrixofGraph() {
    int i, u, v;
    struct Graph *G = (struct Graph *) malloc(sizeof(struct Graph));
    if(!G) {
        printf("Memory error");
        return 0;
    }
    printf("Number of vertices: ");
    scanf( "%d", &G->V);
    printf("Number of edges: ");
    scanf("%d", &G->E);
    
    
    G->Adj = (int **)malloc((G->V) * sizeof(int *));
    for(u = 0; u < G->V; u++) {
        G->Adj[u] = (int *)malloc((G->V) * sizeof(int));
        for(v = 0; v < G->V; v++) {
            G->Adj[u][v] = 0;
        }
    }
    
    for(i = 0; i < G->E; i++) {
        printf("Reading Edge: \n");
        printf("u = ");
        scanf("%d", &u);
        printf("v = ");
        scanf("%d", &v);
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1;
    }
    
    for(u = 0; u < G->V; u++) {
        for(v = 0; v < G->V; v++) {
            printf("%d %d: %d\n", u, v, G->Adj[u][v]);
        }
    }
    return G;
}

void DFS(struct Graph *G, int u, int *Visited) {
    Visited[u] = 1;
    for(int v = 0; v < G->V; v++) {
        if(!Visited[v] && G->Adj[u][v]) {
            DFS(G, v, Visited);
            printf("%d", v);
        }
    }
}

void DFSTraversal(struct Graph *G) {
    int i;
    int Visited[G->V];
    for(i = 0; i < G->V; i++) {
        Visited[i] = 0;
    }
    
    for(i = 0; i < G->V; i++) {
        if(!Visited[i]) {
            DFS(G, i, Visited);
        }
    }
}


















