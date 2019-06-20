#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#pragma warning(disable:4996)

vector<int> v(1001);
vector<bool> check(1001);

void DFS(int current) {
	check[current] = 1;
	if(check[v[current]] == false)
		DFS(v[current]);
}
void BFS(int start) {
	// 갈 영역이 한 군데 밖에 되지 않으므로 BFS를 구현할 필요는 없음.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		int cnt=0;
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			check[i] = false;
		}

		for (int i = 1; i <= n; i++) {
			if (check[i] == false) {
				cnt++;
				DFS(i);
			}
		}
		cout << cnt << '\n';

	}


	return 0;
}