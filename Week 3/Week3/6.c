#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int findGcd(int num1, int num2);

int main() {
	int num1, num2;

	scanf("%d %d", &num1, &num2);

	printf("%d \n", findGcd(num1, num2));
}

int findGcd(int num1, int num2) {
	
	if (num1 == 0 || num2 == 0) {
		if (num1 == 0) {
			return num2;
		}
		else {
			return num1;
		}
	}

	if (num1 > num2) {
		findGcd(num2, num1 % num2);
	}
	else {
		findGcd(num1, num2 % num1);
	}
}
