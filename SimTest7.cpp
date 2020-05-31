#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
struct Edge { long u, v, w; }e[105];
long p, q, r, dep, arr, len;
long graph[50][50];
long head[50], nextEdge[105], cnt;
char place[50][30], from[30], to[30];
unordered_map<string, long> dict;
inline void addEdge(long u,long v,long w) {
	cnt++, e[cnt].u = u, e[cnt].v = v, e[cnt].w = w;
	nextEdge[cnt] = head[u], head[u] = cnt;
}
inline void spfa(long s, long t) {
	queue<long> q;
	long d[50], inq[50], path[50];
	memset(d, 1, sizeof(d)), memset(inq, 0, sizeof(inq)), memset(path, 0, sizeof(path));
	d[s] = 0, q.push(s);
	while (!q.empty()) {
		long x = q.front(); q.pop();
		inq[x] = 0;
		for (long i = head[x]; i != 0; i = nextEdge[i]) {
			if (d[e[i].v] > d[x] + e[i].w) {
				d[e[i].v] = d[x] + e[i].w, path[e[i].v] = x;
				if (!inq[e[i].v]) { inq[e[i].v] = 1; q.push(e[i].v); }
			}
		}
	}
	stack<long> st;
	st.push(t);
	while (path[t]) t = path[t], st.push(t);
	long tmp = st.top();
	printf("%s", place[st.top()]), st.pop();
	while (!st.empty()) {
		printf("->(%ld)->%s", graph[tmp][st.top()], place[st.top()]);
		tmp = st.top(), st.pop();
	}
	printf("\n");
}
int main() {
	scanf("%ld", &p);
	for (long i = 1; i <= p; i++) {
		scanf("%s", place[i]), dict[string(place[i])] = i;
	}
	scanf("%ld", &q);
	for (long i = 1; i <= q; i++) {
		scanf("%s %s %ld", from, to, &len);
		dep = dict[string(from)], arr = dict[string(to)];
		if (!graph[dep][arr]) graph[dep][arr] = len;
		else graph[dep][arr] = min(graph[dep][arr], len);
		graph[arr][dep] = graph[dep][arr];
		addEdge(dep, arr, len), addEdge(arr, dep, len);
	}
	scanf("%ld", &r);
	for (long i = 1; i <= r; i++) {
		scanf("%s %s", from, to);
		dep = dict[string(from)], arr = dict[string(to)];
		spfa(dep, arr);
	}
}