#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#pragma warning(disable:4996)
vector<int> v(100001);
vector<int> visit(100001);
vector<int> start_point(100001);
int DFS(int current,int step, int start) {
	visit[current] = step;
	start_point[current] = start;
	if (visit[v[current]] == 0) {
		DFS(v[current], ++step, start);
	}
	else {
		if (start_point[v[current]] == start)
			return step - visit[v[current]]+1;
		else
			return 0;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	int cnt = 0;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			visit[i] = 0;
			start_point[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0)
				cnt += DFS(i,1,i);

		}
		cout << n-cnt << '\n';
		cnt = 0;
	}



	return 0;
}