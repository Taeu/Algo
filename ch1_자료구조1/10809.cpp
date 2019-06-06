#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a[26];
	for (int i = 0; i < 26; i++) {
		a[i] = -1;
	}

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if(a[s[i]-97]==-1)
			a[s[i] - 97] = i;
	}

	for (int x : a) {
		cout << x << ' ';
	}

	return 0;
}