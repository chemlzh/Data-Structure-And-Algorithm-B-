#include <cstdio>
#include <vector>
using namespace std;
long n, ans;
long a[105][105], f[105][105];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= i; j++) scanf("%ld", &a[i][j]);
	}
	f[1][1] = a[1][1];
	for (long i = 2; i <= n; i++) {
		for (long j = 1; j <= i; j++) {
			if (j == 1) f[i][j] = f[i - 1][j] + a[i][j];
			else if (j == i) f[i][j] = f[i - 1][j - 1] + a[i][j];
			else f[i][j] = ((f[i - 1][j] > f[i - 1][j - 1]) ? f[i - 1][j] : f[i - 1][j - 1]) + a[i][j];
		}
	}
	for (long i = 1; i <= n; i++) ans = (f[n][i] > ans) ? f[n][i] : ans;
	printf("%ld", ans);
}