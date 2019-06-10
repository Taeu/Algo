#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int d[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	d[1] = 0;
	for (int i = 1; i <= 1000000; i++) {
		int a, b, c;
		a = i + 1;
		b = i * 2;
		c = i * 3;
		if (a <= 1000000)
			if (d[a] == 0 || d[a] > d[i] + 1)
				d[a] = d[i] + 1;
		if (b <= 1000000)
			if (d[b] == 0 || d[b] > d[i] +1)
				d[b] = d[i] + 1;
		if (c <= 1000000)
			if(d[c] == 0 || d[c] > d[i] + 1)
				d[c] = d[i] + 1;
	}
	int n;
	cin >> n;
	cout << d[n];

	return 0;
}