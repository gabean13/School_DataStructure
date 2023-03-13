//누적 평균
//3-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

float* prefixAverage1(int arr[], int n);			//실행시간 O(n^2)인 알고리즘
float* prefixAverage2(int arr[], int n);			//실행시간 O(n)인 알고리즘

int main() {

	srand(time(NULL));		
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);

	int n;
	int* arr;
	float* average1, * average2;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	average1 = (float*)malloc(sizeof(float) * n);
	average2 = (float*)malloc(sizeof(float) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10000 + 1;		//1~10000사이의 정수를 arr[i]할당
	}

	//prefixAverage1 실행시간
	QueryPerformanceCounter(&start);
	average1 = prefixAverage1(arr, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("prefixAverage1Time: %.8f ms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000 );
	
	//prefixAverage2 실행시간
	QueryPerformanceCounter(&start);
	average2 = prefixAverage2(arr, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("prefixAverage2Time: %.8f ms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	free(arr);
	free(average1);
	free(average2);

	return 0;
}

float* prefixAverage1(int arr[], int n) {

	int sum;
	float* A;

	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < i + 1; j++) {
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