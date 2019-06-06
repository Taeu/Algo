#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a[26] = { 0, };

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 97]++;
	}

	for (int x : a) {
		cout << x << ' ';
	}

	return 0;
}