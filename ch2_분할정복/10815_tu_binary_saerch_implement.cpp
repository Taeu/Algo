#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#pragma warning(disable:4996)

int v[500001];
int find(int num, int size) {
	int left = 0;
	int right = size - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (left == right) {
			if (v[left] == num)
				return 1;
			else
				return 0;
		}
		if (v[mid] == num)
			return 1;
		else if (v[mid] > num) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

	}
	return 0;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v, v + n);
	int m;
	cin >> m;
	for(int i = 0; i<m; i++){
		int find_num;
		cin >> find_num;
		cout << find(find_num,n) << ' ';
	}

	return 0;
}