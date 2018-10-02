//
//  BFS.h
//  BFS
//
//  Created by Trang Nguyen on 8/5/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#ifndef BFS_h
#define BFS_h

#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int V;
    int E;
    int **Adj;
};

struct Graph *AdjMatrixofGraph();

void BFSTraversal(struct Graph*);

#endif /* BFS_h */
