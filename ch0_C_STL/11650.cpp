#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#pragma warning (disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int, int>> v;
	
	int N;
	cin >> N;
	while (N--) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	for (auto k : v) {
		cout << k.first << ' ' << k.second << '\n';
	}


	return 0;
}