#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	 
	int N;
	int* arr1;
	int* arr2;
	int* result;

	scanf("%d", &N);

	arr1 = (int*)malloc(sizeof(int) * N);
	arr2 = (int*)malloc(sizeof(int) * N);
	result = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr1[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr2[i]);
	}

	for (int i = 0; i < N; i++) {
		result[i] = arr1[i] + arr2[N - 1 - i];
		printf(" %d", result[i]);
	}

	free(arr1);
	free(arr2);
}