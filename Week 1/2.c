#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ABC(int arr[], int k) {

	int max = arr[k];

	for (int i = k; i < 10; i++) {
		if (max < arr[i]) {
			max = arr[i];
			arr[i] = arr[k];
			arr[k] = max;
		}
	}
}

int main() {

	int arr[10] = { 0 ,};

	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
		
	for (int i = 0; i < 9; i++) {
		ABC(arr, i);
	}

	for (int i = 0; i < 10; i++) {
		printf(" %d", arr[i]);
	}

}