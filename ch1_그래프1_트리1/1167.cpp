#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include<cstring>
using namespace std;

#pragma warning(disable : 4996)

vector<pair<int, int>> t[100001]; // first ดย vertex, second ดย edge
bool check[100001];
int dist[100001];
queue <int> q;

void bfs(int start) {
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		check[current] = true;
		
		for (pair<int, int> p : t[current]) {
			if (check[p.first] == false) {
				dist[p.first] = dist[current] + p.second;
				q.push(p.first);
			}
		}
	}
}


int main() {

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		while (1) {
			int v, d;
			scanf("%d", &v);
			if (v == -1) break;
			scanf("%d", &d);
			t[x].push_back(make_pair(v, d));
		}
	}
	bfs(1); // random index, which is 1 in my case;
	
	// find most far from 1
	int longgest = 0;
	int long_idx = 0;
	for (int i = 2; i <= N; i++) {
		if (dist[i] > longgest) {
			longgest = dist[i];
			long_idx = i;
		}
	}
	
	// reset check & dist
	memset(check, false, sizeof(check));
	memset(dist, 0, sizeof(dist));

	bfs(long_idx);
	for (int i = 1; i <= N; i++) {
		if (dist[i] > longgest) {
			longgest = dist[i];
		}
	}

	printf("%d", longgest);

	return 0;
}