//
//  main.cpp
//  Media
//
//  Created by Trang Nguyen on 8/31/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
int a[5];

int f(int mid) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= mid) {  //tim so luong phan tu trong day a <= mid
            count ++;
        }
    }
    return count;
}

void k_largest(int a[], int k) {
    int max_a = 0;
    int min_a = a[0];
    for(int i = 0; i < n; i++) {
        if(min_a > a[i]) {
            min_a = a[i];
        }
        if(max_a < a[i]) {
            max_a = a[i];
        }
    }
    int kth = 0;
    while(min_a <= max_a) {
        int mid = (min_a + max_a)/2;
        if(f(mid) < k) {
            min_a = mid + 1;
        } else {
            kth = mid;
            max_a = mid - 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    n = 5;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int k = 2;
    k_largest(a, k);
    return 0;
}
