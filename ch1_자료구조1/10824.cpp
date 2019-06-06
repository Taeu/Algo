#include<string>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	long long s1, s2;
	s1 = stoll(to_string(a) + to_string(b));
	s2 = stoll(to_string(c) + to_string(d));
	s1 += s2;
	cout << s1;
	return 0;
}