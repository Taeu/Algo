#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int s[301];
int dp[301][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	dp[1][0] = s[1];
	dp[1][1] = 0;
	dp[2][0] = s[2];
	dp[2][1] = dp[1][0] + s[2];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][1],dp[i-2][0]) + s[i];
		dp[i][1] = dp[i - 1][0]+s[i];
	}
	cout << max(dp[n][0], dp[n][1]);

	return 0;
}