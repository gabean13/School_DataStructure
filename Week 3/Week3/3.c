#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printDigits(int Num);

int main() {

	int Num;

	scanf("%d", &Num);

	printDigits(Num);

	return 0;
}

void printDigits(int Num) {

	int digit;

	if (Num / 10 <= 0) {
		printf("%d \n", Num);
		return 0;			//���̽� ���̽�
	}
	else {
		printf("%d \n", Num % 10);
		printDigits(Num / 10);
	}
}

