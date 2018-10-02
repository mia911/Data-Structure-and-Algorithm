#include <stdio.h>
#include "BucketSort.h"

int main () {
    int a[3] = {4, 5, 3};
    BucketSort(a, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
