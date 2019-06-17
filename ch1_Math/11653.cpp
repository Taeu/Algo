#include<algorithm>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int prime[10000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// prime number
	prime[1] = 1;
	for (int i = 2; i <= 3162; i++) {
		if (prime[i] == 0) {
			for (int j = i * 2; j <= 10000000; j += i) {
				prime[j] = 1;
			}
		}
	}
	int n;
	cin >> n;
	while (n != 1) {
		for (int i = 2; i <= 10000000; i++) {
			if (prime[i] != 0) continue;
			if (n % i == 0) {
				cout << i << '\n';
				n /= i;
				break;
			}
		}
		
	}

	return 0;
}