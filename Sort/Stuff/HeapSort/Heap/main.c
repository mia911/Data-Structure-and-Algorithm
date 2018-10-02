//
//  main.c
//  Heap
//
//  Created by Trang Nguyen on 3/26/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "HeapSort.h"

int main(int argc, const char * argv[]) {
    int a[3] = {6, 9, 7};
    HeapSort(a, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
