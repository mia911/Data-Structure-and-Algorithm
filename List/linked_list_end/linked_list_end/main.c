#include <stdio.h>
#include <stdlib.h>

typedef struct List_Node {
    int value;
    struct List_Node *next;
} Node;

void add (int);
void display();
int search (int);
//Node *find (Node *, int);
void reverse();

Node *head = NULL;

int main() {
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    add(6);
    int n;

    printf("Input a number: "); scanf("%d", &n);
    printf("Number on the %dth from the bottom is: %d\n", n, search(n));
    
//    Node *result = find(head, n);
//    printf("Number on the %dth from the bottom is: %d\n", n, result->value);
//    display();
    reverse();
    display();
    return 0;
}

void add (int v) {
    if (head == NULL) {
        head = (Node*) malloc(sizeof(Node));
        head->value = v;
        head->next = NULL;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = (Node*) malloc(sizeof(Node));
        temp->next->value = v;
        temp->next->next = NULL;
    }
}

int search (int p) {
    int size = 0;
    Node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        size++;
    }
    
    if (head == NULL || p > size || p < 1) {
        return -1;
    } else {
        p = size - p;
        temp = head;
        while (p > 0) {
            temp = temp->next;
            p --;
        }
        return temp->value;
    }
}

//Node *find (Node *head, int p) {
//    Node *temp = head;
//    Node *n_node = head;
//    int count = 0;
//    while (temp != NULL) {
//        count ++;
//        if (p - count == 0) {
//            n_node = head;
//        } else if (p - count > 0) {
//            n_node = n_node->next;
//        }
//        temp = temp->next;
//    }
//    if (n_node) {
//        return n_node;
//    } else {
//        return NULL;
//    }
//}

void display() {
    Node *temp = head;
    int count = 0;
    if (head->next == NULL) {
        printf("Pointer 1: %d\n", temp->value);
    } else {
        while (temp != NULL) {
            count++;
            printf("Pointer %d: %d\n", count, temp->value);
            temp = temp->next;
        } 
    }
}

void reverse () {
    Node *curr_node = head;
    Node *prev_node = NULL;
    Node *next_node = NULL;
    while (curr_node != NULL) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    head = prev_node;
}