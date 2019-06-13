#include<iostream>
#include<string>
using namespace std;

#pragma warning(disable:4996)

int main() {
	string s;
	cin >> s;
	
	int num = 0;
	int mul = 1;
	if (s.length() % 3 == 1)
		s = "00" + s;
	else if (s.length() % 3 == 2)
		s = "0" + s;

	string num8 = "";
	for (int i = 0; i < s.length(); i = i+3) {
		int a = 0;
		a = a + (s[i] - '0') * 4;
		a = a + (s[i + 1] - '0') * 2;
		a = a + (s[i + 2] - '0') * 1;
		char c = a + '0';
		cout << c;
	}


	return 0;
}