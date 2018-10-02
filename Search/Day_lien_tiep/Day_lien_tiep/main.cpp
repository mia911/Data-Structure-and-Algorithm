//
//  main.cpp
//  Day_lien_tiep
//
//  Created by Trang Nguyen on 9/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[100];
int n;
int sum_i[100];
int min_sum_i[100];

//void max_subarray() {
//    int temp = 0;
//    if(arr[0] >= 0) {
//        min_sum_i[0] = 0;
//    } else {
//        min_sum_i[0] = arr[0]; //= min(sum_i[0], sum_i[1], .. , sum_i[i]
//    }
//    for(int i = 0; i < n; i++) {
//        temp += arr[i];
//        sum_i[i] = temp; //= arr[0] + arr[1] + .. + arr[i]
//    }
//    
//    for(int i = 1; i < n + 1; i++) {
//        if(min_sum_i[i - 1] >= sum_i[i]) {
//            min_sum_i[i] = sum_i[i];
//        } else {
//            min_sum_i[i] = min_sum_i[i - 1];
//        }
//    }
//    
//    int max_sum = -100;
//    for(int i = 0; i < n; i++) {
//        if(i == 0) {
//            if(max_sum < sum_i[0])
//                max_sum = sum_i[0];
//        } else {
//            if(max_sum < sum_i[i] - min_sum_i[i - 1]) {
//                max_sum = sum_i[i] - min_sum_i[i - 1];
//            }
//        }
//        
//    }
//    
//    cout<<max_sum;
//}

void max_subarray() {
    int max_sum = arr[0];
    sum_i[0] = arr[0];
    min_sum_i[0] = min(sum_i[0], 0);
    
    for(int i = 1; i < n; i++) {
        sum_i[i] = sum_i[i - 1] + arr[i];
        min_sum_i[i] = min(sum_i[i], min_sum_i[i - 1]);
        if(max_sum < sum_i[i] - min_sum_i[i - 1])
            max_sum = sum_i[i] - min_sum_i[i - 1];
    }
    
    cout<<max_sum;
}

void no_saved_arr() {
    int min_sum = 0;
    int sum_arr = 0;
    int result = -100;
    for(int i = 0; i < n; i++) {
        sum_arr += arr[i];
        int v = sum_arr - min_sum;
        if(result < v)
            result = v;
        min_sum = min(min_sum, sum_arr);
    }
    cout<<result;
}

int main(int argc, const char * argv[]) {
    cout<<"Input n: "; cin>>n;
    
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
//    int max = -100;
//    for(int i = 0; i < n; i++) {
//        int tong = 0;
//        for(int j = i; j < n; j++) {
//            tong += arr[j];
//            if(max < tong) {
//                max = tong;
//            }
//        }
//    }
//    cout<<max;
    max_subarray();
    return 0;
}
