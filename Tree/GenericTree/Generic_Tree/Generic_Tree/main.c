#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *firstChild;
    struct Node *nextSibling;
};

int FindSum(struct Node *root) {
    if (!root) return 0;
    return root->data + FindSum(root->firstChild) + FindSum(root->nextSibling);
}
