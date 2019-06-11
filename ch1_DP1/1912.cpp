#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)
int a[100001];
int d[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (d[i - 1] + a[i] > d[i])
			d[i] = d[i - 1] + a[i];
	}
	int max = -1111;
	for (int i = 1; i <= n; i++) {
		if (max < d[i])
			max = d[i];
	}
	cout << max;

	return 0;
}