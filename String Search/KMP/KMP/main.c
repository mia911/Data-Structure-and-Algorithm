//
//  main.c
//  KMP
//
//  Created by Trang Nguyen on 5/7/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int F[50];

void PrefixTable(char *P, int m) {
    int i = 1, j = 0;
    F[0] = 0;
    while (i<m) {
        if(P[i] == P[j]) {
            F[i] = j + 1;
            i++;
            j++;
        } else if(j > 0) {
            j = F[j - 1];
        } else {
            F[i] = 0;
            i++;
        }
    }
}

int KMP(char*T, int n, char *P, int m) {
    int i=0, j= 0;
    PrefixTable(P, m);
    while(i < n) {
        if(T[i] == P[j]) {
            if(j == m - 1)
                return i - j;
            else {
                i++;
                j++;
            }
        } else if(j > 0)
            j = F[j-1];
        else i++;
    }
    return -1;
}

int main () {
    char P[] = "abcde";
    char T[] = "rwgaabcdekksabcde";
    
    printf("%d", KMP(T, 17, P, 5));
    return 0;
}
