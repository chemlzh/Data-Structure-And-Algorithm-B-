#include <cstdio>
using namespace std;
long n, f[20][20];
int main() {
	scanf("%ld", &n);
	for (long i = 0; i <= n; i++) f[i][0] = 1;
	for (long j = 1; j <= n; j++) {
		for (long i = 0; i <= n - j; i++) f[i][j] = (i == 0) ? f[i + 1][j - 1] : (f[i + 1][j - 1] + f[i - 1][j]);
	}
	printf("%ld", f[0][n]);
}