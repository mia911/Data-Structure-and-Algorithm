//
//  CountingSort.c
//  CountingSort(Mac)
//
//  Created by Trang Nguyen on 3/27/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "CountingSort.h"

void CountingSort(int *a, int n, int *b) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (k < a[i]) {
            k = a[i];
        }
    }
    
    int c[k + 1], i, j;
    
    for (i = 0; i <= k; i++) {
        c[i] = 0;
    }
    
    for (j = 0; j < n; j++) {
        c[a[j]] = c[a[j]] + 1;
    }
    
    for (i = 1; i <= k; i++) {
        c[i] = c[i] + c[i - 1];
    }
    
    for (j = n - 1; j >= 0; j--) {
        if (c[a[j]] != 0) {
            b[c[a[j]] - 1] = a[j];
            c[a[j]] = c[a[j]] - 1;
        }
    }
}
