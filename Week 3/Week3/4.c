#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int findMax(int n, int* arr);

int main() {
	int n;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d \n", findMax(n, arr));

	return 0;
}

int findMax(int n, int* arr) {

	if (n == 1) {
		return arr[0];
	}
	int max = findMax(n - 1, arr);
	if (max > arr[n - 1]) {
		return max;
	}
	else {
		return arr[n - 1];
	}
}