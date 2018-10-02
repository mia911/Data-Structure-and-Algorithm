//
//  main.c
//  Merge
//
//  Created by Trang Nguyen on 3/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "MergeSort.h"

int main(int argc, const char * argv[]) {
    int a[10] = {3, 2, 6, 4, 13, 89, 5, 4, 7, 9};
    int temp[10];
    MergeSort(a, temp, 0, 9);
    for (int i = 0; i < 9; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
