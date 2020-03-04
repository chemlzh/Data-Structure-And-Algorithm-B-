#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char codes[105], words[105];
int ccnt[26], wcnt[26], diff, flag = 1;
int main() {
	scanf("%s", codes);
	scanf("%s", words);
	for (int i = 0; i < strlen(codes); i++) 	ccnt[codes[i] - 'A']++;
	for (int i = 0; i < strlen(words); i++) wcnt[words[i] - 'A']++;
	sort(ccnt, ccnt + 26), sort(wcnt, wcnt + 26);
	for (int i = 0; i < 26; i++) {
		if (ccnt[i] != wcnt[i]) { flag = 0; break; }
	}
	printf("%s", (flag) ? "YES" : "NO");
}