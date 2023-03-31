#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int X[100] = { 0, };
	int N;
	int num, temp1, temp2;
	int count = 0;
	int change[100] = { 0, };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &change[i]);
	}
	
	temp1 = X[change[1]];
	X[change[1]] = X[change[0]];

	for (int i = 1; i < num - 1; i++) {
		if (count == 0) {
			temp2 = X[change[i + 1]];
			X[change[i + 1]] = temp1;
			count++;
			continue;
		}
		if (count == 1) {
			temp1 = X[change[i + 1]];
			X[change[i + 1]] = temp2;
			count--;
			continue;

		}
	}

	for (int i = 0; i < N; i++) {
		printf(" %d", X[i]);
	}
}