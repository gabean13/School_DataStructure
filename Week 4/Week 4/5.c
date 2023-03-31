#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
    int arr[100][100] = { 0 };
    int N, M;
    int num = 1;
    int x = 0;

    scanf("%d %d", &N, &M);

    while (1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i + j == x) {
                    arr[i][j] = num++;
                }
            }
        }
        x++;
        if (num - 1 == N * M) {
            break;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}