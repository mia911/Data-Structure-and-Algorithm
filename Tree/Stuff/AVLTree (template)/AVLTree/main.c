#include <stdio.h>
#include "AVLtree.h"

int main () {
    AVLNode *N = NULL;
    N = Insert(N, 30);
    N = Insert(N, 20);
    N = Insert(N, 40);
    N = Insert(N, 10);
    N = Insert(N, 15);
    N = Insert(N, 24);
    N = Insert(N, 45);
    
    PreOrder(N);
    
    return 0;
}
