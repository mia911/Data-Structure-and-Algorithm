//
//  main.cpp
//  Q_truy_van
//
//  Created by Trang Nguyen on 9/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

int q;
int l[100];
int r[100];
int n;
int arr[100];
int tong[100];
int tong_can_tim[100];

int main(int argc, const char * argv[]) {
    cout<<"Input n: "; cin>>n;
    cout<<"Input array: ";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    cout<<"Input q: "; cin>>q;
    
    cout<<"Input l: ";
    for(int i = 0; i < q; i++) {
        cin>>l[i];
    }
    
    cout<<"Input r: ";
    for(int i = 0; i < q; i++) {
        cin>>r[i];
    }
    
    int temp = 0;
    for(int i = 0; i < n; i++) {
        temp += arr[i];
        tong[i] = temp;
    }
    
    for(int i = 0; i < q; i++) {
        if(l[i] == 0) {
            tong_can_tim[i] = tong[r[i]];
        }
        tong_can_tim[i] = tong[r[i]] - tong[l[i] - 1];
    }
//    for(int i = 0; i < q; i++) {
//        for(int j = l[i]; j <= r[i]; j++) {
//            tong[i] += arr[j];
//        }
//    }
    
    for(int i = 0; i < q; i++) {
        cout<<tong_can_tim[i]<<" ";
    }
    return 0;
}
