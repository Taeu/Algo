#include <set>
#include <iostream>
using namespace std;
# pragma warning (disable : 4996)

set<int> s;
int main() {
	int N, num;
	cin >> N;
	while (N--) {
		cin >> num;
		s.insert(num);
	}

	for (int x : s)
		cout << x << ' ';

	return 0;
}