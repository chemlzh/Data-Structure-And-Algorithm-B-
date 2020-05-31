#include <cstdio>
#include <vector>
using namespace std;
long k, f[20];
inline bool judge(long num) {
	long pos = 0;
	for (long i = 0; i < k; i++) {
		pos = (pos + num) % (2 * k - i);
		if ((pos <= k) && (pos >= 1)) return false;
		else if (pos) pos--;
		else;
	}
	return true;
}
int main() {
	while (scanf("%ld", &k) != EOF) {
		if (!k) break;
		if (f[k]) printf("%ld\n", f[k]);
		else {
			for (long i = 1;; i++) {
				long t = i * (k + 1);
				if (judge(t)) { printf("%ld\n", t); f[k] = t; break; }
				else if (judge(t + 1)) { printf("%ld\n", t + 1); f[k] = t + 1; break; }
			}
		}
	}
}