#include <string>
#include <iostream>
using namespace std;

#pragma warning (disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(c) + to_string(d);
	long long l1 = stoll(s1);
	long long l2 = stoll(s2);

	cout << l1 + l2;
	return 0;
}