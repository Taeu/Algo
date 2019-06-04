#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	while (M--) {
		int s, e, m;
		cin >> s >> e >> m;
		rotate(v.begin() + s -1, v.begin() + m -1, v.begin() + e);
	}
	for (int x : v) {
		cout << x << ' ';
	}
	return 0;
}