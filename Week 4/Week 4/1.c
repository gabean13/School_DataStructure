#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//수열 x의 원하는 범위를 뒤집는 함수
void reverseX(int*, int, int);

int main() {
	
	int N = 0, reverseNum = 0;
	int x[100] = { 0 , };
	int reverseStart, reverseEnd;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}

	scanf("%d", &reverseNum);
	for (int i = 0; i < reverseNum; i++) {
		scanf("%d %d", &reverseStart, &reverseEnd);
		reverseX(x, reverseStart, reverseEnd);
	}

	for (int i = 0; i < N; i++) {
		printf(" %d", x[i]);
	}

	return 0;
}

void reverseX(int* x, int start, int end) {

	int temp;
	float num = (float)(end + start) / 2;

	for (int i = 0; i + start < num; i++) {
		temp = x[start + i];
		x[start + i] = x[end - i];
		x[end - i] = temp;
	}

	return 0;
}
