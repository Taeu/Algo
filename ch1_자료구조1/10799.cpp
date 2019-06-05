#include<string>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int leftstack=0;
	int answer = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			leftstack++;
		}
		else {
			leftstack--;
			if (s[i - 1] == '(')
				answer += leftstack;
			else
				answer += 1;
		}
	}
	cout << answer << '\n';

	return 0;
}