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
    int left = 2*i;
    int right = 2*i + 1;
    int max = i;
    
    if (left <= n && a[left] > a[i]) {
        max = left;
    }
    if (right <= n && a[right] > a[max]) {
        max = right;
    }
    if (max != i) {
        swap(&a[i], &a[max]);
        heapify(a, max, n);
    }
}

void buildheap(int a[], int n) {
    for (int i = n/2; i>=1; i--) {
        heapify(a, i, n);
    }
}

void heap_sort(int a[], int n) {
    buildheap(a, n);
    for (int i = n ; i>1; i--) {
        swap(&a[1], &a[i]);
        heapify(a, 1, i-1);
    }
}

int main(int argc, const char * argv[]) {
    int a[6] = {0, 1, 5, 3, 6, 4};
    
    heap_sort(a, 5);
    
    for (int i = 1; i<6; i++) {
        printf("%d\n", a[i]);
    }
    printf("\n");
    return 0;
}


















