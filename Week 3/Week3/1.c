#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Sum(int N);

int main() {

	int N, total;

	scanf("%d", &N);
	
	total = Sum(N);
	
	printf("%d \n", total);

	return 0;

}

//1부터 N까지의 합 반환하는 재귀 함수
int Sum(int N) {

	if (N == 1) {		//베이스 케이스
		return 1;
	}
	else {
		return N + Sum(N - 1);
	}
}