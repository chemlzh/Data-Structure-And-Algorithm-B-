#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
typedef pair<long, long> numPair;
unordered_map<string, long> dict;
struct edge { long u, v, w; }e[150];
char place[50][30], p1[30], p2[30];
long firstEdge[50], nextEdge[150];
long matrix[50][50];
long P, Q, R, s, t, weight, tot;
inline void addEdge(long u, long v, long w) {
	++tot, e[tot].u = u, e[tot].v = v, e[tot].w = w;
	nextEdge[tot] = firstEdge[e[tot].u], firstEdge[e[tot].u] = tot;
}
inline void shortestPath(long s, long t) {
	long dis[50], path[50], done[50];
	priority_queue<numPair, vector<numPair>, greater<numPair>> q;
	memset(dis, 1, sizeof(dis));
	memset(path, 1, sizeof(path));
	memset(done, 0, sizeof(done));
	dis[s] = path[s] = 0;
	q.push(make_pair(dis[s], s));
	while (!q.empty()) {
		numPair np = q.top(); q.pop();
		long x = np.second;
		if (done[x]) continue;
		done[x] = 1;
		for (long i = firstEdge[x]; i != -1; i = nextEdge[i]) {
			if (dis[e[i].v] > dis[e[i].u] + e[i].w) {
				dis[e[i].v] = dis[e[i].u] + e[i].w, path[e[i].v] = e[i].u;
				q.push(make_pair(dis[e[i].v], e[i].v));
			}
		}
	}
	stack<long> st;
	long x = t;
	while (path[x]) st.push(x), x = path[x];
	printf("%s", place[s]);
	x = s;
	while (!st.empty()) {
		printf("->(%ld)->%s", matrix[x][st.top()], place[st.top()]);
		x = st.top(), st.pop();
	}
	printf("\n");
}
int main() {
	scanf("%ld", &P);
	for (long i = 1; i <= P; i++) {
		scanf("%s", place[i]), dict[string(place[i])] = i;
	}
	scanf("%ld", &Q);
	memset(firstEdge, -1, sizeof(firstEdge));
	memset(matrix, 1, sizeof(matrix));
	for (long i = 1; i <= Q; i++) {
		scanf("%s%s%ld", p1, p2, &weight);
		s = dict[string(p1)], t = dict[string(p2)];
		if (matrix[s][t] > weight) matrix[s][t] = matrix[t][s] = weight;
		addEdge(s, t, weight), addEdge(t, s, weight);
	}
	scanf("%ld", &R);
	for (long i = 1; i <= R; i++) {
		scanf("%s%s", p1, p2), s = dict[string(p1)], t = dict[string(p2)];
		shortestPath(s, t);
	}
}