//
//  k-largest.c
//  k-largest
//
//  Created by Trang Nguyen on 7/21/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "k-largest.h"

int k_largest(int *arr, int n, int k) {
    int count = 0;
    int array[5];
    while(count != k) {
        int i = 0, j = 0;
        int max = 0;
        for(i = 0; i < n; i++) {
            if(max < arr[i]) {
                max = arr[i];
            }
            for(j = 0)
        }
    }
    return array[4];
}
