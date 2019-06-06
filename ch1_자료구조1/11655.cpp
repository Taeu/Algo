#include<string>
#include<iostream>

using namespace std;

#pragma warning(disable:4996)

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c >= 'a' && c <= 'z') s[i] = 'a' + (c - 'a' + 13) % 26;
		else if (c >= 'A' && c <= 'Z') s[i] = 'A' + (c - 'A' + 13) % 26;
		
	}
	for (char x : s) {
		cout << x;
	}
	return 0;
}