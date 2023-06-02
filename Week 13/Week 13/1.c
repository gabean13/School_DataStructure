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
Node* searchNode(Node *head, int id);
void inorder(Node* head);
void preorder(Node* head);
void postorder(Node* head);

int main() {

	int orderNum;
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

	scanf("%d %d", &orderNum, &id);

	if (searchNode(head, id) == -1) {
		printf("-1 \n");
		return 0;
	}

	switch (orderNum) {
	case 1:
		preorder(searchNode(head, id));
		break;
	case 2:
		inorder(searchNode(head, id));
		break;
	case 3:
		postorder(searchNode(head, id));
		break;
	}

	return 0;

}

Node* newNode(int id, int data) {

	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->id = id;
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

Node* searchNode(Node * head, int id) {
	
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

void inorder(Node* head) {

	if (head != NULL) {
		inorder(head->left);
		printf(" %d", head->data);
		inorder(head->right);
	}

}
void preorder(Node* head) {
	
	if (head != NULL) {
		printf(" %d", head->data);
		preorder(head->left);
		preorder(head->right);
	}
}

void postorder(Node* head) {

	if (head != NULL) {
		postorder(head->left);
		postorder(head->right);
		printf(" %d", head->data);
	}
}
