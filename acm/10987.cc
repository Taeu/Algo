#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

int solve(char c);
int main() {

	string s;
	int cnt = 0, n;

	cin >> s;
	n = s.length();
	for (int i = 0; i<n; i++) {
		cnt += solve(s[i]);
	}
	printf("%d\n", cnt);


	
	return 0;
}

int solve(char c) {
	int k = c - 0;
	if (k == 97 || k == 101 || k == 105 || k == 111 || k == 117)
		return 1;
	else
		return 0;
}