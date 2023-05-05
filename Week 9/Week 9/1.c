#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int N, top = -1;

void push(char*, char);
char pop(char*);
void peek(char*);
void duplicate(char*);
void upRotate(char*, int);
void downRotate(char*, int);
void print(char*);
void fullStackException();
void emptyStackException();

int main() {
	char* stack;
	char order[10] = { 0 , }, element;
	int countNum, n;

	scanf("%d %d", &N, &countNum);

	stack = (char*)calloc(N, sizeof(char));

	for (int i = 0; i < countNum; i++) {
		scanf("%s", &order);
		if (strcmp(order, "PUSH") == 0) {
			getchar();
			scanf("%c", &element);
			push(stack, element);

		}else if (strcmp(order,"POP") == 0) {
			pop(stack);
		}
		else if (strcmp(order, "PEEK") == 0) {
			peek(stack);
		}
		else if (strcmp(order, "DUP") == 0) {
			duplicate(stack);
		}
		else if (strcmp(order, "UpR") == 0) {
			getchar();
			scanf("%d", &n);
			upRotate(stack, n);
		}
		else if (strcmp(order, "DownR") == 0) {
			getchar();
			scanf("%d", &n);
			downRotate(stack, n);
		}
		else if (strcmp(order, "PRINT") == 0) {
			print(stack);
		}
	}

	free(stack);

	return 0;
}

void push(char* stack, char element) {
	if (top == N - 1) {
		fullStackException();	
		return;
	}

	top++;
	stack[top] = element;
	return;
}
char pop(char* stack) {
	if (top == -1) {
		emptyStackException();
		return;
	}

	top--;
	return stack[top + 1];
}
void peek(char* stack) {
	if (top == -1) {
		emptyStackException();
		return;
	}

	printf("%c \n", stack[top]);
}
void duplicate(char* stack) {
	if (top == N - 2) {
		fullStackException();
		return;
	}

	char temp;

	temp = pop(stack);

	push(stack, temp);
	push(stack, temp);

	return;
}
void upRotate(char* stack, int n) {

	if (n > top + 1) {
		return;
	}
	
	char* save = (char*)calloc(n, sizeof(char));

	for (int i = 0; i < n; i++) {
		save[i] = pop(stack);
	}

	push(stack, save[0]);

	for (int i = n - 1; i > 0; i--) {
		push(stack, save[i]);
	}

	free(save);

	return;

}
void downRotate(char* stack, int n) {

	if (n > top + 1) {
		return;
	}

	char* save = (char*)calloc(n, sizeof(char));

	for (int i = 0; i < n; i++) {
		save[i] = pop(stack);
	}

	for (int i = n - 2; i >= 0; i--) {
		push(stack, save[i]);
	}

	push(stack, save[n - 1]);

	free(save);

	return;
}
void print(char* stack) {

	for (int i = top; i >= 0; i--) {
		printf("%c", stack[i]);
	}

	printf(" \n");

	return;
}

void fullStackException() {
	printf("Stack FULL \n");
	return;
}

void emptyStackException() {
	printf("Stack Empty \n");
	return;
}