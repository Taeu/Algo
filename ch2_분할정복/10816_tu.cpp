#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#pragma warning(disable:4996)

int v[500001];
pair<int, int> s[500001];

int find(int num, int size) {
	int left = 0;
	int right = size - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (left == right) {
			if (s[left].first == num)
				return s[left].second;
			else
				return 0;
		}
		if (s[mid].first == num)
			return s[mid].second;
		else if (s[mid].first > num) {
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
	for (int i = 0; i < n; i++) {
		int num;
		
		cin >> v[i];
	}
	sort(v, v + n);
	int cnt = 1;
	int j=0;
	for (int i = 0 ; i < n-1; i++) {
		
		if (v[i] == v[i + 1]) {
			cnt++;
		}
		else {
			s[j] = make_pair(v[i], cnt);
			cnt = 1;
			j++;
		}
	}
	s[j] = make_pair(v[n - 1], cnt);

	// check if works
	for(int i = 0 ; i<=j; i++)
		cout << s[i].first << ':' << s[i].second << '\n';
	

	int m;
	cin >> m;
	for(int i = 0; i<m; i++){
		int find_num;
		cin >> find_num;
		cout << find(find_num,j+1) << ' ';
	}

	return 0;
}