#include <stdio.h>
#include <stdlib.h>

struct ArrayQueue {
    int front, rear;
    int capacity;
    int *array;
};

struct ArrayQueue *Queue (int size) {
    struct ArrayQueue *Q = malloc (sizeof(struct ArrayQueue));
    if (!Q) return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc (Q->capacity * sizeof(int));
    if (!Q->array)
        return NULL;
    return Q;
}

int IsEmptyQueue (struct ArrayQueue *Q) {
    return (Q->front == -1);
}

int IsFullQueue(struct ArrayQueue *Q) {
    return ((Q->rear+1) % Q->capacity == Q->front);
}

int QueueSize (struct ArrayQueue *Q) {
    if (IsEmptyQueue(Q)) {
        return 0;
    } else {
        return ((Q->capacity - Q->front + Q->rear) % (Q->capacity)) + 1;
    }
}

void EnQueue (struct ArrayQueue *Q, int data) {
    if (IsFullQueue(Q))
        printf("Queue Overflow");
    else {
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
        if (Q->front == -1) {
            Q->front = Q->rear;
        }
        printf("%d, %d\n", Q->front, Q->rear);
    }
}

int DeQueue (struct ArrayQueue *Q) {
    int data = 0;
    if (IsEmptyQueue(Q)) {
        printf("Quere is Empty");
        return 0;
    }
    else {
        data = Q->array[Q->front];
        if (Q->front == Q->rear) {
            Q->front = Q->rear = -1;
        } else {
            Q->front = (Q->front+1) % Q->capacity;
        }
        return data;
    }
}

void DeleteQueue(struct ArrayQueue *Q) {
    if (Q) {
        if (Q->array) {
            free(Q->array);
        }
        free(Q);
    }
}

int main () {
    struct ArrayQueue *My_Queue = Queue(5);
    EnQueue(My_Queue, 1);
    EnQueue(My_Queue, 2);
    EnQueue(My_Queue, 3);
    EnQueue(My_Queue, 4);
    EnQueue(My_Queue, 5);
    printf("Size of Queue: %d\n", QueueSize(My_Queue));
    
    int full_queue = IsFullQueue(My_Queue);
    printf("Queue is Full: %d\n", full_queue);
    
    printf("Output: %d\n", DeQueue(My_Queue));
    printf("Output: %d\n", DeQueue(My_Queue));
    printf("Output: %d\n", DeQueue(My_Queue));
    printf("Output: %d\n", DeQueue(My_Queue));
//    printf("Size of Queue: %d\n", QueueSize(My_Queue));
    printf("Output: %d\n", DeQueue(My_Queue));
    printf("Size of Queue: %d\n", QueueSize(My_Queue));
    int empty = IsEmptyQueue(My_Queue);
    printf("Queue is Empty: %d\n", empty);
    
    return 0;
}




            
            
            
            
            
            
            
            
            
            
            

