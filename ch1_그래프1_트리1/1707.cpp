#include<vector>
#include<queue>
#include<iostream>
using namespace std;
#pragma warning(disable :4996)
vector<int> v[20001];
vector<int> check(20001);

void DFS(int current, int check_point) {
	check[current] = check_point;
	for (int i = 0; i < v[current].size(); i++) {
		if (check[v[current][i]] == 0)
			DFS(v[current][i], -check_point);
	}
}

void BFS(int start) {
	queue<int> q1;
	int	check_point = 1;
	q1.push(start);
	check[start] = check_point;
	while (!q1.empty()) {
		int current = q1.front();
		check_point = check[current];
		q1.pop();
		for (int i = 0; i < v[current].size(); i++) {
			if (check[v[current][i]] == 0) {
				check[v[current][i]] = -check_point;
				q1.push(v[current][i]);
			}
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int V, E;
		cin >> V >> E;
		while (E--) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (check[i] == 0)
				DFS(i, 1); //BFS(i);
				
		}


		bool ok = true;
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (check[v[i][j]] == check[i]) {
					ok = false;
					break;
				}
		
			}
		}
		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		// ÃÊ±âÈ­
		for (int i = 1; i <= V; i++) {
			v[i].clear();
			check[i] = 0;
		}
	}
	return 0;
}


