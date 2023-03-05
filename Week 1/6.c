#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct studentInfo {
	char name[9];
	int score;
}STUDENT;

int main() {
	STUDENT students[5];
	int average = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%s %d", &students[i].name, &students[i].score);
		average += students[i].score;
		getchar();
	}

	average /= 5;

	for (int i = 0; i < 5; i++) {
		if (average >= students[i].score) {
			printf("%s \n", students[i].name);
		}
	}
}