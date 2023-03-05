#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[7];
	int scores[3];
	float average;
}STUDENT;

int main() {

	int N;
	STUDENT* students;

	scanf("%d", &N);
	
	students = (STUDENT*)malloc(sizeof(STUDENT) * N);

	for (int i = 0; i < N; i++) {
		(students + i)->average = 0;
		scanf("%s", &(students + i)->name);
		for (int j = 0; j < 3; j++) {
			scanf("%d", &(students + i)->scores[j]);
			(students + i)->average += (students + i)->scores[j];
		}
		(students + i)->average /= 3;
	}

	for (int i = 0; i < N; i++) {
		printf("%s %.1f", (students + i)->name, (students + i)->average);
		for (int j = 0; j < 3; j++) {
			if ((students + i)->scores[j] >= 90) {
				printf(" GREAT");
				break;
			}
		}
		for (int j = 0; j < 3; j++) {
			if ((students + i)->scores[j] < 70) {
				printf(" BAD");
				break;
			}
		}
		printf("\n");
	}

	free(students);
}