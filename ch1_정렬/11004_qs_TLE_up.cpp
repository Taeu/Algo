#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable : 4996)
int v[5000000];
// https://en.wikipedia.org/wiki/Median_of_medians#Algorithm 이거 공부해보기
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	k -= 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	bool notFound = true;
	int start = 0;
	int end = n-1;
	while (notFound) {

		int left = start, right = end;
		int pivot_num = v[left];
		while (left <= right) {
			while (v[left] <= pivot_num)
				left++;
			while (v[right] > pivot_num)
				right--;
			if (left < right) {
				swap(v[left], v[right]);
				left++;
				right--;
			}
		}
		swap(v[start], v[right]);
		if (right == k) {
			cout << v[k];
			break;
		}
		else if (right > k) {
			end = right - 1;
		}
		else {
			start = right + 1;
		}
	}

	return 0;
}