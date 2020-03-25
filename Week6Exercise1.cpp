#include <cstdio>
#include <queue>
#include <functional>
using namespace std;
long n, value, ans = 0;
priority_queue<long, vector<long>, greater<long>> t;
int main() {
	scanf("%ld", &n);
	for (int i = 0; i < n; i++) scanf("%ld", &value), t.push(value);
	long a, b, tmp;
	while (t.size() > 1) {
		a = t.top(), t.pop();
		b = t.top(), t.pop();
		tmp = a + b, ans += tmp, t.push(tmp);
	}
	printf("%ld\n", ans);
}