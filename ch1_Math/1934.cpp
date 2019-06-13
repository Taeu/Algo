#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int gcd(int a, int b) {	
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << a / gcd(a, b) * b << '\n';
	}

	return 0;
}
