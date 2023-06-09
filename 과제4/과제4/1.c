#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <Windows.h>
#include <time.h>


typedef struct Queue {
	int front, rear;
	int element[1100000];
}Queue;

//front, enqueue, dequeue
//isEmpty, push, top, pop

Queue* initQueue();
void enqueue(Queue*, int);
int dequeue(Queue*);
int front(Queue*);

int isEmpty(Queue*);
void push(Queue*, int);
void pushMillion(Queue*);
int pop(Queue*, Queue*);
int top(Queue*, Queue*);

int main() {
	
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);

	Queue* mainQueue, * subQueue;
	char order, getString[100], *s = NULL;
	int elements[100] = { 0 ,};
	int size = 0, temp, num = 0;
	float workTime;

	mainQueue = initQueue();
	subQueue = initQueue();

	while (1) {
		scanf("%c", &order);
		getchar();
		if (order == 'q') {
			break;
		}
		else if (order == 'S') {
			QueryPerformanceCounter(&start);
			if (isEmpty(mainQueue) == 1) {
				printf("Empty ");
			}
			else {
				printf("NonEmpty ");
			}
			QueryPerformanceCounter(&end);
		}
		else if (order == 't') {
			QueryPerformanceCounter(&start);
			temp = top(mainQueue, subQueue);
			QueryPerformanceCounter(&end);
			printf("%d ", temp);
		}
		else if (order == 'p') {
			num = 0;
			gets_s(getString, 100);
			for (s = strtok(getString, " "); s; s = strtok(NULL, " "), num++) {
				if (sscanf(s, "%d", &elements[num]) < 1) {
					break;
				}
			}
			QueryPerformanceCounter(&start);
			for (int i = 0; i < num; i++) {
				push(mainQueue, elements[i]);
			}
			QueryPerformanceCounter(&end);
			printf("OK ");
		}
		else if (order == 'P') {
			QueryPerformanceCounter(&start);
			pushMillion(mainQueue);
			QueryPerformanceCounter(&end);
			printf("OK ");
		}
		else if (order == 'o') {
			QueryPerformanceCounter(&start);
			temp = pop(mainQueue, subQueue);
			QueryPerformanceCounter(&end);
			if (temp != -1) {
				printf("%d ", temp);
			}
		}
		size = mainQueue->rear - mainQueue->front;
		diff.QuadPart = end.QuadPart - start.QuadPart;
		workTime = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
		printf("(%d), cputime = %.10f \n", size, workTime);
	}

}

Queue* initQueue() {
	Queue* queue;

	queue = (Queue*)malloc(sizeof(Queue));
	queue->front = queue->rear = -1;
	
	return queue;
}

int isEmpty(Queue* queue) {

	return (queue->front == queue->rear);

}

void enqueue(Queue* queue, int element) {
	
	queue->rear++;

	queue->element[queue->rear] = element;
	return;
}

int dequeue(Queue* queue){
	
	queue->front++;

	return queue->element[queue->front];
}

int front(Queue* queue) {

	int index = queue->front + 1;

	return queue->element[index];
}

void push(Queue* mainQueue, int element) {

	enqueue(mainQueue, element);
	return;
}

void pushMillion(Queue *mainQueue) {

	int randomElement;
	srand(time(NULL));

	for (int i = 0; i < 100000; i++) {
		randomElement = rand() % 90 + 10;
		push(mainQueue, randomElement);
	}

}

int pop(Queue* mainQueue, Queue* subQueue) {
	
	int temp, result;
	if (isEmpty(mainQueue)) {
		printf("Empty Stack Exception!! ");
		return -1;
	}

	while (mainQueue->rear - mainQueue->front != 1) {
		temp = dequeue(mainQueue);
		enqueue(subQueue, temp);
	}

	result = dequeue(mainQueue);

	while (subQueue->rear - subQueue->front != 0) {
		temp = dequeue(subQueue);
		enqueue(mainQueue, temp);
	}

	return result;
}

int top(Queue* mainQueue, Queue* subQueue) {

	int temp, result;
	if (isEmpty(mainQueue)) {
		printf("Empty Stack Exception!! ");
		return -1;
	}

	while (mainQueue->rear - mainQueue->front != 1) {
		temp = dequeue(mainQueue);
		enqueue(subQueue, temp);
	}

	result = dequeue(mainQueue);
	enqueue(subQueue, result);

	while (subQueue->rear - subQueue->front != 0) {
		temp = dequeue(subQueue);
		enqueue(mainQueue, temp);
	}

	return result;
}

