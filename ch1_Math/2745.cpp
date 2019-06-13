#include<iostream>
using namespace std;
#pragma warning(disable:4996)
#include<string>

int main() {
	string s;
	int n;
	cin >> s >> n;
	int mul = 1;
	int number = 0;
	for (int i = s.length()-1; i >= 0; i--) {
		char c = s[i];
		int a;
		if (c >= '0' && c <= '9') {
			a = s[i] - '0';
		}
		else {
			a = s[i] - 'A' + 10;
		}
		number = number + a * mul;
		mul *= n;
	}

	cout << number;

	return 0;
}