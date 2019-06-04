#include<iostream>
#include<vector>
#include<algorithm>
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
		int a, b;
		cin >> a >> b;
		swap(v[a-1], v[b-1]);
	}

	for (int x : v) {
		cout << x << ' ';
	}
	return 0;
}