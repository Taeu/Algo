#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#pragma warning(disable:4996)
vector<int> v(100001);
vector<int> visit(100001);

int DFS(int current) {
	visit[current] = 1;
	if (visit[v[current]] == 0) {
		DFS(v[current]);
	}
	else {
		return current;
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
		}
		for (int i = 1; i <= n; i++) {
			int last;
			last = DFS(v[i]);
			//cout << "last : " << last << '\n';
			if (i != last)
				cnt++;
			for (int i = 1; i <= n; i++) {
				visit[i] = 0;
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}



	return 0;
}