#include<bitset>
#include<iostream>
using namespace std;

#pragma warning (disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	bitset<100000> A(s);
	cin >> s;
	bitset<100000> B(s);

	cout << (A&B) << '\n';
	cout << (A | B) << '\n';
	cout << (A ^ B) << '\n';
	cout << (~A) << '\n';
	cout << (~B) << '\n';
	return 0;

}