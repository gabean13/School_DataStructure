#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int element;
	struct Node* next;
}Node;

void addNode(Node* node, int element);
int subset(Node* A, Node* B);

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
		if (i == 0) {
			A->element = element;
			continue;
		}
		addNode(temp, element);
		temp = temp->next;
	}

	scanf("%d", &num);
	temp = B;
	for (int i = 0; i < num; i++) {
		scanf("%d", &element);
		if (i == 0) {
			B->element = element;
			continue;
		}
		addNode(temp, element);
		temp = temp->next;
	}

	printf("%d \n", subset(A, B));
}

void addNode(Node* node, int element) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->element = element;
	newNode->next = node->next;
	node->next = newNode;
}

int subset(Node* A, Node* B) {

	Node* tempA = A;
	Node* tempB= B;

	if (A->element == NULL) {
		return 0;
	}

	while (tempA->element != NULL) {
		if (tempA->element != tempB->element) {
			if (tempA->element < tempB->element) {
				return tempA->element;
			}
			else {
				if (tempB->next == NULL) {
					return tempA->element;
				}
				tempB = tempB->next;
			}
		}
		else {
			if (tempA->next == NULL) {
				return 0;
			}
			tempA = tempA->next;
			tempB = tempB->next;
		}
	}

}