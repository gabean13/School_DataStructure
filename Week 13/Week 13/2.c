#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	int id;
	struct Node* left;
	struct Node* right;
}Node;

Node* tree;

Node* newNode(int id, int data);
Node* searchNode(Node* head, int id);
int countTreeData(Node* head);

int main() {

	int id;

	Node* head = tree;
	Node* temp;

	head = newNode(1, 20);
	head->left = newNode(2, 30);
	head->right = newNode(3, 50);
	head->left->left = newNode(4, 70);
	head->left->right = newNode(5, 90);
	head->right->right = newNode(6, 120);
	head->right->right->left = newNode(7, 130);
	head->right->right->right = newNode(8, 80);

	scanf("%d", &id);

	if (searchNode(head, id) == -1) {
		printf("-1 \n");
		return 0;
	}

	printf("%d \n", countTreeData(searchNode(head, id)));

	return 0;

}

Node* newNode(int id, int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->id = id;
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

Node* searchNode(Node* head, int id) {

	switch (id) {
	case 1:
		return head;
	case 2:
		return head->left;
	case 3:
		return head->right;
	case 4:
		return head->left->left;
	case 5:
		return head->left->right;
	case 6:
		return head->right->right;
	case 7:
		return head->right->right->left;
	case 8:
		return head->right->right->right;
	default:
		return -1;
	}

}

int countTreeData(Node* head) {

	int left, right;
	if (head == NULL) {
		return 0;
	}
	left = countTreeData(head->left);
	right = countTreeData(head->right);
	return left + right + head->data;

}
