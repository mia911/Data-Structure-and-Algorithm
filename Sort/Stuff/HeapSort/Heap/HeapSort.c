//
//  HeapSort.c
//  Heap
//
//  Created by Trang Nguyen on 3/26/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "HeapSort.h"

Heap *CreateHeap (int capacity, int heap_type) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->heap_type = heap_type;
    h->count = 0;
    h->capacity = capacity;
    h->array = (int *)malloc(sizeof(int) * h->capacity);
    return h;
}

int Parent(Heap *h, int i) {
    if (i <= 0 || i >= h->count)
        return -1;
    return i-1/2;
}

int LeftChild (Heap *h, int i){
    int left = 2 * i + 1;
    if(left >= h->count)
        return -1;
    return left;
}

int RightChild (Heap *h, int i) {
    int right = 2 * i + 2;
    if(right >= h->count)
        return -1;
    return right;
}

int GetMaximum(Heap *h) {
    if(h->count == 0)
        return 1;
    return h->array[0];
}

void PercolateDown(Heap *h, int i) {
    int l, r, max, temp;
    l = LeftChild(h, i);
    r = RightChild(h, i);
    if(l != -1 && h->array[l] > h->array[i])
        max = 1;
    else
        max = i;
    if (r != -1 && h->array[r] > h->array[max])
        max = r;
    if(max != i) {
        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp;
    }
    PercolateDown(h, max);
}

int DeleteMax(Heap *h) {
    int data;
    if(h->count == 0)
        return -1;
    data = h->array[0];
    h->array[0] = h->array[h->count-1];
    h->count--;
    PercolateDown(h, 0);
    return data;
}

void ResizeHeap(Heap *h) {
    int *array_old = h->array;
    h->array = (int *)malloc(sizeof(int) * h->capacity * 2);
    for (int i = 0; i < h->capacity; i++) {
        h->array[i] = array_old[i];
    }
    h->capacity *= 2;
    free(array_old);
}

int Insert(Heap *h, int data) {
    int i;
    if(h->count == h->capacity)
        ResizeHeap(h);
    
    h->count++;
    i = h->count - 1;
    while(i>=0 && data > h->array[(i-1)/2]) {
        h->array[i] = h->array[(i-1)/2];
        i = i-1/2;
    }
    h->array[i] = data;
    return data;
}

void BuildHeap(Heap *h, int a[], int n) {
    if(h == NULL)
        return;
    while (n > h->capacity) {
        ResizeHeap(h);
    }
    for (int i = 0; i < n; i++) {
        h->array[i] = a[i];
    }
    h->count = n;
    for (int i = (n-1)/2; i <= 0; i--)
        PercolateDown(h, i);
}

void HeapSort(int a[], int n) {
    int heap_type;
    Heap *h = CreateHeap(n, heap_type);
    int old_size, i, temp;
    BuildHeap(h, a, n);
    old_size = h->count;
    for (i = n-1; i > 0; i--) {
        temp = h->array[0];
        h->array[0] = h->array[h->count - 1];
        h->array[0] = temp;
        h->count--;
        PercolateDown(h, 0);
    }
    h->count = old_size;
}






























