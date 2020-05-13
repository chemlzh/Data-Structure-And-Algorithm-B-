#include <cstdio>
using namespace std;
long T, M, cost[105], value[105], f[1005];
int main() {
	scanf("%ld%ld", &T, &M);
	for (long i = 1; i <= M; i++) scanf("%ld%ld", &cost[i], &value[i]);
	for (long i = 1; i <= M; i++) {
		for (long j = T; j >= 0; j--) {
			if (j >= cost[i]) {
				f[j] = (f[j] > f[j - cost[i]] + value[i]) ? f[j] : (f[j - cost[i]] + value[i]);
			}
		}
	}
	printf("%ld", f[T]);
}