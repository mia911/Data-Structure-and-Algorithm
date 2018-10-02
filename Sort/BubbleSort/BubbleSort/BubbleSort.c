//
//  BubbleSort.c
//  BubbleSort
//
//  Created by Trang Nguyen on 3/18/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "BubbleSort.h"

void BubbleSort(int *arr, int n) {
    int pass, i, temp, swapped = 1;
    for (pass = n - 1; pass >= 0 && swapped; pass --) {
        swapped = 0;
        for (i = 0; i <= pass - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    }
}
