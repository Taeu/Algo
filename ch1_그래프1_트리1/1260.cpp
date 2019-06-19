#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
#pragma wanring(disable:4996)
vector<int> dfs;
vector<bool> check(1001);
vector<int> v[1001];
void DFS(int current) {
	cout << current << ' ';
	check[current] = true;
	for (int i = 0; i < v[current].size(); i++) {
		if (check[v[current][i]] == false)
			DFS(v[current][i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, V;
	cin >> n >> m >> V;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= 1000; i++) {
		if(v[i].size())
			sort(v[i].begin(), v[i].end());
	}

	DFS(V);
	cout << '\n';
	
	
	for (int i = 1; i <= 1000; i++)
		check[i] = false;
	queue<int> bfs;
	bfs.push(V);
	check[V] = true;
	while (!bfs.empty()) {
		int current = bfs.front();
		cout << current << ' ';
		bfs.pop();
		for (int i = 0; i < v[current].size(); i++) {
			if (check[v[current][i]] == false) {
				check[v[current][i]] = true;
				bfs.push(v[current][i]);
			}
		}
	}


	return 0;
}