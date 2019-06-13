#include<iostream>
#include<string>
using namespace std;

#pragma warning(disable:4996)
string e[8] = { "000","001","010","011","100","101","110","111" };
int main() {
	string s;
	cin >> s;
	int a = s[0] - '0';
	string c = "";
	do {
		int r = a % 2;
		c = (char)(r + '0') + c;
		a /= 2;
	} while (a != 0);
	cout << c;

	for (int i = 1; i < s.length(); i++) {
		int j = s[i] - '0';
		cout << e[j];
	}

	return 0;
}