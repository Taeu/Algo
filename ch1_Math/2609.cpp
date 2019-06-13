#include<iostream>

using namespace std;

#pragma warning(disable:4996)
int gcd(int a, int b){
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}	
}

int gcd2(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << gcd2(a, b) << '\n';
	cout << a * b / gcd2(a, b) << '\n';

	return 0;
}