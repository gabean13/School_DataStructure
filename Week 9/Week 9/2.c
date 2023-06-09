#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int top = -1;

void push(char*, char);
char pop(char*);
void fullStackException();
void emptyStackException();

int main() {
	char string[1000] = { 0 , }, temp;
	char* stack;
	int stringNum, stackNum = 0;
	int result = 0;

	gets(&string);

	stringNum = strlen(string);
	stack = (char*)calloc(stringNum, sizeof(char));

	for (int i = 0; i < stringNum; i++) {
		if (string[i] == '{' || string[i] == '[' || string[i] == '(') {
			stackNum++;
			push(stack, string[i]);
		}
		else if (string[i] == '}' || string[i] == ']' || string[i] == ')') {
			stackNum++;
			temp = pop(stack);
			if (string[i] == '}') {
				if (temp != '{') {
					result = 1;
				}
			}
			else if (string[i] == ']') {
				if (temp != '[') {
					result = 1;
				}
			}
			else {
				if (temp != '(') {
					result = 1;
				}
			}
		}
	}

	if (top > -1 || top < -1) {
		result = 1;
	}

	if (result == 1) {
		printf("Wrong_%d \n", stackNum);
	}
	else {
		printf("OK_%d \n", stackNum);
	}

	free(stack);
	return;
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

