//
//  Adjacency-Matrix.c
//  Adjacency Matrix
//
//  Created by Trang Nguyen on 7/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "Adjacency-Matrix.h"

struct Graph {
    int V;
    int E;
    int **Adj;
};

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
