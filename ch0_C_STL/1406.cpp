#include <iostream>
#include <list>
#include <string>
using namespace std;

#pragma warning (disable:4996)

list<char> li;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		li.push_back(s[i]);
	}
	int N;
	char cmd,nothing,c;
	cin >> N;
	auto it = li.end();
	while (N--) {
		cin >> cmd;
		if (cmd == 'L') {
			if (it != li.begin())
				--it;
		}
		else if (cmd == 'D') {
			if (it != li.end())
				++it;

		}
		else if (cmd == 'B') {
			if (it != li.begin()) {
				auto temp = it;
				--temp;
				li.erase(temp);
			}
		}
		else if (cmd == 'P') {
			cin >> c;
			li.insert(it, c); // so..
		}

	}

	for (char x : li) {
		cout << x;
	}

	return 0;
}