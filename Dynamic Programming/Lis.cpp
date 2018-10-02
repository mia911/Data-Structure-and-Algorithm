//
//  main.cpp
//  lis
//
//  Created by Trang Nguyen on 9/24/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//
// longest increasing subsequence

#include <iostream>

using namespace std;

int n;
int a[100];
int max_lis = -100;
int max_lis_i;

int lis(int end) {
    if (end == 1) {
        return 1;
    }
    
    int res, max_lis_i = 0;
    
    for(int i = 1; i < end; i++) {
        res = lis(i - 1);
        if(a[i - 1] <= a[end - 1] && res + 1 > max_lis_i) {
            max_lis_i = res + 1;
        }
    }
    
    max_lis = max(max_lis_i, max_lis);
    return max_lis_i;
}

int length_i[100];

void dyn_prog() {
    for(int i = 0; i < n; i++) {
        length_i[i] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j] && length_i[i] < length_i[j] + 1)
                length_i[i] = length_i[j] + 1;
        }
    }
    int max_length = -100;
    int max_i = 0;
    
    for(int i = 0; i < n; i++) {
        if(max_length <= length_i[i]) {
            max_length = length_i[i];
            max_i = i;
        }
    }
    
    cout<<max_length<<"\n";
    
    int lis_arr[max_length];
    int count = 1;
    
    lis_arr[0] = a[max_i];
    
    while(max_length > 1) {
        for(int i = 0; i < max_i; i++) {
            if(length_i[i] + 1 == length_i[max_i] && a[i] < lis_arr[count - 1]) {
                lis_arr[count] = a[i];
                count++;
                max_i = i;
                break;
            }
        }
        max_length -= 1;
    }

    for(int i = count - 1; i >= 0; i--)
        cout<<lis_arr[i]<<" ";
}

int main(int argc, const char * argv[]) {
    cout<<"Input n: "; cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
//    lis(n);
//    cout<<max_lis;
    dyn_prog();
    return 0;
}
