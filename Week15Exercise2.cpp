#include <cstdio>
#include <unordered_map>
#include <map>
#include <algorithm>
#define pairLL pair<long, long>
using namespace std;
pairLL p[1005];
long n, cnt;
inline bool cmp(const pairLL p1, const pairLL p2) {
	if (p1.first < p2.first) return true;
	else if (p1.first > p2.first) return false;
	else if (p1.second < p2.second) return true;
	else return false;
}
inline bool judge(const pairLL p1) {
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = l + ((r - l) >> 1);
		if ((p[mid].first==p1.first)&& (p[mid].second == p1.second))	
			return true;
		else if ((p[mid].first > p1.first) || ((p[mid].first == p1.first) && (p[mid].second > p1.second)))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return false;
}
int main() {
	while (scanf("%ld", &n) != EOF) {
		if (!n) break;
		cnt = 0;
		for (long i = 1; i <= n; i++) scanf("%ld%ld", &p[i].first, &p[i].second);
		sort(p + 1, p + n + 1, cmp);
		for (long i = 1; i <= n; i++) {
			for (long j = i + 1; j <= n; j++) {
				long dx = p[j].first - p[i].first, dy = p[j].second - p[i].second;
				pairLL p3 = make_pair(p[i].first - dy, p[i].second + dx);
				pairLL p4 = make_pair(p[j].first - dy, p[j].second + dx);
				if ((judge(p3)) && (judge(p4))) cnt++;
			}
		}
		printf("%ld\n", cnt / 2);
	}
}