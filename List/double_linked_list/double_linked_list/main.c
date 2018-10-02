#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *previous;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;
int size = 0;

void beg_add (int);
void end_add (int);
void mid_add (int, int);
void delete_node(int);
void display();
void clean();

int main () {
    beg_add(2);
    end_add(3);
    end_add(5);
    end_add(6);
    end_add(7);
    end_add(8);
    mid_add(4, 3);
    delete_node(7);
    display();
    clean();
    return 0;
}

void beg_add (int v) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    if (head == NULL) {
        new_node->value = v;
        new_node->next = NULL;
        new_node->previous = NULL;
        last = new_node;
    } else {
        head->previous = new_node;
        new_node->next = head;
        new_node->previous = NULL;
        new_node->value = v;
    }
    head = new_node;
    size ++;
}

void end_add (int v) {
    if (head == NULL) {
        beg_add(v);
    } else {
        last->next = (struct node *) malloc (sizeof(struct node));
        last->next->next = NULL;
        last->next->value = v;
        last->next->previous = last;
        last = last->next;
        size ++;
    }
}

void mid_add (int v, int p) {
    if (p > (size + 1) || p < 0) {
        return;
    } else if (p == (size + 1)) {
        if (head == NULL) {
            beg_add(v);
        } else {
            end_add(v);
        }
    } else if (p == 1) {
        beg_add(v);
    } else {
        if (head == NULL) {
            beg_add(v);
        } else {
            struct node *new_node = (struct node *) malloc (sizeof(struct node));
            if (p > (size / 2)) {
                struct node *temp = last;
                p = size - p;
                while (p > 0) {
                    temp = temp->previous;
                    p--;
                }
                new_node->value = v;
                new_node->next = temp;
                temp->previous->next = new_node;
                new_node->previous = temp->previous;
                temp->previous = new_node;
                size ++;
            } else if (p <= (size / 2)) {
                struct node *temp = head;
                p = p - 2;
                while (p > 0) {
                    temp = temp->next;
                    p--;
                }
                new_node->value = v;
                temp->next->previous = new_node;
                new_node->next = temp->next;
                new_node->previous = temp;
                temp->next = new_node;
                size ++;
            }
        }
    }
}

void delete_node(int p) {
    if (p > size || p < 1) {
        return;
    }
    else if (p == 1 && size == 1) {
        free(head);
        head = NULL;
        last = NULL;
    }
    else if (p == 1 && size > 1) {
        struct node *temp = head;
        head = head->next;
        head->previous = NULL;
        free(temp);
    }
    else if (p == size) {
        struct node *temp = last;
        last = last->previous;
        last->next = NULL;
        free(temp);
    } else {
        if (p > (size / 2)) {
            struct node *temp = last;
            p = size - p;
            while (p > 0) {
                temp = temp->previous;
                p--;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            free(temp);
        } else if (p <= (size / 2)) {
            struct node *temp = head;
            p = p - 1;
            while (p > 0) {
                temp = temp->next;
                p--;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            free(temp);
        }
    }
    size--;
}

void display() {
    struct node *temp = head;
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

void clean() {
    struct node *temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
    head = NULL;
}











