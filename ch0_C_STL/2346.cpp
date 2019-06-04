#include <iostream>
#include <list>
using namespace std;

#pragma warning (disable:4996)

list<pair<int, int>> l1;

int main() {
	int N,a;
	cin >> N;
	int i = 1;
	// 입력
	while (N--) {
		cin >>a;
		l1.push_back(make_pair(i, a));
		i++;
	}
	// 터뜨리기
	auto it = l1.begin();
	
	while (l1.size() > 1) {


		int next = it->second;
		auto temp = it;

		if (next > 0) {
			// + 방향
			temp++;
			if (temp == l1.end())
				temp = l1.begin();
			cout << it->first << ' ';
			l1.erase(it);
			it = temp;
			for (i = 1; i < next; i++) {
				it++;
				if (it == l1.end())
					it = l1.begin();
			}
		}

		else {
			// - 방향
			if (temp == l1.begin())
				temp = l1.end();
			temp--;
			cout << it->first << ' ';
			l1.erase(it);
			it = temp;
			for (i = -1; i > next; i--) {
				if (it == l1.begin()) {
					it = l1.end();
				}
				it--;
			}

		}

	}
	cout << it->first << ' ';
}