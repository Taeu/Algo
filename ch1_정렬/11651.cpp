#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<int,int>> v(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = make_pair(b, a);
	}
	sort(v.begin(), v.end());
	for (pair<int,int> x : v)
		cout << x.second << ' '<< x.first << '\n';

	return 0;
}