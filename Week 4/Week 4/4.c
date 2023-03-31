#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int arr[100][100] = { 0, };
	int N, M;
	int num = 1;
	int LRturn = 0;
	int UDturn = 1;
	int right = 1, down = 0, left = 0, up = 0;
	int i = 0, j = -1;

	scanf("%d %d", &N, &M);

	while (num <= N * M) {
		if (right == 1) {
			j++;
			for (int n = 0; n < M - LRturn; n++) {
				arr[i][j++] = num++;
			}
			down = 1;
			right = 0;
			LRturn++;
			j--;
		}
		else if (down == 1) {
			i++;
			for (int n = 0; n < N - UDturn; n++) {
				arr[i++][j] = num++;
			}
			down = 0;
			left = 1;
			UDturn++;
			i--;
		}
		else if (left == 1) {
			j--;
			for (int n = 0; n < M - LRturn; n++) {
				arr[i][j--] = num++;
			}
			left = 0;
			up = 1;
			LRturn++;
			j++;
		}
		else {
			i--;
			for (int n = 0; n < N - UDturn; n++) {
				arr[i--][j] = num++;
			}
			up = 0;
			right = 1;
			UDturn++;
			i++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

}