#include <stdio.h>
#include <stdlib.h>

struct DynArrayQueue {
    int front, rear;
    int capacity;
    int *array;
};

struct DynArrayQueue *CreateDynQueue() {
    struct DynArrayQueue *Q = malloc(sizeof(struct DynArrayQueue));
    if (!Q) return NULL;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    if (!Q->array)
        return NULL;
    return Q;
}

int IsEmptyQueue(struct DynArrayQueue *Q) {
    return (Q->front == -1);
}

int IsFullQueue (struct DynArrayQueue *Q) {
    return ((Q->rear+1) % Q->capacity == Q->front);
}

int QueueSize(struct DynArrayQueue *Q) {
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void ResizeQueue(struct DynArrayQueue *Q) {
    int size = Q->capacity;
    Q->capacity = Q->capacity*2;
    Q->array = realloc(Q->array, Q->capacity);
    if(!Q->array) {
        printf("Memorry Error");
        return;
    }
    if (Q->front > Q->rear) {
        for (int i = 0; i < Q->front; i++) {
            Q->array[i + size] = Q->array[i];
        }
        Q->rear = Q->rear + size;
    }
}

void EnQueue (struct DynArrayQueue *Q, int data) {
    if (IsFullQueue(Q))
        ResizeQueue(Q);
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if (Q->front == -1) {
        Q->front = Q->rear;
    }
}

int DeQueue (struct DynArrayQueue *Q) {
    int data = 0;
    if (IsEmptyQueue(Q)) {
        printf("Queue is Empty");
        return 0;
    } else {
        data = Q->array[Q->front];
        if (Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front + 1) % Q->capacity;
    }
    return data;
}

void DeleteQueue (struct DynArrayQueue *Q) {
    if (Q) {
        if (Q->array)
            free(Q->array);
        free(Q->array);
    }
}

int main () {
    
}
































