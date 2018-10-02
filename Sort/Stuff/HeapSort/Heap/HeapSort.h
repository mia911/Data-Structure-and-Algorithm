//
//  HeapSort.h
//  Heap
//
//  Created by Trang Nguyen on 3/26/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap_struct {
    int *array;
    int count;
    int capacity;
    int heap_type;
} Heap;

Heap * CreateHeap (int, int);
void HeapSort(int[], int);
#endif /* HeapSort_h */
