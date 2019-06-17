#include<algorithm>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int prime[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// prime number
	prime[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == 0) {
			for (int j = i * 2; j <= 1000000; j += i) {
				prime[j] = 1;
			}
		}
	}
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 3; i*2 <= n; i+=2) {
			if (prime[i] == 0 && prime[n - i] == 0) {
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
	}

	return 0;
}