#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)
int d[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= 316; i++) {
		d[i*i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 316; j++) {
			int a = j * j;
			if (i < a) break;
			if (d[i - a] != 0) {
				if (d[i] == 0 || d[i-a] + 1 < d[i])
					d[i] = d[i - a] + 1;
			}
		}
	}

	cout << d[n];


	return 0;
}