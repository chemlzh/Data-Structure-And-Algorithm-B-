#include <cstdio>
using namespace std;
struct treeNode {
	long element;
	treeNode* leftTree, * rightTree;
	treeNode(long n) : element(n), leftTree(nullptr), rightTree(nullptr) {}
};
struct BSTree {
	treeNode* root;
	BSTree() :root(nullptr) {}
	inline void insert(long n) {
		if (root == nullptr) {
			treeNode* newNode = new treeNode(n);
			root = newNode;
		}
		else {
			treeNode* tempNode = root, * fatherNode = nullptr;
			while (tempNode != nullptr) {
				fatherNode = tempNode;
				if (tempNode->element == n) break;
				else if (tempNode->element < n) tempNode = tempNode->rightTree;
				else tempNode = tempNode->leftTree;
			}
			if (tempNode != nullptr) return;
			else {
				treeNode* newNode = new treeNode(n);
				if (fatherNode->element < n) fatherNode->rightTree = newNode;
				else fatherNode->leftTree = newNode;
			}
		}
	}
	inline void printPreOrder() {	printPreOrder(root); }
	inline void printPreOrder(treeNode* t) {
		if (t == nullptr) return;
		printf("%ld ", t->element), printPreOrder(t->leftTree), printPreOrder(t->rightTree);
	}
}*tree;
long num, empty = 0;
int main() {
	tree = new BSTree();
	while (scanf("%ld", &num) != EOF) tree->insert(num);
	tree->printPreOrder();
}