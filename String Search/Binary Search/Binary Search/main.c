//
//  main.c
//  Binary Search
//
//  Created by Trang Nguyen on 4/2/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "BinarySearch.h"

int main(int argc, const char * argv[]) {
    int a[7] = {1,2,3,4,5,6,7};
    printf("%d\n", BinarySearchIterative(a, 7, 1));
    printf("%d\n", BinarySearchRecursive(a, 0, 6, 1));
    return 0;
}
