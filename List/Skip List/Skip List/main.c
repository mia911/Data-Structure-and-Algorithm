//
//  main.c
//  Skip List
//
//  Created by Trang Nguyen on 8/21/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "SkipList.h"

int main(int argc, const char * argv[]) {
    int i, *a, maxnum = atoi(argv[1]);
    initlist();
    if((a = malloc(maxnum * sizeof(*a))) == 0) {
        fprintf(stderr, "insufficient memory (a)\n");
        exit(1);
    }
    for(i = 0; i < maxnum; i++) {
        a[i] = rand();
        printf(")
    }
    return 0;
}
