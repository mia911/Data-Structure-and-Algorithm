//
//  main.cpp
//  Phan_so
//
//  Created by Trang Nguyen on 9/19/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int a[100];
int b[100];
float phanso[100];
float phanso_sort[100];
int arr_index[100];
int arr_index_sort[100];
int n;

void Merge(int beg, int mid, int end) {
    int i = beg;
    int j = mid + 1;
    int cnt_sort = 0;
    while(i <= mid || j <= end) {
        if(i > mid && j <= end) {
            for(int k = j; k <= end; k++) {
                phanso_sort[cnt_sort] = phanso[k];
                arr_index_sort[cnt_sort] = arr_index[k];
                j++;
                cnt_sort++;
            }
        }
        
        if(i <= mid && j > end) {
            for(int k = i; k <= mid; k++) {
                phanso_sort[cnt_sort] = phanso[k];
                arr_index_sort[cnt_sort] = arr_index[k];
                i++;
                cnt_sort++;
            }
        }
        
        if(phanso[i] > phanso[j]) {
            phanso_sort[cnt_sort] = phanso[j];
            arr_index_sort[cnt_sort] = arr_index[j];
            j++;
            cnt_sort++;
        } else {
            phanso_sort[cnt_sort] = phanso[i];
            arr_index_sort[cnt_sort] = arr_index[i];
            i++;
            cnt_sort++;
        }
    }
    
    for(int k = 0; k < cnt_sort; k++) {
        phanso[k] = phanso_sort[k];
        arr_index[k] = arr_index_sort[k];
    }
}

void MergeSort(int beg, int end) {
    if(beg >= end)
        return;
    
    int mid = (end - beg)/2;
    MergeSort(beg, mid);
    MergeSort(mid + 1, end);
    Merge(beg, mid, end);
}

int main(int argc, const char * argv[]) {
    cout<<"Input n: ";
    cin>>n;
    cout<<"A: \n";
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    cout<<"B: \n";
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }
    
    for(int i = 0; i < n; i++) {
        arr_index[i] = i;
    }
    
    for(int i = 0; i < n; i++) {
        phanso[i] = (float) a[i]/b[i];
    }
    MergeSort(0, n-1);
    
    for(int i = 0; i < n; i++) {
        printf("%d/%d  ", a[arr_index[i]], b[arr_index[i]]);
    }
    cout<<"\n";
    
    for(int i = 0; i < n; i++) {
        cout<<phanso[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<arr_index[i]<<" ";
    }
    return 0;
}
