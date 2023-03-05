#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void shift(char* arr, int length) {
	char temp;

	for (int i = 0; i < length; i++) {
		if (i == 0) {
			temp = arr[i];
			continue;
		}
		arr[i - 1] = arr[i];
	}
	arr[length - 1] = temp;
}

int main() {
	char arr[100] = { NULL, };
	int i = 0;
	int length = 0;

	scanf("%s", &arr);

	for (i = 0; arr[i] != NULL; i++) {
		length++;
	}

	for (i = 0; i < length; i++) {
		printf("%s \n", arr);
		shift(&arr, length);
	}
}