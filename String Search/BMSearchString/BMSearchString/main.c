//
//  main.c
//  BMSearchString
//
//  Created by mixmex on 4/5/17.
//  Copyright © 2017 mixmex. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int *computeLast(char *P, int m, int last[]){
    for (int c = 0; c<256; c++) {
        last[c] = 0;
    }
    for (int i=m-1; i>=0; i--) {
        if (last[P[i]] == 0) {
            last[P[i]] = i;
        }
    }
    return last;
}

int max(int a, int b){
    if (a>b) {
        return a;
    }
    return b;
}

void BoyerMoore(char *P, int m, char *T, int n){
    int last[256];
    computeLast(P, m, last);
    int s = 0;
    while (s <= n-m) {
        int j=m-1;
        while (j>0 && T[j+s] == P[j]) {
            j--;
        }
        if (j==0) {
            printf("%d \n", s);
            s++;
        }else{
            int k = last[T[j+s]];
            s = s + max(j-k, 1);
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    char P[] = "abcde";
    char T[] = "rwgaabcdekksabcde";
    
    BoyerMoore(P, 5, T, 17);
    
    return 0;
}
