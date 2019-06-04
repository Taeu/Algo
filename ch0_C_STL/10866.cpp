#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

#pragma warning(disable:4996)

deque<int> d;
void cmd(string);

int main() {
	int N;
	cin >> N;
	

	while (N--) {
		string s1;
		cin >> s1;
		cmd(s1);
	}

	return 0;
}

void cmd(string s1) {
	int n;
	if (s1 == "push_front") {
		cin >> n;
		d.push_front(n);
	}
	else if (s1 == "push_back") {
		cin >> n;
		d.push_back(n);
	}
	else if (s1 == "pop_front") {
		if (d.empty())
			cout << -1 << '\n';
		else {
			cout << d.front() << '\n';
			d.pop_front();
		}

	}
	else if (s1 == "pop_back") {
		if (d.empty())
			cout << -1 << '\n';
		else {
			cout << d.back() << '\n';
			d.pop_back();
		}
	}
	else if (s1 == "size") {
		cout << d.size() << '\n';
	}
	else if (s1 == "empty") {
		if (d.empty())
			cout << 1 << '\n';
		else 
			cout << 0 << '\n';
	}
	else if (s1 == "front") {
		if (d.empty()) 
			cout << -1 << '\n';
		else 
			cout << d.front() << '\n';
	}
	else if (s1 == "back") {
		if (d.empty())
			cout << -1 << '\n';
		else 
			cout <<d.back() << '\n';
	}
}