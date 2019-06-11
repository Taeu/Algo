#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)
int a[1001];
int d[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] > a[i] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[i])
			max = d[i];
	}
	cout << max;

	return 0;
}