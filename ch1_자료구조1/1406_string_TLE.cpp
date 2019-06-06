#include <string>
#include <iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n;
	cin >> s;
	cin >> n;
	char c;
	auto it = s.end();
	while (n--) {
		cin >> c;
		if (c == 'L') {
			if (it != s.begin())
				it--;
		}
		else if (c == 'D') {
			if (it != s.end())
				it++;
		}
		else if (c == 'B') {
			if (it != s.begin()) {
				--it;
				it = s.erase(it);
				
			}
			
		}
		else if (c == 'P') {
			cin >> c; // 제대로 들어가는지 확인해봐야함
			s.insert(it, c);
			it++;
		}
	}
	for (char x : s) {
		cout << x;
	}

	return 0;
}