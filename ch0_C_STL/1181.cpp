#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<string> v;
	while (N--) {
		string s; 
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), [](const string s1, const string s2) {
		if (s1.length() == s2.length()) {
			return s1 < s2;
		}
		else
			return s1.length() < s2.length();
	});

	auto last = unique(v.begin(), v.end());
	v.erase(last, v.end());

	for (string s : v) {
		cout << s << '\n';
	}

	return 0;
}