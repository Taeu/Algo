#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)
int a[1001];
int dinc[1001];
int ddec[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dinc[i] = 1;
		ddec[i] = 1;
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && dinc[j] + 1 > dinc[i])
				dinc[i] = dinc[j] + 1;
		}
		for (int j = n; j >= i; j--) {
			for (int k = n; k > j; k--) {
				if (a[j] > a[k] && ddec[k] + 1 > ddec[j])
					ddec[j] = ddec[k] + 1;
			}
		}
		if (dinc[i] + ddec[i] > max)
			max = dinc[i] + ddec[i] -1;
		for (int j = i + 1; j <= n; j++) {
			ddec[j] = 1;
		}
	}
	
	cout << max;

	return 0;
}