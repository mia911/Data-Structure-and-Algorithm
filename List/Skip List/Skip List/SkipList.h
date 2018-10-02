//
//  SkipList.h
//  Skip List
//
//  Created by Trang Nguyen on 8/21/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#ifndef SkipList_h
#define SkipList_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSKIPLEVEL 5

typedef struct Node {
    int key;
    int value;
    struct Node **forward;
} Node;

typedef struct SkipList {
    struct Node *header;
    int level; //current level of the list
    int size;
} SkipList;

SkipList *initList(SkipList *);
struct ListNode *insertElement(int);
void deleteElement(int);
struct ListNode *findElement(int);


#endif /* SkipList_h */













