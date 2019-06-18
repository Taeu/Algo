#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int v[5000000];
int n, k;

int quick_sort(int left, int right) {
	int start = left;
	int end = right;
	int pivot = (left + right) / 2;
	int pivot_value = v[pivot];
	while (left < right) {
		while (v[left] <= pivot_value && left< end) {
			left++;
		}
		while (v[right] >= pivot_value && right > start) {
			right--;
		}
		if (left < right) {
			swap(v[left], v[right]);
			left++;
			right--;
		}
	}
	if (right == end) {
		swap(v[pivot], v[right]);
		if (right == k)
			return v[k];
	}
	else 
		swap(v[pivot], v[right+1]);
	
	if (right+1 == k) {
		return v[k];
	}
	else if (right > k) {
		quick_sort(start, right);
	}
	else {
		quick_sort(right + 2, end);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	k = k - 1;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ans = quick_sort(0, n - 1);
	cout << ans;
	return 0;
}