#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
#pragma warning(disable : 4996)
vector<int> v[1001];
vector<bool> check(1001);
vector<int> dfs;
queue<int> bfs;
int cnt;
void DFS(int current) {
	check[current] = true;
	for (int i = 0; i < v[current].size(); i++) {
		if (check[v[current][i]] == false) {
			DFS(v[current][i]);
		}
	}
}

void BFS(int start) {
	bfs.push(start);
	check[start] = true;

	while (!bfs.empty()) {
		int a = bfs.front();
		bfs.pop();
		for (int i = 0; i < v[a].size(); i++) {
			if (check[v[a][i]] == false) {
				bfs.push(v[a][i]);
				check[v[a][i]] = true;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// DFS
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) { // 간선이 없을 수도 있기 때문에 v[i].size 가 있으면 안됨
			cnt++;
			/* DFS
			dfs.push_back(i);
			DFS(i);
			*/
			BFS(i);
		}
	}

		


	cout << cnt;


	return 0;
}