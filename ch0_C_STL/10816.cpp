#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#pragma warning(disabla:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N,M;
	cin >> N;
	vector <int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cin >> M;
	sort(v.begin(), v.end());
	while (M--) {
		int num; 
		cin >> num;
		auto l = lower_bound(v.begin(), v.end(), num);
		auto r = upper_bound(v.begin(), v.end(), num);


		cout << r - l << ' ';
	}
	return 0;
}