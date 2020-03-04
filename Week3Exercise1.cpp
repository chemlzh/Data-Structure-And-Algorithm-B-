#include <cstdio>
#include <cstring>
using namespace std;
long n, maxcnt, cnt[26];
char maxchar, str[1005];
int main() {
	scanf("%ld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		memset(cnt, 0, sizeof(cnt)), maxcnt = -1, maxchar = '\0';
		for (int j = 0; j < strlen(str); j++) cnt[str[j] - 'a']++;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > maxcnt) maxcnt = cnt[i], maxchar = 'a' + i;
		}
		printf("%c %ld\n", maxchar, maxcnt);
	}
}