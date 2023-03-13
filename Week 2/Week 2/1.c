#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int modulo(int a, int b);	//a를 b로 나눈 나머지 반환

int main() {

	int a = 0, b = 0;

	scanf("%d %d", &a, &b);
	
	printf("%d \n", modulo(a, b));
	return 0;

}

int modulo(int a, int b) {

	while (a >= b) {
		a -= b;
	}

	return a;
}
