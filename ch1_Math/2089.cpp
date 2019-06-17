#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int n;
	cin >> n;
	string s = "";
	//cout << -1 / 2 << ' ' << -2 / 2 << ' ' << -3 / 2 << ' ' << -4 / 2 << '\n';
	//cout << -1 % 2 << ' ' << -2 % 2 << ' ' << -3 % 2 << ' ' << -4 % 2 << '\n';
	do {
		int r = n % 2;
		if (n < 0) {
			n = (n - 1) / 2;
			n *= -1;
			r *= -1;
		}
		else {
			n = n / 2;
			n *= -1;
		}

		if (r == 1)
			s = '1' + s;
		else
			s = '0' + s;

		
		
	} while (n != 0);

	cout << s;
	return 0;
}