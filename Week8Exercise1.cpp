#include <cstdio>
#include <cstring>
using namespace std;
char preOrder[50], midOrder[50];
inline void printPostOrder(long posPre,long posMid,long n) {
	if (n == 1) { printf("%c", preOrder[posPre]); return; }
	if (n == 0) return;
	long i = 0;
	for (; (i < n) && (preOrder[posPre] != midOrder[posMid + i]); i++);
	printPostOrder(posPre + 1, posMid, i);
	printPostOrder(posPre + i + 1, posMid + i + 1, n - i - 1);
	printf("%c", preOrder[posPre]);
}
int main() {
	while (scanf("%s%s", preOrder, midOrder) != EOF) {
		printPostOrder(0, 0, strlen(preOrder)), printf("\n");
	}
}