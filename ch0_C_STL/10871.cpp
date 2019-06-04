#include <iostream>
using namespace std;
#pragma warning(disable:4996)
int main() {
	int N, x;
	cin >> N >> x;
	auto is_less = [&x](int number) {
		return number < x;
	};
	int a;
	while (N--) {
		cin >> a;
		if (is_less(a)) cout << a << ' ';
	}
	
}