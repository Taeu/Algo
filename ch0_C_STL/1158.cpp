#include<list>
#include<iostream>
using namespace std;

#pragma warning (disable:4996)
list<int> ll1;

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		ll1.push_back(i);
	}
	cout << '<';
	auto p = ll1.begin();
	while (N > 1) {
		for (int i = 0; i < K-1; i++) {
			++p;
			if (p == ll1.end())
				p = ll1.begin();
		}
		
		cout << *p << ", ";
		p = ll1.erase(p);
		if (p == ll1.end())
			p = ll1.begin();

		N--;
	}
	cout << ll1.front() << '>';
	return 0;
}