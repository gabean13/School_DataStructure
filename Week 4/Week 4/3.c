#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main () {

	int arr[100][100] = { 0, };
	int N;
	int left = 1;
	int num = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		if (left == 1) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = num++;
			}
			left = 0;
		}
		else {
			for (int j = N-1; j >= 0; j--) {
				arr[i][j] = num++;
			}
			left = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;

}