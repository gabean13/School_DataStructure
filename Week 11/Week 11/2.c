#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node {
	int data;
	struct node* llink;
	struct node* rlink;
}node;

typedef struct Deque {
	node* front;
	node* rear;
}Deque;

int isEmpty(Deque*);
Deque* initDeque();
void add_front(Deque*, int X);
void add_rear(Deque*, int X);
int delete_front(Deque*);
int delete_rear(Deque*);
void print(Deque*);

int main() {

	Deque* deque = initDeque();
	int n, data;
	char order[2];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &order);
		if (strcmp(order, "AF") == 0) {
			getchar();
			scanf("%d", &data);
			add_front(deque, data);
		}
		else if (strcmp(order, "AR") == 0) {
			getchar();
			scanf("%d", &data);
			add_rear(deque, data);
		}
		else if (strcmp(order, "DF") == 0) {
			if (isEmpty(deque)) {
				printf("underflow \n");
				break;
			}
			delete_front(deque);
		}
		else if (strcmp(order, "DR") == 0) {
			if (isEmpty(deque)) {
				printf("underflow \n");
				break;
			}
			delete_rear(deque);
		}
		else if (strcmp(order, "P") == 0) {
			print(deque);
		}
	}

	return 0;
}

Deque* initDeque() {
	Deque* deque;
	deque = (Deque*)malloc(sizeof(Deque));
	deque->front = NULL;
	deque->rear = NULL;

	return deque;
}

int isEmpty(Deque* deque) {
	if (deque->front == NULL) {
		return 1;
	}
	return 0;
}

void add_front(Deque* deque, int X) {

	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = X;

	if (deque->front == NULL) {
		deque->front = newNode;
		deque->rear = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		deque->front->llink = newNode;
		newNode->rlink = deque->front;
		newNode->llink = NULL;
		deque->front = newNode;
	}

	return;
}
void add_rear(Deque* deque, int X){

	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = X;

	if (deque->rear == NULL) {
		deque->front = newNode;
		deque->rear = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		deque->rear->rlink = newNode;
		newNode->llink = deque->rear;
		newNode->rlink = NULL;
		deque->rear = newNode;
	}

	return;
}
int delete_front(Deque* deque) {

	node* temp = deque->front;
	int deleteData = temp->data;

	if (deque->front->rlink == NULL) {
		deque->front = NULL;
		deque->rear = NULL;
	}
	else {
		deque->front = deque->front->rlink;
		deque->front->llink = NULL;
	}

	free(temp);
	return deleteData;
}
int delete_rear(Deque* deque) {
	node* temp = deque->rear;
	int deleteData = temp->data;

	if (deque->rear->llink == NULL) {
		deque->front = NULL;
		deque->rear = NULL;
	}
	else {
		deque->rear = deque->rear->llink;
		deque->rear->rlink = NULL;
	}

	free(temp);
	return deleteData;
}
void print(Deque* deque) {

	node* temp = deque->front;

	while (temp) {
		printf(" %d", temp->data);
		temp = temp->rlink;
	}
	printf(" \n");

	return;
}
