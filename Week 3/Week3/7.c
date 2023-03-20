#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countFindChar(char* str, char findChar, int n);

int main() {
	char string[100] = { 0 , };
	char findChar;
	int stringLength;

	scanf("%s", &string);
	getchar();
	scanf("%c", &findChar);
	
	stringLength = strlen(string);
	
	printf("%d \n", countFindChar(string, findChar, stringLength));
}

int countFindChar(char* str, char findChar, int n) {

	if (n == 1) {
		if (str[n - 1] == findChar) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (str[n - 1] == findChar) {
			return countFindChar(str, findChar, n - 1) + 1;
		}
		else {
			return countFindChar(str, findChar, n - 1);
		}
	}

}