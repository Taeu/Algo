#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int mul = 5;
	int fiv = 0;
	for (int i = 1; i <= 13; i++) {
		fiv = fiv + n / mul - (n-m)/mul - m/mul;
		mul *= 5;
	}
	mul = 2;
	int two = 0;
	for (int i = 1; i <= 30; i++) {
		two = two + n / mul - (n - m) / mul - m / mul;
		mul *= 2;
	}
	cout << min(fiv, two);

	return 0;
}