//
//  main.cpp
//  Bishop
//
//  Created by Trang Nguyen on 9/12/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, k;
int Board[100][100];
int Count_Bishop;


int isCrossed(int a, int b, int x, int y) {
    if(abs(a - x) == abs(b - y)) {
        return 1;
    } else {
        return 0;
    }
}

void findBishop(int x, int y) {
    if(Count_Bishop >= k) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                printf("%d ",Board[j][k]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    
    if(x >= n) {
        return;
    }
    
    int flag = 0;
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
            if(Board[j][k] == 1) {
               if(isCrossed(j, k, x, y)) {
                   flag = 1;
                   break;
               }
            }
        }
        if(flag == 1) {
            break;
        }
    }
    
    int next_x = x;
    int next_y = y + 1;
    
    if (y + 1 >= n) {
        next_x = x + 1;
        next_y = 0;
    }
    
    if(flag == 0) {
        Board[x][y] = 1;
        Count_Bishop += 1;
        findBishop(next_x, next_y);
        Board[x][y] = 0;
        Count_Bishop -= 1;
    }
    
    findBishop(next_x, next_y);
    
}

int main(int argc, const char * argv[]) {
    cout<<"Input n: "; cin>>n;
    cout<<"Input k: "; cin>>k;
    findBishop(0, 0);
    return 0;
}
