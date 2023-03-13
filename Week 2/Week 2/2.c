//비트행렬에서 최대 1행 찾기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int mostOnesSlow(int arr[][100], int n);		//실행시간이 O(n^2)인 알고리즘
int mostOnesFast(int arr[][100], int n);		//실행시간이 O(n)인 알고리즘

int main() {

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);

	int A[100][100] = { 0, };
	int n;		//n * n 비트 행렬 크기

	//비트 행렬 입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	mostOnesSlow 실행시간 측정
	QueryPerformanceCounter(&start);
	mostOnesSlow(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("mostOnesSlowtime: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	QueryPerformanceCounter(&start);
	mostOnesFast(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("mostOnesSlowtime: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	printf("%d\n", mostOnesFast(A, n));
}

int mostOnesSlow(int arr[][100], int n) {
	int row = 0, jmax = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; arr[i][j] == 1; j++) {
			if (j > jmax) {
				jmax = j;
				row = i;
			}
		}
	}

	return row;
}

int mostOnesFast(int arr[][100], int n) {

	int row = 0, jmax = 0;
	int i = 0, j = 0;

	while (i < n) {
		if (arr[i][j] == 0) {
			if (j > jmax) {
				jmax = j;
				row = i;
			}
			i++;

		}
		else {
			j++;
		}
	}

	return row;
}