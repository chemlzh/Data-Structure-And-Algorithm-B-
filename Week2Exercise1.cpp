#include <cstdio>
#include <vector>
using namespace std;
long m, n, oldpos, pos;
vector<long> NextPeople;
int main() {
	while (true) {
		scanf("%ld%ld", &n, &m);
		if ((n == 0) && (m == 0)) break;
		if (n == 1) { printf("%ld\n", 1); continue; }
		NextPeople.clear();
		for (long i = 0; i < n; i++) NextPeople.push_back((i + 1) % n);
		oldpos = n - 2, pos = n - 1;
		while (n) {
			for (long i = 0; i < m; i++) oldpos = pos, pos = NextPeople[pos];
			NextPeople[oldpos] = NextPeople[pos], n--;
		}
		printf("%ld\n", pos + 1);
	}
}