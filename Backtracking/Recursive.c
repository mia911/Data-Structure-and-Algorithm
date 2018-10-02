//
//  main.c
//  Duyet 2^n truong
//
//  Created by Trang Nguyen on 8/12/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>

int n;
int s;
int arr[100];
int sum;
int found = 0;
int ChiSo[100];
int m;
int ThemChiSo[100];

void Duyet(int i) {
    if(i >= n) {
        if(sum == s) {
            printf("yes");
            found = 1;
        }
        return;
    }
    
    
    
    sum += arr[i];
    Duyet(i + 1);
    
    if(found == 1) {
        return;
    }
    
    sum -= arr[i];
    Duyet(i + 1);
    
}

//mang 0 va 1
void DuyetInChiSo(int i) {
    if(i >= n) {
        if(sum == s) {
            found = 1;
            for(int j = 0; j < n; j++) {
                if(ChiSo[j] == 1) {
                    printf("%d  ", arr[j]);
                }
            }
            printf("\n");
        }
        return;
    }
    
    sum += arr[i];
    ChiSo[i] = 1;
    DuyetInChiSo(i + 1);
    
    
    sum -= arr[i];
    ChiSo[i] = 0;
    DuyetInChiSo(i + 1);
}

//Them phan tu moi vao mang
void DuyetThemPhanTu(int i) {
    if(i >= n) {
        if(sum == s) {
            for(int j = 0; j < m; j++) {
                printf("%d  ", ThemChiSo[j]);
            }
            printf("\n");
        }
        return;
    }
    
    sum += arr[i];
    ThemChiSo[m] = arr[i];
    m += 1;
    DuyetThemPhanTu(i + 1);
    
    
    sum -= arr[i];
    ThemChiSo[m] = 0;
    m -= 1;
    DuyetThemPhanTu(i + 1);
}

int main(int argc, const char * argv[]) {
    printf("Nhap n: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i); scanf("%d", &arr[i]);
    }
    printf("Nhap s: "); scanf("%d", &s);
    sum = 0;
//    Duyet(0);
//    DuyetInChiSo(0);
    DuyetThemPhanTu(0);
    printf("%d", sum);
    if(found == 0) {
        printf("No");
    }
    return 0;
}










