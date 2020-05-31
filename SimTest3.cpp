#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
long t, n, tmp;
int main() {
	scanf("%ld", &t);
	for (long i = 1; i <= t; i++) {
		scanf("%ld", &n);
		stack<long> s;
		queue<long> order;
		for (long j = 1; j <= n; j++) scanf("%ld", &tmp), order.push(tmp);
		for (long j = 1; j <= n; j++) {
			s.push(j);
			while ((!s.empty()) && (s.top() == order.front())) {
				s.pop(), order.pop();
			}
		}
		if (s.empty()) printf("%s\n", "yes");
		else printf("%s\n", "no");
	}
}