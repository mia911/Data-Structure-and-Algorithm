//
//  main.cpp
//  Counting Sort
//
//  Created by Trang Nguyen on 8/30/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[100];
int n;
int cnt[100];
int a[100];

void counting_sort(int arr[], int n) {
    int max = 0;
    for(int i = 0; i < n; i++) {
        cnt[arr[i]]++;
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    
    int j = 0;
    for(int i = 0; i < max + 1; i++) {
        if(cnt[i] != 0) {
            while(cnt[i] != 0) {
                a[j] = i;
                j++;
                cnt[i]--;
            }
        }
        if(j == (n - 1)) {
            return;
        }
    }
}

int main(int argc, const char * argv[]) {
    cout<<"Input n: ";
    cin>>n;
    cout<<"Input n elements: ";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    counting_sort(arr, n);
    for(int i = 0; i < n; i++) {
        cout<<a[i];
    }
    return 0;
}
