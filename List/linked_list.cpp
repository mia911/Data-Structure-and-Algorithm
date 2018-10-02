#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

struct node {
	int value;
	struct node *next;
};

struct node *head = NULL;
int size = 0;

void beg_addnode(int);
void end_addnode(int);
void mid_addnode(int, int);
void delete_node(int);
void display();
void clear();

int main() {
	beg_addnode(2);
	end_addnode(3);
	end_addnode(5);
	mid_addnode(4, 1);
	delete_node(2);
	display();
	clear();
	
	_CrtDumpMemoryLeaks();
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	return 0;
}

void beg_addnode(int v) {
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->value = v;
	new_node->next = head;
	head = new_node;
	size++;
}

void end_addnode(int v) {
	if (head == NULL) {
		head = (struct node*) malloc(sizeof(struct node));
		head->value = v;
		head->next = NULL;
	} else {
		struct node *new_node = head;
		while (new_node->next != NULL) {
			new_node = new_node->next;
		}
		new_node->next = (struct node*) malloc(sizeof(struct node));
		new_node->next->value = v;
		new_node->next->next = NULL;
	}
	size++;
}

void mid_addnode(int v, int p) {
	if (size < p) {
		return;
	} else {
		if (head == NULL) {
			head = (struct node*) malloc(sizeof(struct node));
			head->value = v;
			head->next = NULL;
		} else {
			struct node *new_node = head;
			while (new_node != NULL && p > 0) {
				new_node = new_node->next;
				p--;
			}
			if (p == 0 && new_node != NULL) {
				struct node *temp = (struct node*) malloc(sizeof(struct node));
				temp->value = v;
				temp->next = new_node->next;
				new_node->next = temp;
			}
		}
	}
	size++;
}

void delete_node(int p) {
	if (size < p) {
		return;
	}
	else if (p == 0 && size == 1) {
		free(head);
		head == NULL;
	}
	else if (p == 0 && size > 1) {
		struct node *temp = head;
		head = head->next;
		free(temp);
	}
	else if (p == (size - 1)) {
		struct node *temp = head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		struct node *end = temp->next;
		free(end);
		temp->next = NULL;
	}
	else {
		struct node *new_node = head;
		p = p - 1;
		while (new_node != NULL && p > 0) {
			new_node = new_node->next;
			p--;
		}
		if (p == 0 && new_node != NULL) {
			struct node *temp = new_node->next;
			new_node->next = temp->next;
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

void clear() {
	struct node *temp = head;
	while (head != NULL) {
		head = head->next;
		free(temp);
		temp = head;
	}
	head = NULL;
}