//
//  main.c
//  BubbleSort
//
//  Created by Trang Nguyen on 3/18/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "BubbleSort.h"

int main(int argc, const char * argv[]) {
    int n;
    printf("Insert n: "); scanf("%d", &n);
    int a[n];
    printf("Insert numbers: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    BubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
