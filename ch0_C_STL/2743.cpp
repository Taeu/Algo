#include <string>
#include <iostream>
using namespace std;

#pragma warning (disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	getline(cin, s);
	cout << s.length();

	return 0;
}