#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
unordered_map<string, long> dict;
char place[50][30], p1[30], p2[30], tmp;
long graph[50][50], dis[50][50], path[50][50];
long P, Q, R, s, t, d;
int main() {
	scanf("%ld", &P);
	memset(graph, 1, sizeof(graph));
	memset(dis, 1, sizeof(dis));
	memset(path, 1, sizeof(path));
	for (long i = 1; i <= P; i++) {
		scanf("%s", place[i]), dict[string(place[i])] = i, dis[i][i] = path[i][i] = 0;
	}
	scanf("%ld", &Q);
	for (long i = 1; i <= Q; i++) {
		scanf("%s%s%ld", p1, p2, &d), s = dict[string(p1)], t = dict[string(p2)];
		if (d < dis[s][t]) {
			graph[s][t] = graph[t][s] = d;
			dis[s][t] = dis[t][s] = d;
			path[s][t] = t, path[t][s] = s;
		}
	}
	for (long k = 1; k <= P; k++) {
		for (long i = 1; i <= P; i++) {
			for (long j = 1; j <= P; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j], path[i][j] = path[i][k];
				}
			}
		}
	}
	scanf("%ld", &R);
	for (long i = 1; i <= R; i++) {
		scanf("%s%s", p1, p2), s = dict[string(p1)], t = dict[string(p2)];
		printf("%s", place[s]);
		long x = s;
		while (path[x][t]) {
			printf("->(%ld)->%s", graph[x][path[x][t]], place[path[x][t]]);
			x = path[x][t];
		}
		printf("\n");
	}
}