//
//  main.c
//  Kruskal
//
//  Created by Trang Nguyen on 9/17/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>

#include "Kruskal.h"

int main(int argc, const char * argv[]) {
//    int graph[9][9] = {
//    /*0*/    {0, 4, 0, 0, 0, 0, 0, 8, 0},
//    /*1*/     {4, 0, 8, 0, 0, 0, 0, 11, 0},
//    /*2*/     {0, 8, 0, 7, 0, 4, 0, 0, 2},
//    /*3*/     {0, 0, 7, 0, 9, 14, 0, 0, 0},
//    /*4*/     {0, 0, 0, 9, 0, 10, 0, 0, 0},
//    /*5*/     {0, 0, 4, 14, 10, 0, 2, 0, 0},
//    /*6*/     {0, 0, 0, 0, 0, 2, 0, 1, 6},
//    /*7*/     {8, 11, 0, 0, 0, 0, 1, 0, 7},
//    /*8*/     {0, 0, 2, 0, 0, 0, 6, 7, 0}
//    };
//    
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    printf("Input number of vertices: "); scanf("%d", &graph->v);
    printf("Input number of edges: "); scanf("%d", &graph->e);
    struct Edge *edge = (struct Edge *)malloc(graph->e * sizeof(struct Edge));
    for(int i = 0; i < graph->e; i++) {
        printf("Input vertice %d: \n", i);
        printf("x: "); scanf("%d", &edge[i].x);
        printf("y: "); scanf("%d", &edge[i].y);
        printf("weight: "); scanf("%d", &edge[i].weight);
    }
    
    struct Edge *array[graph->v - 1];
//    Kruskal(graph, array);
    return 0;
}
