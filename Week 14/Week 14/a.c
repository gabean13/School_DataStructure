#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {

	int data;
	struct Node* left;
	struct Node* right;

}Node;

Node* root;
Node* searchNode;

Node* newNode(int data);
void preorder(Node* node, int data);
void search(Node *node, int data);
void insertNode(int parentData, int leftData, int rightData);
void printNode(Node* node, char printOrder[100], int i);

int main() {

	int nodeNum, printNum;
	int parentData, leftData, rightData;
	char printOrder[100] = { NULL, };

	scanf("%d", &nodeNum);

	for (int i = 0; i < nodeNum; i++) {
		scanf("%d %d %d", &parentData, &leftData, &rightData);
		insertNode(parentData, leftData, rightData);
	}

	scanf("%d", &printNum);

	for (int i = 0; i < printNum; i++) {
		scanf("%s", printOrder);
		printNode(root, printOrder, 0);
		printf("\n");
	}

	return 0;
	
}

Node* newNode(int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void preorder(Node* node, int data) {

	if (node != NULL) {
		if (node->data = data) {
			searchNode = node;
		}
		preorder(node->left, data);
		preorder(node->right, data);
	}
}

void search(Node* node, int data) {

	if (node == NULL) {
		return NULL;
	}
	if (node->data == data) {
		preorder(node, data);
	}
	else {
		
		search(node->left, data);
		search(node->right, data);
	}
	
}

void insertNode(int parentData, int leftData, int rightData) {

	search(root, parentData);
	Node* parentNode = searchNode;

	//루트 노드
	if (parentNode == NULL) {
		parentNode = newNode(parentData);		
		root = parentNode;
	}

	if (leftData != 0) {
		parentNode->left = newNode(leftData);
	}
	if (rightData != 0) {
		parentNode->right = newNode(rightData);
	}

	return;
}

void printNode(Node* node, char printOrder[100], int i) {

	printf(" %d", node->data);
	while (printOrder[i] != NULL) {		
		if (printOrder[i] == 'R') {
			return printNode(node->right, printOrder, ++i);
		}
		else {
			return printNode(node->left, printOrder, ++i);
		}
	}

	return;

}