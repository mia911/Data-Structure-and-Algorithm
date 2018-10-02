#include <stdio.h>
#include <stdlib.h>

typedef struct stack_struct {
    int top;
    int capacity;
    int *array;
} Stack;

Stack *CreateStack() {
    Stack *s = (Stack *) malloc (sizeof(Stack));
    if (!s) return NULL;
    s->capacity = 5;
    s->top = -1;
    s->array = (int *) malloc (s->capacity * sizeof(int));
    return s;
}

int EmptyStack (Stack *s) {
    return (s->top == -1);
}

int FullStack (Stack *s) {
    return (s->top == s->capacity - 1);
}

void Push (Stack *s, int data) {
    if (FullStack(s)) printf("Stack overflow\n");
    else
        s->array[++s->top] = data;
}

int Pop (Stack *s) {
    if (EmptyStack(s)) {
        printf("Stack is empty\n");
        return 0;
    } else {
        return (s->array[s->top--]);
    }
}

void Delete (Stack *s) {
    if (s) {
        if (s->array) free (s->array);
        free(s);
    }
}

int main () {
    Stack *s = CreateStack();
    Push (s, 1);
    Push (s, 2);
    Push (s, 3);
    printf("%d\n", Pop(s));
    printf("%d\n", Pop(s));
    printf("%d\n", Pop(s));
    printf("%d\n", Pop(s));
}