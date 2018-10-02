//
//  SkipList.c
//  Skip List
//
//  Created by Trang Nguyen on 8/21/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include "SkipList.h"

struct ListNode *insertElement(int data) {
    int i, newLevel;
    struct ListNode *update[MAXSKIPLEVEL + 1];
    struct ListNode *temp;
    temp = list.header;
    for(i = list.listLevel; i >= 0; i--) {
        while(temp->next[i] != list.header  && temp->next[i]->data < data) {
            
        }
    }
}
