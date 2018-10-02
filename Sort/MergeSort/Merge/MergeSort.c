//
//  MergeSort.c
//  Merge
//
//  Created by Trang Nguyen on 3/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "MergeSort.h"

void Merge(int *arr, int *temp, int left, int mid, int right) {
    int i, left_end, size, temp_pos;
    left_end = mid - 1;
    temp_pos = left;
    size = right - left + 1;
    while ((left <= left_end) && (mid <= right)) {
        if (arr[left] <= arr[mid]) {
            temp[temp_pos] = arr[left];
            temp_pos = temp_pos + 1;
            left = left + 1;
        } else {
            temp[temp_pos] = arr[mid];
            temp_pos = temp_pos + 1;
            mid = mid + 1;
        }
    }
    while (left <= left_end) {
        temp[temp_pos] = arr[left];
        left = left + 1;
        temp_pos = temp_pos + 1;
    }
    while (mid <= right) {
        temp[temp_pos] = arr[mid];
        mid = mid + 1;
        temp_pos = temp_pos + 1;
    }
    for (i=0; i <= size; i++) {
        arr[right] = temp[right];
        right = right - 1;
    }
}

void MergeSort (int *arr, int *temp, int left, int right) {
    int mid;
    if (right > left) {
        mid = (right + left)/2;
        MergeSort(arr, temp, left, mid);
        MergeSort(arr, temp, mid + 1, right);
        Merge(arr, temp, left, mid + 1, right);
    }
}






