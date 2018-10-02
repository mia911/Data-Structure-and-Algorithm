//
//  main.cpp
//  Substring
//
//  Created by Trang Nguyen on 9/13/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

string s;
string dif_substring[100];
int n;
int count_subs;
string dif_substring_clone[100];

void Substring() {
    string temp;
    
    n = (int)s.length();
    
    for(int i = 0; i < n; i++) {
        temp = "";
        for(int j = i; j < n; j++) {
                temp += s[j];
            
            int flag = 0;
            for(int k = 0; k < count_subs; k++) {
                if(temp == dif_substring[k]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                dif_substring[count_subs] = temp;
                count_subs ++;
            }
        }
    }
}

void Merge(int beg, int mid, int end) {
    int i = beg;
    int j = mid + 1;
    int count_subs_clone = 0;
    while(i <= mid || j <= end) {
        if(i > mid && j <= end) {
            for(int k = j; k <= end; k++) {
                dif_substring_clone[count_subs_clone] = dif_substring[k];
                count_subs_clone ++;
            }
            j = end + 1;
        }
        
        if(j > end && i <= mid) {
            for(int k = i; k <= mid; k++) {
                dif_substring_clone[count_subs_clone] = dif_substring[k];
                count_subs_clone ++;
            }
            i = mid + 1;
        }
        
        if(dif_substring[i] > dif_substring[j]) {
            dif_substring_clone[count_subs_clone] = dif_substring[j];
            j++;
            count_subs_clone ++;
        } else {
            dif_substring_clone[count_subs_clone] = dif_substring[i];
            i++;
            count_subs_clone ++;
        }
    }
    for(int k = beg; k <= end; k++) {
        dif_substring[k] = dif_substring_clone[k - beg];
    }
}

void MergeSort(int beg, int end) {
    if(beg >= end) {
        return;
    }
    
    int mid = (beg + end)/2;
    MergeSort(beg, mid);
    MergeSort(mid + 1, end);
    Merge(beg, mid, end);
}

void shortcut_sort() {
    string temp;
    
    n = (int)s.length();
    
    for(int i = 0; i < n; i++) {
        temp = "";
        for(int j = i; j < n; j++) {
            temp += s[j];
            dif_substring[count_subs] = temp;
            count_subs ++;
        }
    }
    
    MergeSort(0, count_subs - 1);

    for(int i = 0; i < count_subs; i++) {
        if(i == count_subs - 1) {
            cout<<dif_substring[count_subs - 1];
        } else if(dif_substring[i] != dif_substring[i + 1]) {
            cout<<dif_substring[i]<<"\n";
        }
    }
}

int main(int argc, const char * argv[]) {
    cout<<"Input s: "; cin>>s;
//    Substring();
//    for(int i = 0; i < count_subs; i++) {
//        cout<<dif_substring[i]<<"\n";
//    }
    shortcut_sort();
    return 0;
}
