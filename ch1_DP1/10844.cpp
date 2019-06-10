#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)

int dp[101][10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; 
	cin >> n;
	dp[1][0] = 0;
	long long ln = 1000000000;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= 100; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % ln;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += dp[n][i];
	cout << ans % ln;
	return 0;
}