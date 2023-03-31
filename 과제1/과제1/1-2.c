/*과제 1-2
비트행렬에서 1의 수 세기 + 실행시간 측정*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

int countOnesButSlow(int ***A, int n);
int countOnes(int ***A, int n);

int main() {

	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);

	int** A1 = { 0, };
	int** A2 = { 0, };
	int** A3 = { 0, };
	int n, k;
	int kTotal1 = 0, kTotal2 = 0, kTotal3 = 0;
	int fast_one1, fast_one2, fast_one3;
	int slow_one1, slow_one2, slow_one3;
	float fastTime_1, fastTime_2, fastTime_3;
	float slowTime_1, slowTime_2, slowTime_3;

	//1. n = 1000;
	n = 1000;
	k = n;

	//A 동적할당
	A1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		A1[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		k = rand(0) % (int)(0.1 * k + 1) + 0.9 * k;
		kTotal1 += k;
		for (int j = 0; j < k; j++) {
			A1[i][j] = 1;
		}
	}

	//n=1000 countOnes 실행시간 측정
	QueryPerformanceCounter(&start);
	fast_one1 = countOnes(&A1, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	fastTime_1 = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);

	QueryPerformanceCounter(&start);
	slow_one1 = countOnesButSlow(&A1, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	slowTime_1 = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);

	//A 동적할당 해제
	for (int i = 0; i < n; i++) {
		free(A1[i]);
	}

	free(A1);

	//2. n = 2000;
	n = 2000;
	k = n;

	//A 동적할당
	A2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		A2[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		k = rand(0) % (int)(0.1 * k + 1) + 0.9 * k;
		kTotal2 += k;
		for (int j = 0; j < k; j++) {
			A2[i][j] = 1;
		}
	}

	//n=2000 countOnes 실행시간 측정
	QueryPerformanceCounter(&start);
	fast_one2 = countOnes(&A2, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	fastTime_2 = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000;

	QueryPerformanceCounter(&start);
	slow_one2 = countOnesButSlow(&A2, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	slowTime_2 = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000;

	//A 동적할당 해제
	for (int i = 0; i < n; i++) {
		free(A2[i]);
	}

	free(A2);

	//3. n = 3000;
	n = 3000;
	k = n;

	//A 동적할당
	A3 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		A3[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		k = rand(0) % (int)(0.1 * k + 1) + 0.9 * k;
		kTotal3 += k;
		for (int j = 0; j < k; j++) {
			A3[i][j] = 1;
		}
	}

	//n=3000 countOnes 실행시간 측정
	QueryPerformanceCounter(&start);
	fast_one3 = countOnes(&A3, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	fastTime_3 = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000;

	QueryPerformanceCounter(&start);
	slow_one3 = countOnesButSlow(&A3, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	slowTime_3 = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000;
	
	//A 동적할당 해제
	for (int i = 0; i < n; i++) {
		free(A3[i]);
	}

	free(A3);

	printf("%d, %d, %.12f ms \n", kTotal3, fast_one3, fastTime_3);
	printf("%d, %d, %.12f ms \n", kTotal1, fast_one1, fastTime_1);
	printf("%d, %d, %.12f ms \n", kTotal2, fast_one2, fastTime_2);

	printf("%d, %d, %.12f ms \n", kTotal3, slow_one3, slowTime_3);
	printf("%d, %d, %.12f ms \n", kTotal1, slow_one1, slowTime_1);
	printf("%d, %d, %.12f ms \n", kTotal2, slow_one2, slowTime_2);

	return 0;
}

int countOnesButSlow(int*** A, int n) {

	int count = 0;

	for (int i = 0; i < n; i++) {
		int j = 0;
		while ((j < n) && (*A)[i][j] == 1) {
			count++;
			j++;
		}
	}

	return count;
}
int countOnes(int*** A, int n) {
	int count = 0;
	int j = 0;

	for (int i = n - 1; i >= 0; i--) {
		count += j;
		while ((*A)[i][j] == 1) {
			count++;
			j++;
		}
	}
	return count;
}