#include<iostream>
using namespace std;

#pragma warning(disable:4996)
int d[1001][10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}
	int div = 10007;
	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int z = 0; z <= j; z++) {
				d[i][j] += d[i - 1][z];
			}
			d[i][j] %= div;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];
	cout << ans % div;
	return 0;
}