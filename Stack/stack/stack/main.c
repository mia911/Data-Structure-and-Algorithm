#include <stdio.h>
#include <stdlib.h>

typedef struct List_Node {
    int value;
    struct List_Node *next;
} Node;

Node *head = NULL;

void push (int);
int pop ();

int main () {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    while (head != NULL) {
        printf("%d\n", pop());
    }
    return 0;
}

void push(int v) {
    if (head == NULL) {
        head = (Node*) malloc(sizeof(Node));
        head->value = v;
        head->next = NULL;
    } else {
        Node *temp = (Node *) malloc (sizeof(Node));
        temp->value = v;
        temp->next = head;
        head = temp;
    }
}

int pop() {
    Node *temp = head;
    if (head != NULL) {
        head = head->next;
    } else {
        return -1;
    }
    int v = temp->value;
    free(temp);
    return v;
}