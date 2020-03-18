#include <cstdio>
#include <cstring>
struct treeNode { 
	char comp;
	long layer;
	treeNode *leftTree, *rightTree, *father; 
	treeNode(char c, long l) : comp(c), layer(l), leftTree(nullptr), rightTree(nullptr), father(nullptr) {}
	inline char* preOrderTravel() {	return preOrderTravel(this); }
	inline char* midOrderTravel() { return midOrderTravel(this); }
	inline char* postOrderTravel() { return postOrderTravel(this); }
	inline char* preOrderTravel(treeNode* t) {
		if (t == nullptr) return nullptr;
		char* leftOrder = preOrderTravel(t->leftTree);
		char* rightOrder = preOrderTravel(t->rightTree);
		long leftlen = (leftOrder == nullptr) ? 0 : strlen(leftOrder);
		long rightlen = (rightOrder == nullptr) ? 0 : strlen(rightOrder);
		char* travelOrder = new char[leftlen + rightlen + 1];
		memset(travelOrder, 0, sizeof(travelOrder));
		travelOrder[0] = t->comp;
		if (leftlen) strcat(travelOrder, leftOrder);
		if (rightlen) strcat(travelOrder, rightOrder);
		return travelOrder;
	}
	inline char* midOrderTravel(treeNode* t) {
		if (t == nullptr) return nullptr;
		char* leftOrder = midOrderTravel(t->leftTree);
		char* rightOrder = midOrderTravel(t->rightTree);
		long leftlen = (leftOrder == nullptr) ? 0 : strlen(leftOrder);
		long rightlen = (rightOrder == nullptr) ? 0 : strlen(rightOrder);
		char* travelOrder = new char[leftlen + rightlen + 1];
		memset(travelOrder, 0, sizeof(travelOrder));
		if (leftlen) strcat(travelOrder, leftOrder);
		travelOrder[leftlen] = t->comp;
		if (rightlen) strcat(travelOrder, rightOrder);
		return travelOrder;
	}
	inline char* postOrderTravel(treeNode* t) {
		if (t == nullptr) return nullptr;
		char* leftOrder = postOrderTravel(t->leftTree);
		char* rightOrder = postOrderTravel(t->rightTree);
		long leftlen = (leftOrder == nullptr) ? 0 : strlen(leftOrder);
		long rightlen = (rightOrder == nullptr) ? 0 : strlen(rightOrder);
		char* travelOrder = new char[leftlen + rightlen + 1];
		memset(travelOrder, 0, sizeof(travelOrder));
		if (leftlen) strcat(travelOrder, leftOrder);
		if (rightlen) strcat(travelOrder, rightOrder);
		travelOrder[leftlen + rightlen] = t->comp;
		return travelOrder;
	}
};
treeNode *tree, *curNode, *tempNode;
char str[200];
long len, flag;
int main() {
	while (scanf("%s", str) != EOF) {
		if (!strcmp(str, "0")) break;
		len = strlen(str);
		if (len == 1) 	tree = new treeNode(str[0], 0), curNode = tree;
		else if (str[len - 1] == '*') flag = 1;
		else {
			while (curNode->layer >= len - 1) curNode = curNode->father;
			tempNode = new treeNode(str[len - 1], len - 1);
			if ((curNode->leftTree != nullptr) || (flag)) {
				tempNode->father=curNode, curNode->rightTree = tempNode, curNode = curNode->rightTree;
			}
			else {
				tempNode->father = curNode, curNode->leftTree = tempNode, curNode = curNode->leftTree;
			}
			flag = 0;
		}
	}
	printf("%s\n", tree->preOrderTravel());
	printf("%s\n", tree->postOrderTravel());
	printf("%s\n", tree->midOrderTravel());
}