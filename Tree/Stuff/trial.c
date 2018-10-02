#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct ArrayQueue {
    int front, rear;
    int capacity;
    struct Node *array;
};

struct ArrayQueue *CreateQueue (int size) {
    struct ArrayQueue *Q = (struct ArrayQueue *) malloc (sizeof(struct ArrayQueue));
    Q->capacity = size;
    Q->front = Q->rear = 0;
    Q->array = malloc(Q->capacity * sizeof(struct Node));
    return Q;
}

int Queue_Size (struct ArrayQueue *Q) {
    return Q->rear;
}

int IsFull (struct ArrayQueue *Q) {
    if (Q->rear == Q->capacity) {
        return 1;
    } else {
        return 0;
    }
}

int IsEmpty (struct ArrayQueue *Q) {
    if (Q->rear == 0) {
        return 1;
    } else {
        return 0;
    }
}

void Resize (struct ArrayQueue *Q) {
    Q->capacity = Q->capacity * 2;
    Q->array = realloc(Q->array, Q->capacity);
}

void EnQueue (struct ArrayQueue *Q, struct Node root) {
    if (IsFull(Q)) {
        Resize(Q);
    }
    Q->rear = Q->rear + 1;
    Q->array[Q->rear] = root;
    if (Q->front == 0) {
        Q->front = Q->rear;
    }
}

struct Node *DeQueue (struct ArrayQueue *Q) {
    if (IsEmpty(Q)) {
        printf("Queue is empty\n");
        return 0;
    } else {
        struct Node *data = malloc(sizeof(struct Node));
        *data = Q->array[Q->front];
        if (Q->front == Q->rear) {
            Q->front = Q->rear = 0;
        } else {
            Q->front = Q->front + 1;
        }
        return data;
    }
}

void DeleteQueue (struct ArrayQueue *Q) {
    if (Q) {
        if (Q->array)
            free(Q->array);
        free(Q);
    }
}

void InsertTree (struct Node *root, int value) {
    struct ArrayQueue *Q;
    struct Node *temp;
    struct Node *NewNode = malloc(sizeof(struct Node));
    
    NewNode->left = NewNode->right = NULL;
    NewNode->value = value;
    
    if (!NewNode) {
        printf("Memory Error\n");
        return;
    }
    
    if (!root) {
        root = NewNode;
        return;
    }
    
    Q = CreateQueue(10);
    EnQueue(Q, root);
    while (IsEmpty(Q) == 0) {
        temp = DeQueue(Q);
        if (temp->left != NULL) {
            EnQueue(Q, *temp->left);
        } else {
            temp->left = NewNode;
            DeleteQueue(Q);
            return;
        }
        if(temp->right) {
            EnQueue(Q, *temp->right);
        } else {
            temp->right = NewNode;
            DeleteQueue(Q);
            return;
        }
    }
    DeleteQueue(Q);
}

void PostOrder(struct Node *root) {
    if (root) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d", root->value);
    }
}

int main () {
    struct Node *root = malloc(sizeof(root));
    InsertTree(root, 1);
    InsertTree(root, 2);
    InsertTree(root, 3);
    InsertTree(root, 4);
    InsertTree(root, 5);
    InsertTree(root, 6);
    PostOrder(root);
    return 0;
}





















































