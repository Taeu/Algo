#include<vector>
#include<iostream>
#include<string>

using namespace std;

#pragma warning(disable:4996)

int main() {
	string s = "abcd";
	vector<char> v;
	auto it = s.begin();
	int i = 0;
	for (; it != s.end(); it++) {
		cout << *it << ++i <<' ';
	}
	cout << '\n';
	auto it0 = s.begin();
	auto it1 = s.begin() + 1;
	auto it2 = s.begin() + 2;
	auto it3 = s.begin() + 3;
	auto it4 = s.begin() + 4;
	s.insert(it4, 'i');
	if (it4 == s.end()) cout << "true";
	

	cout << *it0 << *it1 << *it2 << *it3 << *it4;
	cout << '\n';
	it = s.end();
	for (; it != s.begin();) {
		cout << *(--it);
	}
	cout << '\n';
/*
	for (int i = 0; i < 5; i++) {
		v.push_back(65 + i);
	}
	auto it = v.begin();
	for (int i = 0; i < 5; i++) {
		it = v.erase(it);
		for (char x : v) {
			cout << x;
		}
		cout << '\n';
	}
	cout << '\n';

*/
	for (char x : s) {
		cout << x;
	}
	cout << '\n';


	return 0;
}