//
//  BruteForce.c
//  BruteForce
//
//  Created by Trang Nguyen on 4/2/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "BruteForce.h"

int BruteForce(char *t, int n, char *p, int m) {
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && p[j] == t[i + j])
            j = j + 1;
        if(j == m)
            return i;
    }
    return -1;
}
