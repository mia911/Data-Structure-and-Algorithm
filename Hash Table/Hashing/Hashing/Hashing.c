//
//  Hashing.c
//  Hashing
//
//  Created by Trang Nguyen on 6/25/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "Hashing.h"

char FirstRepeatedChar(char *str) {
    int i;
    int len = strlen(str);
    int count[256];
    for(i = 0; i < len; ++i)
        count[i] = 0;
    for(i = 0; i < len; ++i) {
        if(count[str[i]] == 1) {
            printf("%c\n",str[i]);
            break;
        }
        else
            count[str[i]]++;
    }
    if(i == len)
        printf("No Repeated Characters\n");
    return 0;
}
