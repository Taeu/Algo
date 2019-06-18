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
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int x : v)
		cout << x << '\n';

	return 0;
}