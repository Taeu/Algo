#include <string>
#include <iostream>
using namespace std;

#pragma warning (disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int sum = 0;
	while (getline(cin, s, ',')) {
		sum += stoi(s);
	}

	return 0;
}