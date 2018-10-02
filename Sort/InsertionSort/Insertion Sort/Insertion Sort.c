//
//  Insertion Sort.c
//  Insertion Sort
//
//  Created by Trang Nguyen on 3/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "Insertion Sort.h"

void InsertionSort (int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        temp = arr[i];
        j = i;
        while (arr[j - 1] > temp && j >= 1) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}
