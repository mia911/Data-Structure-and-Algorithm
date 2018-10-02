//
//  main.cpp
//  Knight_Tour
//
//  Created by Trang Nguyen on 9/13/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n;
int step = 1;
int board[100][100];
int range_x[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int range_y[8] = {-2, 2, -2, 2, -1, 1, -1, 1};

int check(int step_x, int step_y) {
    if(step_y >= 0 && step_y < n && step_x >= 0 && step_x < n) {
        return 1;
    } else {
        return 0;
    }
}

void Knight_Tour(int x, int y) {
    if(step >= n*n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    
    for(int i = 0; i < 8; i++) {
        int step_x, step_y;
        step_x = x + range_x[i];
        step_y = y + range_y[i];
        if(check(step_x, step_y)) {
            if(board[step_x][step_y] == 0) {
                step += 1;
                board[step_x][step_y] = step;
                Knight_Tour(step_x, step_y);
                board[step_x][step_y] = 0;
                step -= 1;
            }
        }
//        step_x -= range_x[i];
//        step_y -= range_y[i];
    }
}

int main(int argc, const char * argv[]) {
    int x, y;
    cout<<"Input n:"; cin>>n;
    cout<<"Input x:"; cin>>x;
    cout<<"Input y:"; cin>>y;
//    for (x = 0; x < n; x++) {
//        for (y = 0; y < n; y++) {
            board[x][y] = 1;
            Knight_Tour(x, y);
//        }
//    }
    return 0;
}
