//
//  main.cpp
//  knapsack
//
//  Created by Trang Nguyen on 9/26/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

int weight[100];
int val[100];
int n, w;

int knapsack(int n, int W) {
    if(n < 0)
        return 0;
    int res = knapsack(n - 1, W);
    if(W >= weight[n]) {
        return max(res, knapsack(n - 1, W - weight[n]) + val[n]);
    }
    return res;
}

int a[100][100];

void dyn_prog() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            a[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            a[i][j] = a[i - 1][j];
            if(j >= weight[i - 1])
                a[i][j] = max(a[i - 1][j], a[i - 1][j - weight[i - 1]] + val[i - 1]);
        }
    }
    
    cout<<a[n][w]<<"\n";
}

int main(int argc, const char * argv[]) {
//    freopen("5", "r", stdin);
    cout<<"Input the amount of items: ";
    cin>>n;
    
    cout<<"Input the weight of the bag: ";
    cin>>w;
    
    for(int i = 0; i < n; i++) {
        cout<<"Input value of item "<<i<<": ";
        cin>>val[i];
        cout<<"Input weight of item "<<i<<": ";
        cin>>weight[i];
    }
    int x = knapsack(n - 1, w);
    cout<<x<<"\n";
    dyn_prog();
    return 0;
}
