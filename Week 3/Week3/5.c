#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n);
void rHanoi(int n, char from, char aux, char to);

int main() {
	int N;
	scanf("%d", &N);
	hanoi(N);
}

void hanoi(int n) {
	rHanoi(n, 'A', 'B', 'C');
}
void rHanoi(int n, char from, char aux, char to) {

	if (n == 1) {
		printf("%c %c \n", from, to);
		return 0;
	}
	rHanoi(n - 1, from, to, aux);
	printf("%c %c \n", from, to);
	rHanoi(n - 1, aux, from, to);
	return;
}