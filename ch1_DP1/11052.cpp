#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)
int price[1001];
int dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> price[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + price[j]);
		}
	}
	cout << dp[n];

	return 0;
}