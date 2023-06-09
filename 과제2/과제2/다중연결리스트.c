#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NG 5
#define NE 4

typedef struct List {
	struct List* nextGroup;
	struct List* nextElement;
}List;

typedef struct Group {
	char user;
	List* header;
}Group;

typedef struct Element {
	int coupon;
	List* header;
}Element;

List* getNode() {
	List* newList = (List*)malloc(sizeof(List));
	newList->nextElement = NULL;
	newList->nextGroup = NULL;
	return newList;
}

void init(Group** groups, Element** elements);
void addShrare(Group* groups, Element* elements, char user, int coupon);
void removeShare(Group* groups, Element* elements, char user, int coupon);
void removeList(List* p);
void traverseShareElements(Group* groups, Element* elements, char user);
void traverseShareGroups(Group* groups, Element* elements, int coupon);
int getElement(Element* elements, List* p);
char getGroup(Group* groups, List* p);

int main() {

	char cmd, group;
	int element;

	Group* groups;
	Element* elements;

	init(&groups, &elements);

	while (1) {
		scanf("%c", &cmd);		//명령어 입력
		getchar();
		switch (cmd)
		{
		case 'a' :
			scanf("%d %c", &element, &group);
			getchar();
			addShrare(groups, elements, group, element);
			continue;
		case 'r':
			scanf("%d %c", &element, &group);
			getchar();
			removeShare(groups, elements, group, element);
			continue;
		case 'e':
			scanf("%c", &group);
			getchar();
			traverseShareElements(groups, elements, group);
			continue;
		case 'g':
			scanf("%d", &element);
			getchar();
			traverseShareGroups(groups, elements, element);
			continue;
		case 'q':
			break;
		}
		if (cmd == 'q') {
			break;
		}
	}
}

//groups , elements 초기화
void init(Group** groups, Element** elements) {

	char users[NG] = { 'A', 'B', 'C', 'D', 'E' };
	int coupons[NE] = { 1,2,3,4 };
	
	(*groups) = (Group*)malloc(sizeof(Group) * NG);
	(*elements) = (Element*)malloc(sizeof(Element) * NE);

	for (int i = 0; i < NG; i++) {
		List* newList = getNode();
		newList->nextElement = newList;
		(*groups)[i].header = newList;
		(*groups)[i].user = users[i];
	}

	for (int i = 0; i < NE; i++) {
		List* newList = getNode();
		newList->nextGroup = newList;
		(*elements)[i].header = newList;
		(*elements)[i].coupon = coupons[i];
	}

}

//쿠폰 추가
void addShrare(Group* groups, Element* elements, char user, int coupon) {

	int userIndex = 0;
	int couponIndex = 0;

	for (int i = 0; i < NG; i++) {
		if (groups[i].user == user) {
			userIndex = i;
			break;
		}
	}

	for (int i = 0; i < NE; i++) {
		if (elements[i].coupon == coupon) {
			couponIndex = i;
			break;
		}
	}

	List* HG = groups[userIndex].header;
	List* HE = elements[couponIndex].header;
	List* newList = getNode();
	newList->nextElement = HG->nextElement;
	HG->nextElement = newList;
	newList->nextGroup = HE->nextGroup;
	HE->nextGroup = newList;
	
	printf("OK \n");

	return;

}

//쿠폰 사용
void removeShare(Group* groups, Element* elements, char user, int coupon) {

	int userIndex = 0;
	int couponIndex = 0;

	for (int i = 0; i < NG; i++) {
		if (groups[i].user == user) {
			userIndex = i;
			break;
		}
	}

	for (int i = 0; i < NE; i++) {
		if (elements[i].coupon == coupon) {
			couponIndex = i;
			break;
		}
	}

	List* HG = groups[userIndex].header;
	List* p = HG->nextElement;

	while (p != HG) {
		if (elements[couponIndex].coupon == getElement(elements, p)) {
			removeList(p);
			break;
		}
		p = p->nextElement;
	}

	printf("OK \n");
	return;
}

void removeList(List* p) {
	List* removeE = p->nextElement;
	List* removeG = p->nextGroup;
	List* temp = removeE;

	while (temp->nextElement != p) {
		temp = temp->nextElement;
	}
	temp->nextElement = removeE;

	temp = removeG;
	while (temp->nextGroup != p) {
		temp = temp->nextGroup;
	}
	temp->nextGroup = removeG;

	free(p);
}
//원하는 사용자가 가진 쿠폰 열람
void traverseShareElements(Group* groups, Element* elements, char user) {

	int userIndex = 0;
	int n = 0;

	for (int i = 0; i < NG; i++) {
		if (groups[i].user == user) {
			userIndex = i;
			break;
		}
	}

	List* H = groups[userIndex].header;
	List* p = H->nextElement;

	while (p != H) {
		printf("%d ", getElement(elements, p));	
		n++;
		p = p->nextElement;
	}

	if (n == 0) {
		printf("0");
	}

	printf("\n");

	return;
}

int getElement(Element* elements, List* p) {
	List* temp = p->nextGroup;

	while (temp->nextElement != NULL) {
		temp = temp->nextGroup;
	}
	for (int i = 0; i < NE; i++) {
		if (elements[i].header == temp) {
			return elements[i].coupon;
		}
	}
}

void traverseShareGroups(Group* groups, Element* elements, int coupon) {
	int couponIndex = 0;
	int n = 0;

	for (int i = 0; i < NE; i++) {
		if (elements[i].coupon == coupon) {
			couponIndex = i;
			break;
		}
	}

	List* H = elements[couponIndex].header;
	List* p = H->nextGroup;

	while (p != H) {
		printf("%c ", getGroup(groups, p));
		n++;
		p = p->nextGroup;
	}

	if (n == 0) {
		printf("0");
	}

	printf("\n");
	return;
}

char getGroup(Group* groups, List* p) {
	List* temp = p->nextElement;

	while (temp->nextGroup != NULL) {
		temp = temp->nextElement;
	}
	for (int i = 0; i < NG; i++) {
		if (groups[i].header == temp) {
			return groups[i].user;
		}
	}
}