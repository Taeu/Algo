#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	string s;
	cin >> s;
	for (int i = 'a'; i <= 'z'; i++) {
		auto it = find(s.begin(), s.end(), i);
		if (it == s.end()) {
			cout << -1 << ' ';
		}
		else {
			cout << it - s.begin() << ' ';
		}
	}


	return 0;
}