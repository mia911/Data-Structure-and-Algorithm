//
//  main.c
//  DFS
//
//  Created by Trang Nguyen on 8/5/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"

int main(int argc, const char * argv[]) {
    struct Graph *G = AdjMatrixofGraph();
    DFSTraversal(G);
    return 0;
}
