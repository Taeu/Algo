#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)
int A, B;
int Ato10(string a) {
	int num10 = 0;
	int mul = 1;
	for (int i = a.length() - 1; i >= 0; i--) {
		if (a[i] >= 'A')
			num10 = num10 + (a[i] - 'A' + 10)*mul;
		else
			num10 = num10 + (a[i] - '0')*mul;
		mul *= 10;
	}
	return num10;
}

string ten2B(int num10) {
	string b = "";
	int a;
	char c;
	do {
		a = (num10 % B);
		if (a >= 10)
			c = a - 10 + 'A';
		else
			c = a + '0';
		b = c + b;
		num10 /= B;
	} while (num10 != 0);
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B;
	int N;
	cin >> N;
	int mul = 1;
	for (int i = 1; i < N; i++) {
		mul *= A;
	}

	// A to 10;
	int num10 = 0;
	while (N--) {
		int n;
		cin >> n;
		num10 = num10 + n * mul;
		mul /= A;
	}
	// 10 to B
	string b = "";
	int a;
	do {
		a = (num10 % B);
		b = to_string(a) + ' ' + b;
		num10 /= B;
	} while (num10 != 0);

	cout << b;

	return 0;
}