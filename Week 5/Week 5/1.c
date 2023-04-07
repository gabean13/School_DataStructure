#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//이중연결리스트 노드 타입
typedef struct Node {
	char element;
	struct Node* prev;
	struct Node* next;
}Node;
int n;		//원소의 개수

void add(Node* node, int rank, char element);
void addNodeBefore(Node* node, int element);
void delete(Node* node, int rank);
void deleteNodeBefore(Node* node);
char get(Node* node, int rank);
void print(Node* node);

int main() {
	int num;	//연산의 개수
	scanf("%d", &num);

	char functionName;
	char element, getChar;
	int rank;

	Node* head = (Node*)malloc(sizeof(Node));
	head->prev = head;
	head->next = head;
	n = 0;

	for (int i = 0; i < num; i++) {
		getchar();
		scanf("%c", &functionName);
		if (functionName == 'A') {
			getchar();
			scanf("%d %c", &rank, &element);
			add(head, rank, element);
		}
		else if (functionName == 'D') {
			getchar();
			scanf("%d", &rank);
			delete(head, rank);
		}
		else if (functionName == 'G') {
			scanf("%d", &rank);
			getChar = get(head, rank);
			if (getChar != 0) {
				printf("%c \n", getChar);
			}
		}
		else {
			print(head);
		}
	}
}

void add(Node* node, int rank, char element) {

	if (rank < 1 || rank > n + 1) {
		printf("invalid position \n");
		return 0;
	}

	Node * temp = node;
	for (int i = 0; i < rank; i++) {
		temp = temp->next;
	}

	addNodeBefore(temp, element);
	n++;

	return;
}

void addNodeBefore(Node* node, int element) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->element = element;
	newNode->prev = node->prev;
	newNode->next = node;
	(node->prev)->next = newNode;
	node->prev = newNode;

	return;
}

void delete(Node* node, int rank) {

	if (rank < 1 || rank > n) {
		printf("invalid position \n");
		return 0;
	}

	Node* temp = node;
	for (int i = 0; i < rank; i++) {
		temp = temp->next;
	}

	deleteNodeBefore(temp);
	n--;

	return;
}

void deleteNodeBefore(Node* node) {

	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);

	return;

}

char get(Node* node, int rank) {

	if (rank < 1 || rank > n) {
		printf("invalid position \n");
		return 0;
	}
	
	Node* temp = node;

	for (int i = 0; i < rank; i++) {
		temp = temp->next;
	}

	return temp->element;

}
void print(Node* node) {

	Node* temp;

	int i = 0;
	temp = node;

	while (i < n) {
		temp = temp->next;
		printf("%c", temp->element);
		i++;
	}

	printf("\n");

	return;
}

