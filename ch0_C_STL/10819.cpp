#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int sum = 0, max = 0;

	do {
		for (int i = 0; i < N-1; i++) {
			sum += abs(v[i + 1] - v[i]);
		}
		if (sum > max) {
			max = sum;
		}
		sum = 0;
	} while (next_permutation(v.begin(), v.end()));

	cout << max;

	return 0;
}