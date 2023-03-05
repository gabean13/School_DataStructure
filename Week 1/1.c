#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1부터 n까지의 합 계산, 반환
int sum(int n) {

	int total = 0;

	for (int i = 1; i <= n; i++)
	{
		total += i;
	}

	return total;
}

int main() {

	int X, total = 0;

	scanf("%d", &X);

	for (int i = 1; i <= X; i++)
	{
		total += sum(i);
	}

	printf("%d", total);
}
