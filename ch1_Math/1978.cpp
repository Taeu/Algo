#include<algorithm>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int prime[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int cnt = 0;
	// prime number
	for (int i = 2; i <= 31; i++) {
		if (prime[i] == 0) {
			for (int j = i * 2; j <= 1000; j += i) {
				prime[j] = 1;
			}
		}
	}

	while (N--) {
		int num;
		cin >> num;
		if (num == 1) continue;
		if (prime[num] == 0) cnt++;
	}
	cout << cnt;
	return 0;
}