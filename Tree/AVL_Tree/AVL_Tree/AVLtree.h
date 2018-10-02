//
//  AVLtree.h
//  AVL_Tree
//
//  Created by Trang Nguyen on 3/12/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#ifndef AVLtree_h
#define AVLtree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *left;
    int data;
    struct Node *right;
    int height;
} AVLNode;

int Height(AVLNode *);
AVLNode *Insert(AVLNode *, AVLNode*, int);
void PreOrder (AVLNode *);
#endif /* AVLtree_h */

