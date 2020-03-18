#include <cstdio>
#include <cstring>
struct treeNode { 
	char comp;
	long layer;
	treeNode *leftTree, *rightTree, *father; 
	treeNode(char c, long l) : comp(c), layer(l), leftTree(nullptr), rightTree(nullptr), father(nullptr) {}
	inline void preOrderTravel() { preOrderTravel(this); printf("\n"); }
	inline void midOrderTravel() { midOrderTravel(this); printf("\n"); }
	inline void postOrderTravel() { postOrderTravel(this); printf("\n"); }
	inline void preOrderTravel(treeNode* t) {
		if (t == nullptr) return;
		else printf("%c", t->comp), preOrderTravel(t->leftTree), preOrderTravel(t->rightTree);	
	}
	inline void midOrderTravel(treeNode* t) {
		if (t == nullptr) return;
		else midOrderTravel(t->leftTree), printf("%c", t->comp), midOrderTravel(t->rightTree);
	}
	inline void postOrderTravel(treeNode* t) {
		if (t == nullptr) return;
		else postOrderTravel(t->leftTree), postOrderTravel(t->rightTree), printf("%c", t->comp);
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
	tree->preOrderTravel(), tree->postOrderTravel(), tree->midOrderTravel();
}