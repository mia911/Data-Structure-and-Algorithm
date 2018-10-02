//
//  main.c
//  X_trong_
//
//  Created by Trang Nguyen on 8/23/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>

int found;
int flag[100];
int minindex, maxindex;

void check(int a[], int n, int x) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= x) {
            if(a[i] == x) {
                printf("Yes\n");
                found = 1;
                return;
            }
        }
    }
    if(found == 0) {
        printf("No\n");
    }
}

void check_mid(int a[], int beg, int end, int x) {
    if(beg > end) {
        printf("No\n");
        return;
    }
    
    int mid = (beg + end)/2;
    
    if(a[mid] == x) {
        printf("Yes\n");
        found = 1;
        return;
    } else if(a[mid] > x) {
        check_mid(a, beg, mid - 1, x);
    } else {
        check_mid(a, mid + 1, end, x);
    }
}

void min_index(int a[], int beg, int end, int x) {
    if(beg > end) {
        return;
    }
    int mid = (beg + end)/2;
    
    if(a[mid] == x) {
        minindex = mid;
        min_index(a, beg, mid - 1, x);
    } else if(a[mid] > x) {
        min_index(a, beg, mid - 1, x);
    } else {
        min_index(a, mid + 1, end, x);
    }
}

void max_index(int a[], int beg, int end, int x) {
    if(beg > end) {
        return;
    }
    int mid = (beg + end)/2;
    
    if(a[mid] == x) {
        maxindex = mid;
        max_index(a, mid + 1, end, x);
    } else if(a[mid] > x) {
        max_index(a, beg, mid - 1, x);
    } else {
        max_index(a, mid + 1, end, x);
    }
}

int minmax_index(int a[], int beg, int end, int x) {
    if(beg > end) {
        return found;
    }
    int mid = (beg + end)/2;
    
    if(a[mid] == x) {
        found = 1;
        flag[mid] = 1;
    } else if(a[mid] > x) {
        minmax_index(a, beg, mid - 1, x);
    } else {
        minmax_index(a, mid + 1, end, x);
    }
    return found;
}
                  
void search(int a[], int x, int end) {
    int beg = 0;
    found = 0;
    while(beg <= end) {
        int mid = (beg + end)/2;
        if(x == a[mid]) {
            printf("yes\n");
            found = 1;
            return;
        } else if(x < a[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    if(found == 0) {
        printf("no\n");
    }
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Input n: "); scanf("%d", &n);
    int a[n];
    int x;
    
    printf("Input elements of a: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Input x: "); scanf("%d", &x);
    min_index(a, 0, n-1, x);
    printf("%d\n", minindex);
    max_index(a, 0, n-1, x);
    printf("%d\n", maxindex);
    return 0;
}
