#include<cstdio>
#include<vector>
#include<queue>
#include <functional>
using namespace std;

#define INF 987654321
typedef pair<int, int> ii;

int main() {
	vector<ii> list[20001];
	int dist[20001];
	int v, e;
	scanf("%d%d", &v, &e);
	int st;
	scanf("%d", &st);
	for (int i = 1; i <= v; ++i)
		dist[i] = INF;
	for (int i = 0; i<e; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		list[a].push_back(ii(b, c));
	}
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, st));
	while (!pq.empty()) {
		ii cur = pq.top();
		int u = cur.second;
		int cost = cur.first;
		pq.pop();
		if (dist[u]<cost) continue;
		for (int i = 0; i<list[u].size(); ++i) {
			int v = list[u][i].first;
			int w = list[u][i].second;
			if (dist[v]> cost + w) {
				dist[v] = cost + w;
				pq.push(ii(dist[v], v));
			}
		}

	}
	dist[st] = 0;
	for (int i = 1; i <= v; ++i) {
		
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);

	}
	return 0;
}