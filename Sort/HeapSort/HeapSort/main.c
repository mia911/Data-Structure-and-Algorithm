//
//  main.c
//  HeapSort(template)
//
//  Created by Trang Nguyen on 3/26/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int i, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int max = i;
    
    if (left <= n && a[left] > a[i]) {
        max = left;
    }
    if (right <= n && a[right] > a[max]) {
        max = right;
    }
    if (max != i) {
        swap(&a[i], &a[max]);
        heapify(a, max, n - 1);
    }
}

void buildheap(int a[], int n) {
    for (int i = n/2; i>=0; i--) {
        heapify(a, i, n - 1);
    }
}

void heap_sort(int a[], int n) {
    buildheap(a, n);
    for (int i = n - 1; i>0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, 0, i-1);
    }
}

int main(int argc, const char * argv[]) {
    int a[10] = {0, 1, 5, 3, 6, 4, 1, 7, 0, 9};
    
    heap_sort(a, 10);
    
    for (int i = 0; i<10; i++) {
        printf("%d\n", a[i]);
    }
    printf("\n");
    return 0;
}


















