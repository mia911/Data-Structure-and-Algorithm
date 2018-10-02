//
//  QuickSort.c
//  QuickSort
//
//  Created by Trang Nguyen on 3/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "QuickSort.h"

void Swap (int *arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

int Partition(int *arr, int start, int stop){
    int left, right;
    int pivot_item = arr[start];
    left = start;
    right = stop;
    while (left < right) {
        while (arr[left] <= pivot_item) {
            left ++;
        }
        while (arr[right] > pivot_item) {
            right --;
        }
        if (left < right) {
            Swap(arr, left, right);
        }
    }
    arr[start] = arr[right];
    arr[right] = pivot_item;
    return right;
}

void QuickSort(int *array, int start, int stop) {
    int pivot;
    if(stop > start) {
        pivot = Partition(array, start, stop);
        QuickSort(array, start, pivot - 1);
        QuickSort(array, pivot + 1, stop);
    }
}






