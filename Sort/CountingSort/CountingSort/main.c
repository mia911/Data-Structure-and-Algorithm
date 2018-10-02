//
//  main.c
//  CountingSort(Mac)
//
//  Created by Trang Nguyen on 3/27/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "CountingSort.h"

int main(int argc, const char * argv[]) {
    int a[12] = {6, 2, 6, 2, 6, 1, 1, 4, 6, 5, 1, 1};
    int b[12];
    CountingSort(a, 12, b);
    for (int i = 0; i < 12; i++) {
        printf("%d\n", b[i]);
    }
    return 0;
}
