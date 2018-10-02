//
//  main.cpp
//  Xau_con
//
//  Created by Trang Nguyen on 9/7/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

string line;
int select[100];
int n;
string printed[100];
int arr_index;

void xau_Con(int i) {
    if(i >= n) {
        string word = "";
        int k = 0;
        int flag = 0;
        for(int j = 0; j < n; j++) {
            if(select[j] == 1) {
                word += line[j];
                k++;
            }
        }
        for(int l = 0; l < arr_index; l++) {
            if(word == printed[l]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printed[arr_index] = word;
            arr_index ++;
        }
        
        return;
    }
    
    select[i] = 1;
    xau_Con(i + 1);
    
    select[i] = 0;
    xau_Con(i + 1);
}

int main(int argc, const char * argv[]) {
    printf("Input n:"); scanf("%d", &n);
    printf("Input letter:");
    cin>>line;
    xau_Con(0);
    for(int i = 0; i < arr_index; i++) {
        cout<<printed[i]<<"\n";
    }
    return 0;
}
