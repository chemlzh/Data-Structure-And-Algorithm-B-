#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
long num1[250], num2[250], ans[250], len1, len2, len;
char c, str1[250], str2[250];
int main() {
	scanf("%s", str1), scanf("%s", str2);
	len1 = strlen(str1), len2 = strlen(str2);
	for (long i = 1; i <= len1; i++) num1[i] = str1[len1 - i] - '0';
	for (long i = 1; i <= len2; i++) num2[i] = str2[len2 - i] - '0';
	len = (len1 > len2) ? len1 : len2;
	for (long i = 1; i <= len; i++) {
		ans[i] += num1[i] + num2[i];
		ans[i + 1] += ans[i] / 10, ans[i] %= 10;
	}
	for (long i = len + 1; i >= 1; i--) {
		if (ans[i]) { len = i; break; }
	}
	for (long i = len; i >= 1; i--) printf("%ld", ans[i]);
}