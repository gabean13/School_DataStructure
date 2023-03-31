/*과제 1-1
비트행렬에서 1의 수 세기*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int countOnesButSlow(int A[][100], int n);
int countOnes(int A[][100], int n);

int main() {
	int A[100][100] = { 0, };
	int n;

	scanf("%d", &n);

	getchar();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("%d \n%d \n", countOnesButSlow(A, n), countOnes(A, n));

	return 0;
}

int countOnesButSlow(int A[][100], int n) {

	int count = 0;

	for (int i = 0; i < n; i++) {
		int j = 0;
		while ((j < n) && A[i][j] == 1) {
			count++;
			j++;
		}
	}

	return count;
}
int countOnes(int A[][100], int n) {
	int count = 0;
	int j = 0;

	for (int i = n; i >= 0; i--) {
		count += j;
		while (A[i][j] != 0) {
			count++;
			j++;
		}
	}
	return count;
}