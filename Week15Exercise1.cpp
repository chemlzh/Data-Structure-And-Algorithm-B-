#include <cstdio>
using namespace std;
long n;
char stick[5], tmp;
inline void hanoi(int plate, int from, int to) {
	if (plate==1) printf("%ld:%c->%c\n", plate, stick[from], stick[to]);
	else {
		hanoi(plate - 1, from, 6 - from - to);
		printf("%ld:%c->%c\n", plate, stick[from], stick[to]);
		hanoi(plate - 1, 6 - from - to, to);
	}
}
int main() {
	scanf("%ld%c", &n, &tmp);
	for (long i = 1; i <= 3; i++) scanf("%c%c", &stick[i], &tmp);
	hanoi(n, 1, 3);
}