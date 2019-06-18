#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
int v[500000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	bool change = false;
	for (int i = 0; i <= n; i++) {
		change = false;
		for (int j = 0; j < n - 1 - i ; j++) {
			if (v[j] > v[j + 1]) {
				change = true;
				swap(v[j], v[j + 1]);
			}
		}
		if (change == false) {
			cout << i+1 << '\n';
			break;
		}
	}

	return 0;
}