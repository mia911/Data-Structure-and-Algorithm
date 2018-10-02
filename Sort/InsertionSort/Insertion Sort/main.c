//
//  main.c
//  Insertion Sort
//
//  Created by Trang Nguyen on 3/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "Insertion Sort.h"

int main(int argc, const char * argv[]) {
    int n;
    printf("Insert n: "); scanf("%d", &n);
    int a[n];
    printf("Insert numbers: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    InsertionSort(a, n);
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
