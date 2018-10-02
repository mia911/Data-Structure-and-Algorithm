//
//  BucketSort.c
//  BucketSort
//
//  Created by Trang Nguyen on 7/1/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "BucketSort.h"

void BucketSort(int *a, int arr_size) {
    int i, j, k;
    int buckets[10];
    for(j = 0; j < 10; j++) {
        buckets[j] = 0;
    }
    for(i = 0; i < arr_size; i++) {
        ++buckets[a[i]];
    }
    for(i = 0, j = 0; j < 10; j++) {
        for(k = buckets[j]; k > 0; --k) {
            a[i++] = j;
        }
    }
}
