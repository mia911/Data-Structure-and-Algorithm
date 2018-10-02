//
//  DFS.h
//  DFS
//
//  Created by Trang Nguyen on 8/5/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#ifndef DFS_h
#define DFS_h

#include <stdio.h>
#include <stdlib.h>


struct Graph {
    int V;
    int E;
    int **Adj;
};

struct Graph *AdjMatrixofGraph();

void DFSTraversal(struct Graph *);

#endif /* DFS_h */
