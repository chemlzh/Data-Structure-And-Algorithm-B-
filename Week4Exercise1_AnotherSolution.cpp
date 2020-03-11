#include <cstdio>
using namespace std;
long n, f[20];
int main() {
	scanf("%ld", &n);
	f[0] = 1, f[1] = 1, f[2] = 2, f[3] = 5;
	for (long i = 4; i <= n; i++) {
		for (long j = 0; j < n; j++) f[i] += f[j] * f[i - 1 - j];
	}
	printf("%ld", f[n]);
}