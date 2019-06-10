#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)
int d[10001][3];
int am[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> am[i];
	d[1][0] = 0;
	d[1][1] = am[1];
	d[1][2] = 0;
	d[2][0] = am[1];
	d[2][1] = am[2];
	d[2][2] = am[1] + am[2];
	for (int i = 3; i <= n; i++) {
		d[i][0] = max(max(d[i - 1][2], d[i - 1][1]), d[i - 1][0]);
		d[i][1] = d[i - 1][0] + am[i];
		d[i][2] = d[i - 1][1] + am[i];
	}
	cout << max(max(d[n][0], d[n][1]), d[n][2]);


	return 0;
}