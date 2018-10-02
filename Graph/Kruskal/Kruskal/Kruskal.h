//
//  Kruskal.h
//  Kruskal
//
//  Created by Trang Nguyen on 9/17/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#ifndef Kruskal_h
#define Kruskal_h

#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int x;
    int y;
    int weight;
};

struct Graph {
    int v;
    int e;
    struct Edge *edges;
};

void Kruskal(struct Graph *graph);

#endif /* Kruskal_h */
