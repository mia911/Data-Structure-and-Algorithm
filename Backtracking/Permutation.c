//
//  main.c
//  N! Hoan
//
//  Created by Trang Nguyen on 8/12/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>

int a[10];
int n;
int danhdau[10];
void nHoanVi(int i) {
    if (i >= n) {
        for(int j = 0; j < n; j++) {
           printf("%d", a[j]);
        }
        printf("\n");
    }
    
    //chon phan tu thu i
    for(int j = 1; j <= n; ++j) {
        if (danhdau[j] != 1) {
            a[i] = j;
            danhdau[j] = 1;
            nHoanVi(i + 1);
            danhdau[j] = 0;
        }
    }
}            

int main(int argc, const char * argv[]) {
    printf("Nhap n: "); scanf("%d", &n);
    nHoanVi(0);
    return 0;
}
