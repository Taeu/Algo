#include <stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
bool cmp(string s1, string s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	return s1.length() < s2.length();
}
int main() {
	int n;
	scanf("%d", &n);
	set<string> U;
	vector<string> v;
	string s;
	while (n--) {
		cin >> s;
		if (U.find(s) != U.end()) {
			continue;
		}
		U.insert(s);
		v.push_back(s);
	}
	sort(v.begin(),v.end(),cmp);
	for (int i = 0; i < v.size(); i++)
		printf("%s\n", v[i].c_str());
	return 0;
}