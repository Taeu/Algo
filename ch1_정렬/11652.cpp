#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int max = 0;
	long long num;
	int cnt = 1;
	for (int i = 0; i < n-1; i++) {
		if (v[i] != v[i + 1]) {
			if (max < cnt) {
				max = cnt;
				num = v[i];
			}
			cnt = 1;
		}
		else
			cnt++;
	}
	if (max < cnt) {
		num = v[n-1];
	}

	cout << num;
	return 0;
}