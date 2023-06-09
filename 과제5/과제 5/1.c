#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {

	int id;
	char* question;
	struct Node* left;
	struct Node* right;

}Node;

Node* root;
Node* searchNode;

Node* newNode(char *, int);
void preorder(Node* node, int id);
void search(Node* node, int id);
void insertNode(int parentid, char* leftQuestion, char* rightQuestion);
void buildDecisionTree();
Node* runDecisionTree(Node *question);

int main() {
	
	Node* temp,* nextQuestionNode;

	buildDecisionTree();

	temp = runDecisionTree(root);
	while (1) {
		nextQuestionNode = runDecisionTree(temp);
		temp = nextQuestionNode;
		if (temp->id > 100) {
			printf("%s \n", temp->question);
			break;
		}
	}
	
	return 0;
}

Node* newNode(char * question, int id) {

	int length = strlen(question);
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->question = (char*)malloc(sizeof(char) * length);
	newNode->question = question;
	newNode->id = id;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;

}

void preorder(Node* node, int id) {

	if (node != NULL) {
		if (node->id == id) {
			searchNode = node;
		}
		preorder(node->left, id);
		preorder(node->right, id);
	}
}

void search(Node* node, int id) {

	if (node == NULL) {
		return NULL;
	}
	if (node->id == id) {
		preorder(node, id);
	}
	else {

		search(node->left, id);
		search(node->right, id);
	}

}

void insertNode(int parentId, char* leftQuestion, int leftId, char* rightQuestion, int rightId) {

	search(root, parentId);
	Node* parentNode = searchNode;

	//��Ʈ ���
	if (leftQuestion != NULL) {
		parentNode->left = newNode(leftQuestion, leftId);
	}
	if (rightQuestion != NULL) {
		parentNode->right = newNode(rightQuestion, rightId);
	}

	return;

}

void buildDecisionTree() {

	root = newNode("�ؿܿ����� ���Ͻó��� ?", 0);
	insertNode(0, "����ð��� �����ɷ��� ���������?", 1, "�ٴٸ� ���� �Ͻó���?", 2);
	insertNode(1, "�޾����� ���Ͻó���?", 3, "������ ���Ͻó���?", 4);
	insertNode(2, "���� �����Ͻ� �� �ֳ���?", 5, "���̰����� �����Ͻó���?", 6);
	insertNode(3, "������ �ϽǼ� �ճ���?", 7, "�̼���, �ڹ����� �����Ͻó���?", 8);
	insertNode(4, "��Ʈ��", 101, "�ִϸ��̼��� �����Ͻó���?", 9);
	insertNode(5, "���ֵ�", 102, "������ �����Ͻó���?", 10);
	insertNode(6, "����", 103, "����", 104);
	insertNode(7, "�Ͽ���", 105, "����ī��", 106);
	insertNode(8, "����", 107, "�౸�� �����Ͻó���?", 11);
	insertNode(9, "����", 108, "����ī", 109);
	insertNode(10, "���", 110, "����", 111);
	insertNode(11, "����", 112, "������", 113);

}

Node* runDecisionTree(Node *questionNode) {
	
	char answer[5] = { NULL, };
	printf("%s type yes or no \n", questionNode->question);
	
	scanf("%s", answer);
	if (strcmp(answer, "yes") == 0) {
		return questionNode->left;
	}
	else if (strcmp(answer, "no") == 0) {
		return questionNode->right;
	}
	else {
		return runDecisionTree(questionNode);
	}

}