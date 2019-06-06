#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int l = 0, u = 0, n = 0, sp = 0;
	while (getline(cin, s)) {
		for (char x : s) {
			if (x >= 'a' && x <= 'z') l++;
			else if (x >= 'A' && x <= 'Z') u++;
			else if (x == ' ') sp++;
			else if (x >= '0' && x <= '9') n++;
		}
		cout << l <<' '<< u <<' '<< n <<' '<< sp << '\n';
		l = 0; u = 0; n = 0; sp = 0;
	}

	return 0;
}