#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	k = k - 1;
	bool notFound = true;
	int first = 0;
	int i = 0, j = n - 1;
	while (notFound) {
		int start = i;
		int end = j;
		while (i < j) {
			while (v[i] <= v[first]) {
				i++;
				if (i > end) break;
			}
			while (v[j] > v[first]) {
				j--;
			}
			if (i <= j) { //in fact, never happen if i == j
				swap(v[i], v[j]);
				if (i != end)
					i++;
				if (j != start)
					j--;
			}
		}
		swap(v[j], v[first]);

		if (j == k) {
			cout << v[j];
			notFound = false;
		}
		else if (j > k) {
			j = j - 1;
			i = start;
			first = start;
		}
		else {
			i = j + 1;
			first = i;
			j = end;
		}
	}

	return 0;
}