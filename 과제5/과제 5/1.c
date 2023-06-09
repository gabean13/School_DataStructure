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

	//루트 노드
	if (leftQuestion != NULL) {
		parentNode->left = newNode(leftQuestion, leftId);
	}
	if (rightQuestion != NULL) {
		parentNode->right = newNode(rightQuestion, rightId);
	}

	return;

}

void buildDecisionTree() {

	root = newNode("해외여행을 원하시나요 ?", 0);
	insertNode(0, "비행시간이 오래걸려도 상관없나요?", 1, "바다를 좋아 하시나요?", 2);
	insertNode(1, "휴양지를 원하시나요?", 3, "가성비를 원하시나요?", 4);
	insertNode(2, "차를 운전하실 수 있나요?", 5, "놀이공원을 좋아하시나요?", 6);
	insertNode(3, "운전을 하실수 잇나요?", 7, "미술관, 박물관을 좋아하시나요?", 8);
	insertNode(4, "베트남", 101, "애니메이션을 좋아하시나요?", 9);
	insertNode(5, "제주도", 102, "서핑을 좋아하시나요?", 10);
	insertNode(6, "경주", 103, "군산", 104);
	insertNode(7, "하와이", 105, "보라카이", 106);
	insertNode(8, "뉴욕", 107, "축구를 좋아하시나요?", 11);
	insertNode(9, "도쿄", 108, "오사카", 109);
	insertNode(10, "양양", 110, "강릉", 111);
	insertNode(11, "영국", 112, "스위스", 113);

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