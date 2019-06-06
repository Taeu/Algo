#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	vector<string> vs;
	int j = 0;
	while (j<s.length()) {
		string s1;
		
		for (int i = j; i < s.length(); i++) {
			s1 += s[i];
		}
		vs.push_back(s1);
		j++;
	}
	sort(vs.begin(), vs.end());
	for (string s1 : vs) {
		cout << s1 << '\n';
	}

	return 0;
}