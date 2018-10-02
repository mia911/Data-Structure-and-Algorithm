#include <stdio.h>
#include "AVLtree.h"

int main () {
    AVLNode *N = NULL;
    N = Insert(N, N, 30);
    Insert(N, N, 20);
    Insert(N, N, 40);
    Insert(N, N, 10);
    Insert(N, N, 25);
    Insert(N, N, 50);
    Insert(N, N, 60);
    Insert(N, N, 15);
    
    PreOrder(N);
    
    return 0;
}
