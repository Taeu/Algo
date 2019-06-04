#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)


int main() {
	string s;
	cin >> s;
	char a = 'a';
	for (int i = 0; i < 26; i++) {
		int num = count(s.begin(), s.end(), a);
		cout << num << ' ';
		a += 1;

	}

	return 0;
}