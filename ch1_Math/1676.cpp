#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int zerosum = n / 5 + n / 25 + n / 125;
	cout << zerosum;
	return 0;
}