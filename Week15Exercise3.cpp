#include <cstdio>
#include <algorithm>
using namespace std;
struct segment { long l, r; }s[50005];
long n, ansl, ansr;
inline bool cmp(const segment s1, const segment s2) {
	if (s1.l < s2.l) return true;
	else if (s1.l > s2.l) return false;
	else if (s1.r < s2.l) return true;
	else return false;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld%ld", &s[i].l, &s[i].r);
	if (n == 1) printf("%ld %ld", s[1].l, s[1].r);
	else {
		sort(s + 1, s + n + 1, cmp);
		ansl = s[1].l, ansr = s[1].r;
		for (long i = 2; i <= n; i++) {
			if (s[i].l > ansr) {
				printf("%s", "no"); return 0;
			}
			else ansr = (s[i].r > ansr) ? s[i].r : ansr;
		}
		printf("%ld %ld", ansl, ansr);
	}
}