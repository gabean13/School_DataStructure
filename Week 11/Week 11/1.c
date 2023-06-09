#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int q;

typedef struct Queue {
	int* elements;
	int front, rear;
}Queue;

void initQueue(Queue*);
int isEmpty(Queue*);
int isFull(Queue*);
void insertQueue(Queue*, int);
void deleteQueue(Queue*);
void printQueue(Queue*);

int main() {

	int n, element;
	char order;

	Queue queue;

	scanf("%d", &q);

	initQueue(&queue);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &order);
		if (order == 'I') {
			scanf("%d", &element);
			if (isFull(&queue)) {
				printf("overflow");
				printQueue(&queue);
				break;
			}
			insertQueue(&queue, element);
		}
		else if (order == 'D') {
			if (isEmpty(&queue)) {
				printf("underflow");
				break;
			}
			deleteQueue(&queue);
		}
		else if (order == 'P') {
			printQueue(&queue);
		}
	}

	return 0;
}
void initQueue(Queue*queue) {
	queue->front = 0;
	queue->rear = 0;

	queue->elements = (int*)calloc(q, sizeof(int));
}

int isEmpty(Queue* queue) {
	if (queue->front == queue->rear) {
		return 1;
	}
	return 0;
}
int isFull(Queue* queue) {
	if (queue->front == (queue->rear + 1) % q) {
		return 1;
	}
	return 0;
}

void insertQueue(Queue* queue, int element) {
	
	queue->rear = (queue->rear + 1) % q;
	queue->elements[queue->rear] = element;
	return;
}
void deleteQueue(Queue* queue) {

	queue->front = (queue->front + 1) % q;
	queue->elements[queue->front] = 0;
	return;
}
void printQueue(Queue* queue) {

	if (isEmpty(queue)) {
		return 0;
	}
	for (int i = 0; i < q; i++) {
		printf(" %d", queue->elements[i]);
	}
	printf("\n");

	return 0;
}

