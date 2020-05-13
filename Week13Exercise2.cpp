#include <iostream>
#include <vector>
using namespace std;
long N, num[20005];
inline long merge(long sect[], long left, long right) {
	if (left == right) return 0;
	else {
		long* temp = new long[right - left + 1];
		long mid = left + ((right - left) >> 1);
		long cnt = merge(sect, left, mid) + merge(sect, mid + 1, right);
		long pos=0, p1 = left, p2 = mid + 1;
		while ((p1<=mid) && (p2<=right)) {
			if (sect[p1] <= sect[p2]) temp[pos++] = sect[p1++];
			else temp[pos++] = sect[p2++], cnt += mid + 1 - p1;
		}
		while (p1 <= mid) temp[pos++] = sect[p1++];
		while (p2 <= right) temp[pos++] = sect[p2++];
		for (long i = 0; i < pos; i++) sect[left + i] = temp[i];
		return cnt;
	}
}
int main() {
	while (scanf("%ld", &N) != EOF) {
		if (N == 0) break;
		for (long i = 0; i < N; i++) scanf("%ld", &num[i]);
		printf("%ld\n", merge(num, 0, N - 1));
	}
}