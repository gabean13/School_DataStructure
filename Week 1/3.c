#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	printf("%d", temp);
}
int main() {
	
	int arr[50] = { 0 , };
	int N, a, b;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d %d", &a, &b);

	swap(&arr[a], &arr[b]);

	for (int i = 0; i < N; i++) {
		printf(" %d", arr[i]);
	}

}