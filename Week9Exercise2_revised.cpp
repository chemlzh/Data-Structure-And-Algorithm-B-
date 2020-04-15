#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char tempseq[150];
long n, m;
struct DNA { char seq[150]; long pnum, rank; }d[150];
inline bool cmp(const DNA d1, const DNA d2) {
	if (d1.pnum < d2.pnum) return 1;
	else if (d1.pnum > d2.pnum) return 0;
	else if (d1.rank < d2.rank) return 1;
	else return 0;
}
inline long mergesort(char s[], long left, long right) {
	if (left == right) return 0;
	else {
		char* t = new char[right - left + 1];
		memset(t, 0, sizeof(t));
		long mid = ((right - left) >> 1) + left, pos = 0, i = left, j = mid + 1, cnt = 0;
		cnt = mergesort(s, left, mid) + mergesort(s, mid + 1, right);
		while ((i<=mid)&&(j<=right)) {
			if (s[i] <= s[j]) t[pos++] = s[i++];
			else cnt += mid + 1 - i, t[pos++] = s[j++];
		}
		while (i <= mid) t[pos++] = s[i++];
		while (j <= right) t[pos++] = s[j++];
		for (long a = 0; a < pos; a++) s[left + a] = t[a];
		return cnt;
	}
}
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 0; i < m; i++) {
		scanf("%s", d[i].seq);
		strcpy(tempseq, d[i].seq), d[i].rank = i;
		d[i].pnum = mergesort(tempseq, 0, n - 1);
	}
	sort(d, d + m, cmp);
	for (long i = 0; i < m; i++) printf("%s\n", d[i].seq);
}