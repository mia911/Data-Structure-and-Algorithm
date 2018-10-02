//
//  UnweightedShortestPath.h
//  UnweightedShortestPath
//
//  Created by Trang Nguyen on 8/5/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#ifndef UnweightedShortestPath_h
#define UnweightedShortestPath_h

#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int V;
    int E;
    int **Adj;
};

struct Graph *AdjMatrixofGraph();
void UnweightedShortestPath(struct Graph*, int);

#endif /* UnweightedShortestPath_h */
