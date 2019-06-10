#include<iostream>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)
int d[100001][2];
int s[100001][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int k;
	while (n--) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> d[i][0];
		}
		for (int i = 1; i <= k; i++) {
			cin >> d[i][1];
		}
		s[1][0] = d[1][0];
		s[1][1] = d[1][1];
		s[2][0] = d[2][0] + d[1][1];
		s[2][1] = d[2][1] + d[1][0];
		for (int i = 3; i <= k; i++) {
			s[i][0] = max(s[i-1][1],s[i-2][1])+d[i][0];
			s[i][1] = max(s[i - 1][0], s[i - 2][0])+d[i][1];
		}
	
		cout << max(s[k][0], s[k][1]) << '\n';
	}
	
	return 0;
}