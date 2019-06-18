#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int cnt[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int num;
	while (n--) {
		cin >> num;
		cnt[num]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] != 0) {
			for (int j = 1; j <= cnt[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}