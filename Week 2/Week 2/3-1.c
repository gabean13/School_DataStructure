//누적 평균
//3-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

float* prefixAverage1(int arr[], int n);			//실행시간 O(n^2)인 알고리즘
float* prefixAverage2(int arr[], int n);			//실행시간 O(n)인 알고리즘

int main() {

	int n;
	int* arr;
	float *average1, * average2;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	average1 = (float*)malloc(sizeof(float) * n);
	average2 = (float*)malloc(sizeof(float) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	average1 = prefixAverage1(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", (int)(average1[i] + 0.5));
	}
	printf("\n");

	average2 = prefixAverage2(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", (int)(average2[i] + 0.5));
	}
	printf("\n");

	free(arr);
	free(average1);
	free(average2);

	return 0;
}

float* prefixAverage1(int arr[], int n){
	
	int sum;
	float *A;

	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < i+1; j++){
			sum += arr[j];
		}
		A[i] = (float)sum / (float)(i + 1);
	}

	return A;
}

float* prefixAverage2(int arr[], int n) {
	int sum = 0, j = 0;
	float* A;

	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		sum += arr[j++];
		A[i] = (float)sum / (float)(i + 1);
	}

	return A;
}