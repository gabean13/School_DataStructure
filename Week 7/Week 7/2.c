#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int element;
	struct Node* next;
}Node;

void addNode(Node* node, int element);
Node* Union(Node* A, Node* B);
Node* intersect (Node* A, Node* B);

int main() {
	Node* A = (Node*)malloc(sizeof(Node));
	Node* B = (Node*)malloc(sizeof(Node));
	Node* temp;

	A->element = NULL;
	B->element = NULL;
	A->next = NULL;
	B->next = NULL;

	int num;
	int element;

	scanf("%d", &num);
	temp = A;
	for (int i = 0; i < num; i++) {
		scanf("%d", &element);
		addNode(temp, element);
		temp = temp->next;
	}

	scanf("%d", &num);
	temp = B;
	for (int i = 0; i < num; i++) {
		scanf("%d", &element);
		addNode(temp, element);
		temp = temp->next;
	}

	temp = Union(A, B);
	temp = temp->next;
	if (temp == NULL) {
		printf("0");
	}
	else {
		while (temp != NULL) {
			printf(" %d", temp->element);
			temp = temp->next;
		}
	}
	printf("\n");

	temp = intersect(A, B);
	temp = temp->next;
	if (temp == NULL) {
		printf("0");
	}
	else {
		while (temp != NULL) {
			printf(" %d", temp->element);
			temp = temp->next;
		}
	}
	printf("\n");
}

void addNode(Node* node, int element) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->element = element;
	newNode->next = node->next;
	node->next = newNode;
}

Node* Union(Node* A, Node* B) {

	if (A == NULL && B == NULL) {
		return NULL;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	p->element = NULL;
	p->next = NULL;

	if (A == NULL) {
		p->element = B->element;
		p->next = Union(A, B->next);
	}
	else if (B == NULL) {
		p->element = A->element;
		p->next = Union(A->next, B);
	}
	else {
		if (A->element < B->element) {
			p->element = A->element;
			p->next = Union(A->next, B);
		}
		else if (A->element > B->element) {
			p->element = B->element;
			p->next = Union(A, B->next);
		}
		else {
			p->element = A->element;
			p->next = Union(A->next, B->next);
		}
	}

	return p;
}
Node* intersect(Node* A, Node* B) {

	if (A == NULL || B == NULL) {
		return NULL;
	}

	Node* p;

	if (A->element < B->element) {
		return intersect(A->next, B);
	}else if(A->element > B->element) {
		return intersect(A, B->next);
	}
	else {
		p = (Node*)malloc(sizeof(Node));
		p->element = A->element;
		p->next = intersect(A->next, B->next);
		return p;
	}
}