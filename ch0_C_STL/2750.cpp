#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, num;
	vector<int> v;
	cin >> N;
	while (N--) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int x : v) {
		cout << x << '\n';
	}
	return 0;
}