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

//1���� N������ �� ��ȯ�ϴ� ��� �Լ�
int Sum(int N) {

	if (N == 1) {		//���̽� ���̽�
		return 1;
	}
	else {
		return N + Sum(N - 1);
	}
}