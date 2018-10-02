//
//  Adjacent List.c
//  Adjacent List
//
//  Created by Trang Nguyen on 7/25/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "Adjacent List.h"

struct ListNode {
    int vertexNumber;
    struct ListNode *next;
};

struct Graph {
    int V;
    int E;
    struct ListNode **Adj;
};


struct Graph *adjListOfGraph() {
    int i, x, y;
    struct ListNode *temp;
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    if (!G) {
        printf("Memory Error");
        return G;
    }
    printf("Number of Vertices: "); scanf("%d", &G->V);
    printf("Number of Edges: "); scanf("%d", &G->E);
    G->Adj = (struct ListNode **)malloc(G->V * sizeof(struct ListNode *));
    for (i = 0; i < G->V; i++) {
        G->Adj[i] = (struct ListNode *)malloc(sizeof(struct ListNode));
        G->Adj[i]->vertexNumber = i;
        G->Adj[i]->next = G->Adj[i];
    }
    for(i = 0; i < G->E; i++) {
        printf("Reading Edges:\n");
        printf("x: ");
        scanf("%d", &x);
        printf("y: ");
        scanf("%d", &y);
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->vertexNumber = y;
        temp->next = G->Adj[x]->next;
        G->Adj[x]->next = temp;
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->vertexNumber = x;
        temp->next = G->Adj[y]->next;
        G->Adj[y]->next = temp;
    }
    
    for(i = 0; i < G->V; i++) {
        temp = G->Adj[i];
        struct ListNode *head = G->Adj[i];
        printf("%d: ", temp->vertexNumber);
        while(temp->next != head) {
            printf("%d  ", temp->next->vertexNumber);
            temp = temp->next;
        }
        printf("\n");
    }
    return G;
}
