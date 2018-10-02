//
//  main.cpp
//  Sieu_Nguyen_To
//
//  Created by Trang Nguyen on 9/7/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int Chosen;
int n;

int isPrime(int x) {
    if(x == 1) {
        return 0;
    }
    
    for(int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int isSuperPrime(int x) {
    while(x > 0) {
        if(!isPrime(x)) {
            return 0;
        } else {
            x /= 10;
        }
    }
    return 1;
}

void SuperPrime(int i) {
    //kiem tra khi i >= n thi dung de quy
    if(i >= n) {
        printf("%d\n", Chosen);
        return;
    }
    
    for(int k = 1; k <= 9; k++) {
        Chosen = Chosen * 10 + k;
        if(isPrime(Chosen)) {
            SuperPrime(i + 1);
        }
        Chosen /= 10;
    }
}

int main(int argc, const char * argv[]) {
    printf("Nhap n: "); scanf("%d", &n);
    SuperPrime(0);
    return 0;
}
