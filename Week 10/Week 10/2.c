#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int top = -1;

void push(int*, char);
int pop(int*);
int getPostfix(char*, int*);
int isNotOperend(char);
int countPriority(char);

int main() {

	int num;
	char exp[100] = { NULL };
	int* stack;

	stack = (int*)calloc(100, sizeof(int));

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		getchar();
		scanf("%s", &exp);
		printf("%d \n", getPostfix(exp, stack));
	}

	free(stack);

	return 0;
}

void push(int* stack, char element) {

	top++;
	stack[top] = element;
	return;
}

int pop(int* stack) {

	top--;
	return stack[top + 1];
}

int getPostfix(char* exp, int* stack) {

	int num1, num2;
	char temp;

	for (int i = 0; i < strlen(exp); i++) {
		if (countPriority(exp[i]) == 0) {		//피연산자
			push(stack, exp[i] - '0');
		}
		else {			//연산자 처리
			num2 = pop(stack);
			num1 = pop(stack);
			if (countPriority(exp[i]) == 4) {
				push(stack, num1 * num2);
			}else if (countPriority(exp[i]) == 3) {
				push(stack, num1 / num2);
			}else if (countPriority(exp[i]) == 2) {
				push(stack, num1 - num2);
			}else if (countPriority(exp[i]) == 1) {
				push(stack, num1 + num2);
			}
		}
	}

	return pop(stack);
}

int countPriority(char ch) {

	if (ch == '*') {
		return 4;
	}
	else if (ch == '/') {
		return 3;
	}
	else if (ch == '-') {
		return 2;
	}
	else if (ch == '+') {
		return 1;
	}
	else
		return 0;
}
