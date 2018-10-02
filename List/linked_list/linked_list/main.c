#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *current = NULL;
struct node *head = NULL;

void beg_addnode (int);
void end_addnode (int);

int main () {
    end_addnode(5);
    end_addnode(7);
    return 0;
}

void beg_addnode (int v) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = v;
    new_node->next = head;
    head = new_node;
}

void end_addnode (int v) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node = head;
    while (new_node->next != NULL) {
        new_node = new_node->next;
    }
    new_node->next = (struct node*) malloc(sizeof(struct node));
    new_node->next->value = v;
    new_node->next->next = NULL;
}

