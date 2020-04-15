#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point { long x, y, z; }p[15];
struct PointPair { Point p1, p2; long rank; double dis; }ppair[250];
long n, cnt;
inline bool cmp(const PointPair a, const PointPair b) {
	if (a.dis > b.dis) return 1;
	else if (a.dis < b.dis) return 0;
	else if (a.rank < b.rank) return 1;
	else return 0;
}
int main() {
	scanf("%ld", &n);
	for (long i = 0; i < n; i++) {
		scanf("%ld%ld%ld", &p[i].x, &p[i].y, &p[i].z);
		for (long j = 0; j < i; j++, cnt++) {
			ppair[cnt].p1 = p[j], ppair[cnt].p2 = p[i];
			ppair[cnt].rank = (!j) ? (i - 1) : (ppair[cnt - 1].rank + n - 1 - j);
			ppair[cnt].dis = sqrt(pow(ppair[cnt].p1.x - ppair[cnt].p2.x, 2.0) + pow(ppair[cnt].p1.y - ppair[cnt].p2.y, 2.0) + pow(ppair[cnt].p1.z - ppair[cnt].p2.z, 2.0));
		}
	}
	sort(ppair, ppair + cnt, cmp);
	for (long i = 0; i < cnt; i++) 
		printf("(%ld,%ld,%ld)-(%ld,%ld,%ld)=%.2f\n", ppair[i].p1.x, ppair[i].p1.y, ppair[i].p1.z, ppair[i].p2.x, ppair[i].p2.y, ppair[i].p2.z, ppair[i].dis);
}