//
//  main.c
//  BruteForce
//
//  Created by Trang Nguyen on 4/2/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include "BruteForce.h"

int main(int argc, const char * argv[]) {
    char t[12] = "trang nguyen";
    char p[5] = "ng ng";
    printf("%d\n", BruteForce(t, 12, p, 5));
    return 0;
}
