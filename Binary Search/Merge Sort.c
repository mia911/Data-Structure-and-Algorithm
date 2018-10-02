//
//  main.c
//  Merge_Sort
//
//  Created by Trang Nguyen on 8/28/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>

int arr[100];
int n;
int a[100];

void Merge(int *arr, int beg, int end, int mid) {
//    int a[end - beg + 1];
    for (int i = beg; i <= end; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    int firsthalf_count = beg;
    int secondhalf_count = mid + 1;
    for(int i = 0; i <= (end - beg); i++) {
        if((secondhalf_count > end) || ((firsthalf_count <= mid) && (arr[firsthalf_count] < arr[secondhalf_count]))) {
            a[i] = arr[firsthalf_count];
            printf("1st: %d  ", firsthalf_count);
            printf("\n");
            firsthalf_count++;
        } else {
            a[i] = arr[secondhalf_count];
            printf("2nd: %d  ", secondhalf_count);
            printf("\n");
            secondhalf_count++;
        }
    }
    
    for(int i = beg; i <= end; i++) {
        arr[i] = a[i - beg];
    }
    

}

void MergeSort(int *arr, int beg, int end) {
    if(end <= beg) {
        return;
    }
    int mid = (beg + end)/2;
    MergeSort(arr, beg, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, beg, end, mid);
}

int main(int argc, const char * argv[]) {
    printf("Input n: ");
    scanf("%d", &n);
    printf("Input the element in the array: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    MergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}
