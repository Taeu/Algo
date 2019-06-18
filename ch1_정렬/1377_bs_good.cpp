#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a = v[i].second - i;
		if (a > ans)
			ans = a;
	}
	cout << ans + 1;

	return 0;
}