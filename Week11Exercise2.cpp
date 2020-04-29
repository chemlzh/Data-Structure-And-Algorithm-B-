#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge { long u, v, w; }e[200];
long n, cnt, weight, tot, ans;
long father[50];
char c, s, t;
inline bool cmp(const edge e1, const edge e2) { return e1.w < e2.w; }
inline long find(long x) {	return (x == father[x]) ? x : (father[x] = find(father[x])); }
int main() {
	scanf("%ld%c", &n, &c);
	for (long i = 1; i <= n; i++) father[i] = i;
	while (scanf("%c%ld", &s, &cnt) != EOF) {
		for (long i = 1; i <= cnt; i++) {
			scanf("%c%c%ld", &c, &t, &weight);
			++tot, e[tot].u = s - 'A' + 1, e[tot].v = t - 'A' + 1, e[tot].w = weight;
		}
		scanf("%c", &c);
	}
	sort(e + 1, e + tot + 1, cmp);
	for (long i = 1; i <= tot; i++) {
		long x = find(e[i].u), y = find(e[i].v);
		if (x != y) ans += e[i].w, father[x] = y;
	}
	printf("%ld", ans);
}