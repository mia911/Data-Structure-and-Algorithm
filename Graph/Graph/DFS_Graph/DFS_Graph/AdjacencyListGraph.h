//
//  AdjacencyListGraph.h
//  DFS_Graph
//
//  Created by mixmex on 8/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#ifndef AdjacencyListGraph_h
#define AdjacencyListGraph_h

#include <stdio.h>
#include <stdlib.h>

//Khai báo cấu trúc dữ liệu cho các node trong danh sách liền kề
typedef struct nodeVertex{
    int vertex_dest;
    struct nodeVertex *link;
} AdjListNode;

//Khai báo cấu trúc dữ liệu lưu trữ các đỉnh đầu của danh sách liền kề
typedef struct adjList{
    AdjListNode *head;
}AdjList;

//Khai báo cấu trúc dữ liệu lưu trữ Graph
typedef struct adjGraph{
    int V; //Số lượng đỉnh
    int isDirectGraph; //co huong hay vo huong
    AdjList *arrayAdjList; //dinh
}AdjGraph;

AdjGraph *createGraph(int, int);
void printGraph(AdjGraph *);
void addEdge(AdjGraph *, int, int);

#endif /* AdjacencyListGraph_h */
