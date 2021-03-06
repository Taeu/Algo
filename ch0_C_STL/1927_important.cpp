#include<vector>
#include<iostream>
#include<queue>
using namespace std;

#pragma warning (disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N,num;
	cin >> N;
	priority_queue<int> q1;
	while (N--) {
		cin >> num;
		if (num == 0) {
			if (q1.empty())
				cout << 0 << '\n';
			else {
				cout << -q1.top() << '\n';
				q1.pop();
			}
		}
		else
			q1.push(-num);

	}
	return 0;
}