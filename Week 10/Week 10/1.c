#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int top = -1;

void push(char*, char);
char pop(char*);
void getPostfix(char*, char*);
int isNotOperend(char);
int countPriority(char);

int main() {

	int num;
	char exp[100] = { NULL };
	char* stack;

	stack = (char*)calloc(100, sizeof(char));

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		getchar();
		scanf("%s", &exp);
		getPostfix(exp, stack);
	}

	free(stack);

	return 0;
}

void push(char* stack, char element) {

	top++;
	stack[top] = element;
	return;
}

char pop(char* stack) {

	top--;
	return stack[top + 1];
}


void getPostfix(char* exp, char* stack) {

	char temp;

	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '+' || exp[i] == '-') {
			if (i == 0 || (exp[i - 1] != ')' && countPriority(exp[i - 1]))) {
				if (exp[i] == '+') {
					exp[i] = 'P';
				}
				else {
					exp[i] = 'M';
				}
			}
		}
		if (exp[i] == '(') {			//괄호 처리
			push(stack, exp[i]);
		}
		else if (exp[i] == ')') {
			while (stack[top] != '(') {
				temp = pop(stack);
				if (temp == 'P') {
					temp = '+';
				}
				else if (temp == 'M') {
					temp = '-';
				}
				printf("%c", temp);
			}
			pop(stack);		//(제거
		}
		else if (countPriority(exp[i]) == 0) {		//피연산자
			printf("%c", exp[i]);
		}
		else {			//연산자 처리
			while (top != -1 && (countPriority(exp[i]) <= countPriority(stack[top]))) {{
				temp = pop(stack);
				if (temp == '&' || temp == '|') {
					printf("%c", temp);
					temp = pop(stack);
				}
				else if (temp == 'P') {
					temp = '+';
				}
				else if (temp == 'M') {
					temp = '-';
				}
				printf("%c", temp);
			}
		}
		push(stack, exp[i]);
			if (countPriority(exp[i]) == 2 || countPriority(exp[i]) == 1) {
				push(stack, exp[++i]);
			}
		}
	}

	while (top != -1) {
		temp = pop(stack);
		if (temp == '&' || temp == '|') {
			printf("%c", temp);
			temp = pop(stack);

		}
		else if (temp == 'P') {
			temp = '+';
		}
		else if (temp == 'M') {
			temp = '-';
		}
		printf("%c", temp);
	}

	printf("\n");

	return 0;
}
int countPriority(char ch) {

	if (ch == 'P' || ch == 'M' || ch == '!') {
		return 6;
	}
	else if (ch == '*' || ch == '/') {
		return 5;
	}
	else if (ch == '+' || ch == '-') {
		return 4;
	}
	else if (ch == '>' || ch == '<') {
		return 3;
	}
	else if (ch == '&') {
		return 2;
	}
	else if (ch == '|') {
		return 1;
	}
	else
		return 0;
}
