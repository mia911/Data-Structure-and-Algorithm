//
//  main.cpp
//  Day_
//
//  Created by Trang Nguyen on 9/28/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
// Day loi la day giam dan roi tang dần: 32456. 32 là dãy giảm dần, 2456 là dãy tăng dần. Tìm dãy lôi lớn nhất
// mang 2 chieu:

#include <iostream>

using namespace std;

int a[100];
int n;
int flag[100][2];
int flag_lis[100];

void Day_Loi() {
    for(int i = 0; i < n; i++) {
        flag[i][0] = flag[i][1] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] < a[j]) {
                flag[i][0] = max(flag[i][0], flag[j][0] + 1);
            }
            if(a[i] > a[j]) {
                flag[i][1] = max(flag[i][1], max(flag[j][0], flag[j][1]) + 1) ;
            }
        }
    }
    
    int max_Day_Loi = -100;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            if(max_Day_Loi < flag[i][j]) {
                max_Day_Loi = flag[i][j];
            }
        }
    }
    cout<<max_Day_Loi;
}

int lis_dec(int i) {
    int flag_lis_dec[i + 1];
    for(int j = 0; j <= i; j++) {
        flag_lis_dec[j] = 1;
    }
    
    for(int j = 1; j <= i; j++) {
        for(int k = 0; k < j; k++) {
            if(a[j] < a[k]) {
                flag_lis_dec[j] = max(flag_lis_dec[j], flag_lis_dec[k] + 1);
            }
        }
    }
    
    return flag_lis_dec[i];
}

int lis_inc(int i) {
    int flag_lis_inc[n];
    for(int j = 0; j < n; j++) {
        flag_lis_inc[j] = 1;
    }
    
    for(int j = n - 2; j >= i; j--) {
        for(int k = n - 1; k > j; k--) {
            if(a[j] < a[k]) {
                flag_lis_inc[j] = max(flag_lis_inc[j], flag_lis_inc[k] + 1);
            }
        }
    }
    return flag_lis_inc[i];
}

void max_i_loi() {
    int tmp = 0;
    int max_loi = 0;
    for(int i = 0; i < n; i++) {
        tmp = lis_dec(i) + lis_inc(i) - 1;
        max_loi = max(max_loi, tmp);
    }
    cout<<max_loi<<"\n";
}

void abc() {
    int max_lis = 0;
    for(int i = 0; i < n; i++) {
        flag_lis[i] = 1;
    }
    int save_i = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                flag_lis[i] = max(flag_lis[i], flag_lis[j] + 1);
                if(max_lis < flag_lis[i]) {
                    max_lis = flag_lis[i];
                    save_i = i;
                }
            }
        }
    }
    int save_lst[max_lis];
    save_lst[0] = a[save_i];
    for(int i = 1; i < max_lis; i++) {
        for(int j = 0; j < save_i; j++) {
            if(flag_lis[j] == max_lis - 1 && save_lst[i - 1] > a[j]) {
                save_lst[i] = a[j];
                max_lis -= 1;
                save_i = j;
                break;
            }
        }
    }
    for(int i = 0; i < max_lis; i++) {
        cout<<save_lst[i]<<" ";
    }
}

int main(int argc, const char * argv[]) {
    cout<<"Input n: "; cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
//    Day_Loi();
    abc();
    return 0;
}
