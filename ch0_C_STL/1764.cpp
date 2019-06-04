#include <map>
#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable:4996)

int main() {
	map<string, int> m;
	int N, M;
	cin >> N >> M;
	string s;
	int sum = 0;
	while (N--) {
		cin >> s;
		m[s] = 1;
	}
	while (M--) {
		cin >> s;
		if (m.count(s)) {
			m[s] = 2;
			sum++;
		}
	}
	cout << sum << '\n';
	for (auto p : m) {
		if (p.second == 2)
			cout << p.first << '\n';
	}
	return 0;
}