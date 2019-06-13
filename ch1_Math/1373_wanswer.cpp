#include<iostream>
#include<string>
using namespace std;

#pragma warning(disable:4996)

int main() {
	string s;
	cin >> s;
	
	int num = 0;
	int mul = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		char c = s[i];
		int a = s[i] - '0';
		num = num + mul * a;
		mul *= 2;
	}
	cout << "2진수 숫자는 원래 : " << num << '\n';
	string num8 = "";
	do {
		char r =(num % 8) + '0';
		num8 = r + num8;
		num /= 8;
	} while (num != 0);

	cout << num8;


	return 0;
}