#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.length();
	string s1="", s2="", s3="";
	vector<string> all;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int a = i; a >= 0; a--)
				s1 += s[a];
			for(int b=j; b>i; b--)
				s2 += s[b];
			for(int c=n-1; c>j;c--)
				s3 += s[c];
			all.push_back(s1 + s2 + s3);
			s1 = s2 = s3 = "";
		}
	}
	sort(all.begin(), all.end());
	printf("%s\n", all[0].c_str());
	return 0;
}