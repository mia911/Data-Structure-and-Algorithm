//
//  AdjacencyListGraph.h
//  DFS_BFS(Gia Su)
//
//  Created by Trang Nguyen on 8/13/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#ifndef AdjacencyListGraph_h
#define AdjacencyListGraph_h

#include <stdio.h>
#include <stdlib.h>

//node trong danh sach lien ke
struct AdjListNode {
    int vertex_dest;
    struct AdjListNode *next;
};

//dinh dau cua danh sach lien ke
struct AdjList {
    struct AdjListNode *head;
};

struct AdjGraph {
    int V;//so luong dinh
    int isDirectGraph; //graph co huong hoac vo huong
    struct AdjList *arrayAdjList;
};

struct AdjGraph *createGraph(int, int);
void printGraph(struct AdjGraph*);
void addEdge(struct AdjGraph*, int, int);

#endif /* AdjacencyListGraph_h */
