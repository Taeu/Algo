#include<string>
#include<vector>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	string s;
	vector<char> v;
	vector<char> check;
	int okay = 1;
	while (N--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			v.push_back(s[i]);
		}
		for (int i = 0; i < s.length(); i++) {
			char c = v.back();
			if (c == '(') {
				if (check.empty()) {
					okay = 0;
					break;
				}
				else
					check.pop_back();
			}
			else
				check.push_back(c);
			v.pop_back();

		}
		if (okay && check.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		v.clear();
		check.clear();
		okay = 1;

	}
	
	
	return 0;
}