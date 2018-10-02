//
//  BFS.c
//  BFS
//
//  Created by Trang Nguyen on 8/5/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "BFS.h"

struct ArrayQueue {
    int front, rear;
    int capacity;
    int *array;
};

struct ArrayQueue *Queue (int size) {
    struct ArrayQueue *Q = malloc (sizeof(struct ArrayQueue));
    if (!Q) return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc (Q->capacity * sizeof(int));
    if (!Q->array)
        return NULL;
    return Q;
}

int IsEmptyQueue (struct ArrayQueue *Q) {
    return (Q->front == -1);
}

int IsFullQueue(struct ArrayQueue *Q) {
    return ((Q->rear+1) % Q->capacity == Q->front);
}

int QueueSize (struct ArrayQueue *Q) {
    if (IsEmptyQueue(Q)) {
        return 0;
    } else {
        return ((Q->capacity - Q->front + Q->rear) % (Q->capacity)) + 1;
    }
}

void EnQueue (struct ArrayQueue *Q, int data) {
    if (IsFullQueue(Q))
        printf("Queue Overflow");
    else {
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
        if (Q->front == -1) {
            Q->front = Q->rear;
        }
//        printf("%d, %d\n", Q->front, Q->rear);
    }
}

int DeQueue (struct ArrayQueue *Q) {
    int data = 0;
    if (IsEmptyQueue(Q)) {
        printf("Quere is Empty");
        return 0;
    }
    else {
        data = Q->array[Q->front];
        if (Q->front == Q->rear) {
            Q->front = Q->rear = -1;
        } else {
            Q->front = (Q->front+1) % Q->capacity;
        }
        return data;
    }
}

void DeleteQueue(struct ArrayQueue *Q) {
    if (Q) {
        if (Q->array) {
            free(Q->array);
        }
        free(Q);
    }
}

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

void BFS(struct Graph *G, int u, int *Visited) {
    int v;
    struct ArrayQueue *Q = Queue(G->V);
    EnQueue(Q, u);
    while(!IsEmptyQueue(Q)) {
        u = DeQueue(Q);
        printf("%d  ", u);
        Visited[u] = 1;
        for(v = 0; v < G->V; v++) {
            if(!Visited && G->Adj[u][v]) {
                EnQueue(Q, v);
            }
        }
    }
}

void BFSTraversal(struct Graph *G) {
    int i;
    int Visited[G->V];
    for (i = 0; i < G->V; i++) {
        Visited[i] = 0;
    }
    for (i = 0; i < G->V; i++) {
        if(!Visited[i]) {
            BFS(G, i, Visited);
        }
    }
}











