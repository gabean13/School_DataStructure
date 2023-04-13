#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//단일연결리스트 노드 타입
typedef struct Node {
	int coef;
	int exp;
	struct Node* next;
}Node;

void appendTerm(Node* k, int coef, int exp);
Node* addPoly(Node* x, Node* y);

int main() {
	Node *x, *y, *result;
	Node *temp;
	int xNum, yNum;
	int coef, exp;

	x = (Node*)malloc(sizeof(Node));
	y = (Node*)malloc(sizeof(Node));

	x->next = NULL;
	y->next = NULL;

	scanf("%d", &xNum);

	temp = x;
	for (int i = 0; i < xNum; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(temp, coef, exp);	
		temp = temp->next;
	}

	scanf("%d", &yNum);

	temp = y;
	for (int i = 0; i < yNum; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(temp, coef, exp);
		temp = temp->next;
	}

	result = addPoly(x, y);

	temp = result->next;
	while (temp != NULL) {
		printf(" %d %d", temp->coef, temp->exp);
		temp = temp->next;
	}

	return 0;
}

void appendTerm(Node* k, int coef, int exp) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->coef = coef;
	temp->exp = exp;
	temp->next = NULL;

	k->next = temp;

	return;
}

Node* addPoly(Node* x, Node* y) {
	Node* k, *result;
	Node* i = x->next, * j = y->next;
	int sum;

	result = (Node*)malloc(sizeof(Node));
	result->next = NULL;

	k = result;

	while (i != NULL && j != NULL) {
		if (i->exp > j->exp) {
			appendTerm(k, i->coef, i->exp);
			i = i->next;
			k = k->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(k, j->coef, j->exp);
			j = j->next;
			k = k->next;
		}
		else {
			sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(k, sum, i->exp);		
				k = k->next;
			}
			i = i->next;
			j = j->next;
		}
	}

	while (i != NULL) {
		appendTerm(k, i->coef, i->exp);
		i = i->next;
	}

	while (j != NULL) {
		appendTerm(k, j->coef, j->exp);
		j = j->next;
	}
 
	return result;
}
