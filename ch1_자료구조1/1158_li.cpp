#include<list>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	list<int> li;
	for (int i = 1; i <= n; i++)
		li.push_back(i);

	
	auto it = li.begin();
	cout << '<';
	while (n > 1) {
		int num;
		for (int i = 0; i < k-1; i++) {
			if (it == li.end())
				it = li.begin();
			it++;
			
		}
		if (it == li.end())
			it = li.begin();
		cout << *it << ", ";
		it = li.erase(it);
		n--;
	}
	cout << *li.begin() << '>';

	
	/*
	auto it = li.end();
	it = li.erase(--it);
	if (it == li.end()) cout << 't';
	for (auto x : li) {
		cout << x;
	}
	*/
	return 0;
}