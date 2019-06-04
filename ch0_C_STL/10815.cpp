#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v;
	while (N--) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	cin >> N;
	sort(v.begin(), v.end());
	while (N--) {
		int num, check;
		cin >> num;
		if (binary_search(v.begin(), v.end(), num))
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}
	return 0;
}