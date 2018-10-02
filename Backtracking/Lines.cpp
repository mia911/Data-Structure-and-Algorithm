//
//  main.cpp
//  Lines
//
//  Created by Trang Nguyen on 8/31/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//
//các đoạn cắt nhau

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int l[10];
int r[10];
int n;
int select[10];
int flag = 0;
int count_max;
//int count_max1;

int is_cross(int a, int b, int x, int y) {
    if(a >= y) return 0;
    if(b <= x) return 0;
    return 1;
}

void no_cross_line(int j) {
    if(j >= n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(select[i] == 1) {
                flag = 0;
                for(int k = 0; k < n; k++) {
                    if(select[k] == 1) {
                        if(is_cross(l[i], r[i], l[k], r[k])) {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if(flag) {
                break;
            }
        }
        
        if(flag) {
            for(int i = 0; i < n; i++) {
                if(select[i] == 1) {
                    count ++;
                    printf("%d", count);
                    return;
                }
            }
        }
    }
    
    select[j] = 1;
    no_cross_line(j + 1);
    
    select[j] = 0;
    no_cross_line(j + 1);
}

void add_line(int z) {
    if(z >= n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(select[i] == 1) {
                count++;
            }
        }
        count_max = max(count_max, count);
        return;
    }
    
    int can_add = 1;
    for(int i = 0; i < z; i++) {
        if(select[i] == 1) {
            if(is_cross(l[i], r[i], l[z], r[z])) {
                can_add = 0;
                break;
            }
        }
    }
    
    if(can_add) {
        select[z] = 1;
        add_line(z + 1);
    }
    
    select[z] = 0;
    add_line(z + 1);
    
}

void shortcut() {
    int l_select = -100;
    int r_select = -100;
    int r_found[n];
    int i, j;
    
    while(1) {
        int count = 0;
        int min_select = 0;
        for(i = 0; i < n; i++) {
            if(r_select <= l[i] && select[i] == 0) {
                r_found[count] = i;
                count++;
            }
        }
        
        int min_r = 1000;
        for(j = 0; j < count; j++) {
            if(min_r > r[r_found[j]]) {
                min_r = r[r_found[j]];
                min_select = r_found[j];
            }
        }
        
        if(count == 0) {
            break;
        }
        
        select[min_select] = 1;
        l_select = l[min_select];
        r_select = r[min_select];
        printf("[%d %d]  ", l[min_select], r[min_select]);
    }
}

int main(int argc, const char * argv[]) {
    n = 3;
    for(int i = 0; i < n; i++) {
        printf("Input left: ");
        scanf("%d", &l[i]);
    }
    for(int i = 0; i < n; i++) {
        printf("Input right: ");
        scanf("%d", &r[i]);
    }
//    no_cross_line(0);
//    add_line(0);
//    printf("%d\n", count_max);
    shortcut();
    return 0;
}
