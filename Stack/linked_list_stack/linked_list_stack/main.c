#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -1

typedef struct node_struct {
    int data;
    struct node_struct *next;
} Stack;

Stack *create_stack() {
    return NULL;
}

void Push (Stack *top, int value) {
    Stack *temp;
    temp = (Stack *) malloc(sizeof(Stack));
    if (!temp) return;
    printf("Done\n");
    temp->data = value;
    temp->next = top;
    top = temp;
}

int Empty_Stack (Stack *top) {
    return top == NULL;
}

int Pop (Stack *top) {
    int data;
    Stack *temp;
    printf("%d\n", top->data);
    if (Empty_Stack(top))
        return INT_MIN;
    temp = top;
    top = top->next;
    data = temp->data;
    free(temp);
    return data;
}

int Top (Stack *top) {
    if (Empty_Stack(top)) return INT_MIN;
    return top->next->data;
}

void Delete (Stack **top) {
    Stack *temp, *p;
    p = *top;
    while (p->next) {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
    free(p);
}

int main () {
    Stack *top = create_stack();
    Push(top, 1);
    Push(top, 2);
    Push(top, 3);
    printf("%d\n", Pop(top));
    printf("%d\n", Top(top));
    return 0;
}