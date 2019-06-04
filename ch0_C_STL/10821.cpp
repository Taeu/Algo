#include<string>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int cnt = 0;
	while (getline(cin, s, ',')) {
		cnt++;
	}
	cout << cnt << '\n';

	return 0;
}