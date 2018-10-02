//
//  UnweightedShortestPath.c
//  UnweightedShortestPath
//
//  Created by Trang Nguyen on 8/5/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "UnweightedShortestPath.h"

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

void printPath(int path[], int dest) {
    if(path[dest] == -1) {
        return;
    }
    printPath(path, path[dest]);
    printf("%d ", dest);
}

void printSolution(int distance[], int path[], int v, int src) { //src la dinh dau tien duyet
    printf("Vertex\t Distance\t\tPath\n");
    int i;
    for (i = 0; i < v; i++) {
        printf("\n%d -> %d\t\t%d\t\t%d ",src, i, distance[i], src);
        printPath(path, i);
    }
    printf("\n");
}

void UnweightedShortestPath(struct Graph *G, int s) {
    struct ArrayQueue *Q = Queue(G->V);
    int v, w, i;
    int Distance[G->V], Path[G->V];
    EnQueue(Q, s);
    for(i = 0; i < G->V; i++) {
        Distance[i] = -1;
        Path[i] = -1;
    }
    
    Distance[s] = 0;
    
    while(!IsEmptyQueue(Q)) {
        v = DeQueue(Q);
        for(w = 0; w < G->V; w++) {
            if(Distance[w] == -1 && G->Adj[v][w]) {
                Distance[w] = Distance[v] + 1;
                Path[w] = v;
                EnQueue(Q, w);
            }
        }
    }
    DeleteQueue(Q);
    printSolution(Distance, Path, G->V, 0);
}











