#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* insertNode(Node*, Node*, int);
void printChildNode(Node*);

int main() {

	int nodeNum = 0;
	Node* F1, * F2, * F3, * F4, * F5, * F6, * F7, * F8;

	//트리 생성
	F8 = insertNode(NULL, NULL, 80);
	F7 = insertNode(NULL, NULL, 130);
	F6 = insertNode(F7, F8, 120);
	F5 = insertNode(NULL, NULL, 90);
	F4 = insertNode(NULL, NULL, 70);
	F3 = insertNode(NULL, F6, 50);
	F2 = insertNode(F4, F5, 30);
	F1 = insertNode(F2, F3, 20);

	scanf("%d", &nodeNum);

	switch (nodeNum)
	{
	case 1:
		printChildNode(F1);
		break;
	case 2:
		printChildNode(F2);
		break;
	case 3:
		printChildNode(F3);
		break;
	case 4:
		printChildNode(F4);
		break;
	case 5:
		printChildNode(F5);
		break;
	case 6:
		printChildNode(F6);
		break;
	case 7:
		printChildNode(F7);
		break;
	case 8:
		printChildNode(F8);
		break;
	default:
		printf("-1 \n");
		break;
	}
	

	return 0;
}

Node* insertNode(Node* leftNode, Node* rightNode, int data) {
	
	Node* parentNode = (Node*)malloc(sizeof(Node));

	parentNode->data = data;
	parentNode->right = rightNode;
	parentNode->left = leftNode;

	return parentNode;
}

void printChildNode(Node* parentNode) {

	//자식이 둘다 없는 경우
	if (parentNode->left == NULL && parentNode->right == NULL) {
		printf("%d \n", parentNode->data);
		return;
	}

	//둘 중 하나만 자식이 있는 경우
	if (parentNode->left == NULL) {
		printf("%d %d \n", parentNode->data, parentNode->right->data);
		return;
	}
	else if (parentNode->right == NULL) {
		printf("%d %d \n", parentNode->data, parentNode->left->data);
		return;
	}
	

	//둘 다 자식이 있는 경우
	printf("%d %d %d \n", parentNode->data, parentNode->left->data, parentNode->right->data);
	return;

}