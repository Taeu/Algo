#include<algorithm>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)
int d[31];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	d[0] = 1;
	for (int i = 2; i <= n; i = i + 2) {
		for (int j = 2; j <= i; j = j+ 2) {
			if (j==2)
				d[i] += d[i-j] * 3;
			else
				d[i] += d[i-j] * 2;

		}
	}
	cout << d[n];


	return 0;
}