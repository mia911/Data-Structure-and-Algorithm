//
//  Kruskal.c
//  Kruskal
//
//  Created by Trang Nguyen on 9/17/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "Kruskal.h"

int size;

int myCompt(const void *a, const void *b) { //nhung tham so dau vao chua duoc dinh nghia. thay edge bang 1 cai gi khac cung duoc
    struct Edge *a1 = (struct Edge*)a;
    struct Edge *b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void Resize(struct Edge* edge) {
    edge = realloc(edge, size * 2);
    size *= 2;
}

void Kruskal(struct Graph *graph) {
    qsort(graph->edges, graph->e, sizeof(graph->edges[0]), myCompt);
    struct Edge array[graph->v - 1];
    int i = 0;
    struct Edge *temp = (struct Edge*)malloc(sizeof(graph->edges[0]) * (graph->v - 1));
    size = graph->v - 1;
    while(i < graph->v - 1) {
        
    }
}
