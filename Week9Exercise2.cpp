#include <cstdio>
#include <algorithm>
using namespace std;
long n, m;
struct DNA { char seq[150]; long pnum, rank; }d[150];
inline bool cmp(const DNA d1, const DNA d2) {
	if (d1.pnum < d2.pnum) return 1;
	else if (d1.pnum > d2.pnum) return 0;
	else if (d1.rank < d2.rank) return 1;
	else return 0;
}
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 0; i < m; i++) {
		scanf("%s", d[i].seq);
		d[i].rank = i;
		for (long j = 0; j < n; j++) {
			for (long k = j + 1; k < n; k++) d[i].pnum += (d[i].seq[j] > d[i].seq[k]) ? 1 : 0;
		}
	}
	sort(d, d + m, cmp);
	for (long i = 0; i < m; i++) printf("%s\n", d[i].seq);
}