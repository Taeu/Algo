#include <string>
#include <iostream>
#include <list>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n;
	cin >> s;
	list<char> lc;
	for (int i = 0; i < s.length(); i++) {
		lc.push_back(s[i]);
	}
	cin >> n;
	char c;
	auto it = lc.end();
	while (n--) {
		cin >> c;
		if (c == 'L') {
			if (it != lc.begin())
				it--;
		}
		else if (c == 'D') {
			if (it != lc.end())
				it++;
		}
		else if (c == 'B') {
			if (it != lc.begin()) {
				--it;
				it = lc.erase(it);
			}
		}
		else if (c == 'P') {
			cin >> c; // ����� ������ Ȯ���غ����� Ȯ�οϷ�
			lc.insert(it, c); // list�� insert�ϰ� iterator ++ �����ֳ���
		}
	}
	for (char x : lc) {
		cout << x;
	}

	return 0;
}