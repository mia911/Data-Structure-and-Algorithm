//
//  main.c
//  QuickSort
//
//  Created by Trang Nguyen on 3/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "QuickSort.h"

int main(int argc, const char * argv[]) {
    int a[8] = {4, 5, 3, 6, 2, 6, 7, 1};
    QuickSort(a, 0, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
