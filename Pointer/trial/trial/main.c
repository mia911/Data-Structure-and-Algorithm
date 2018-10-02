#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *begin = NULL;
struct node *end = NULL;

void insert(int val) {
    struct node *add = (struct node*) malloc (sizeof(struct node));
    add->val = val;
    add->next = begin;
    begin = add;
}

int main() {
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    while (begin != 0) {
        printf("%d  ", begin->val);
        begin = begin->next;
    }
    printf("\n");
    return 0;
}