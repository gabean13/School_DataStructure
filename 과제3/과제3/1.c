#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <Windows.h>
#include <time.h>

int top = -1;

void push(int*, int element);
int pop(int*);
void pushMillion(int*);
void popMillion(int*);
int findMin(int*);

int main() {

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);

	int* stack, element, resultElement;
	char order;
	float workTime;

	stack = (int*)calloc(1100000, sizeof(int));

	QueryPerformanceCounter(&start);

	QueryPerformanceCounter(&end);
	
	
	while (1) {
		scanf("%c", &order);
		getchar();

		if (order == 'q') {
			break;
		}
		if (order == 'p') {
			scanf("%d", &element);
			getchar();
			QueryPerformanceCounter(&start);
			push(stack, element);
			QueryPerformanceCounter(&end);

			printf("push %d", element);
		}
		else if (order == 'P') {
			QueryPerformanceCounter(&start);
			pushMillion(stack);
			QueryPerformanceCounter(&end);
			printf("pushMillion");
		}
		else if (order == 'o') {
			QueryPerformanceCounter(&start);
			resultElement = pop(stack);
			QueryPerformanceCounter(&end);
			printf("pop %d", resultElement);
		}
		else if (order == 'O') {
			QueryPerformanceCounter(&start);
			popMillion(stack);
			QueryPerformanceCounter(&end);
			printf("popMillion");
		}
		else if (order == 'f') {
			QueryPerformanceCounter(&start);
			resultElement = findMin(stack);
			QueryPerformanceCounter(&end);
			printf("min %d", resultElement);
		}
		diff.QuadPart = end.QuadPart - start.QuadPart;
		workTime = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
		printf(" (%d), cputime = %.10f \n", top+1, workTime);
	}

	free(stack);

	return 0;
}

void push(int* stack, int element) {
	top++;
	stack[top] = element;
	return;
}

int pop(int* stack) {
	top--;
	return stack[top + 1];
}
void pushMillion(int* stack) {

	int randomNum;
	srand(time(NULL));

	for (int i = 0; i < 1000000; i++) {
		randomNum = rand() % 9000 + 1000;
		push(stack, randomNum);
	}
}
void popMillion(int* stack) {

	for (int i = 0; i < 1000000; i++) {
		pop(stack);
	}

}
int findMin(int* stack) {
	int totalElement, min = stack[0];

	totalElement = top + 1;

	for (int i = 1; i < totalElement; i++) {
		if (stack[i] < min) {
			min = stack[i];
		}
	}

	return min;
}
