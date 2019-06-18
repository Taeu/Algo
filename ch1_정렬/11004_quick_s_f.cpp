#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	k = k - 1;

	bool notFound = true;
	int first = 0;
	int i = 1, j = n - 1;
	while (notFound) {
		while (i <= j) {
			if (v[i] <= v[first]) {
				i++;
				continue;
			}
			else {
				while (i <= j) {
					if (v[j] > v[first]) {
						j--;
						continue;
					}
					else {
						swap(v[i], v[j]);
						break;
					}

				}
			}
		}
		swap(v[first], v[j]);
		if (j == k) {
			cout << v[j];
			notFound = false;
		}
		else if (j > k) {
			
			j = j - 1;
			i = 1;
			first = 0;
		}
		else {
			i = j + 1;
			j = n - 1;
			first = j + 1;
		}
	}




	return 0;
}