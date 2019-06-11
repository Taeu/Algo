#include<algorithm>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)
long long d[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;
	for (int i = 6; i <= 101; i++) {
		d[i] = d[i - 1] + d[i - 5];
	}
	while (n--) {
		int num;
		cin >> num;
		cout << d[num] << '\n';
	}
	

	return 0;
}