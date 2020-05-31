#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long odd[10], even[10], tmp, cnt, cnt1, cnt2;
inline bool cmp(long a, long b) { return a > b; }
int main() {
	while (scanf("%ld", &tmp) != EOF) {
		cnt++;
		if (tmp & 1) odd[cnt1++] = tmp; else even[cnt2++] = tmp;
		if (cnt == 10) {
			sort(odd, odd + cnt1, cmp), sort(even, even + cnt2);
			for (long i = 0; i < cnt1; i++) printf("%ld ", odd[i]);
			for (long i = 0; i < cnt2 - 1; i++) printf("%ld ", even[i]);
			printf("%ld\n", even[cnt2 - 1]);
			cnt = 0, cnt1 = 0, cnt2 = 0;
		}
	}
}