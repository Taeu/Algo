#include<algorithm>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int prime[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, N;
	cin >> M >> N;
	int cnt = 0;
	// prime number
	prime[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == 0) {
			for (int j = i * 2; j <= 1000000; j += i) {
				prime[j] = 1;
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (prime[i] == 0)
			cout << i << '\n';
	}
	return 0;
}