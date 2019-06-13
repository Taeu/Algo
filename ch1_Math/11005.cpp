#include<string>
#include<iostream>
#pragma warning (diasable:4996)

using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	string s = "";
	do  {
		int m, n;
		n = a % b;
		char c;
		if (n < 10) {
			c = n + 48;
			s = c + s;
		}
		else {
			c = n + 55;
			s = c + s;
		}

		m = a / b;
		a = m;
	} while ( a != 0);
	cout << s;

	return 0;
}

/*
int main() {

	int n, b;

	cin >> n >> b;

	string ans =  "";

	while (n > 0) {

		int r = n % b;

		if (r < 10) {

			ans += (char)(r + '0');

		} else {

			ans += (char)(r - 10 + 'A');

		}

		n /= b;

	}

	reverse(ans.begin(),ans.end());

	cout << ans << '\n';

	return 0;

}

*/