#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
	if (n > 1)
		cout << n;

	return 0;
}