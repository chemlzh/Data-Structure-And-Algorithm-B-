#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
char pre[105], mid[105];
inline void findPost(long preL, long preH, long midL, long midH) {
	if ((preL == preH) && (midL == midH)) { printf("%c", pre[preL]); return; }
	int pos = 0;
	for (; pos <= midH - midL; pos++) {
		if (mid[midL + pos] == pre[preL]) break;
	}
	if (pos > 0) findPost(preL + 1, preL + pos, midL, midL + pos - 1);
	if (pos < midH - midL) findPost(preL + pos + 1, preH, midL + pos + 1, midH);
	printf("%c", pre[preL]);
}
int main() {
	scanf("%s", pre), scanf("%s", mid);
	findPost(0, strlen(pre) - 1, 0, strlen(mid) - 1);
}