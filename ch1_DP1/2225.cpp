#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int d[201][201]; // 앞에가 정수 N, 뒤에가 K개를 쓴다라고 하고
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	long long ans = 0LL;
	int mod = 1000000000;
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
		d[i][1] = 1;
	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				ans += d[k][i - 1];
			}
			ans %= mod;
			d[j][i] = ans;
			ans = 0LL;
		}
	}

	cout << d[N][K];
	

	return 0;
}