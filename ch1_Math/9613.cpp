#include<iostream>
#include<vector>
#include<set>
using namespace std;
#pragma	warning(disable:4996)

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	vector <int> v;
	while (t--) {
		int n,num;
		cin >> n;
		while (n--) {
			cin >> num;
			v.push_back(num);
		}
		long long ans = 0LL;
		for (int i = 0; i < v.size()-1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				ans += gcd(v[i], v[j]);
			}
		}
		cout << ans << '\n';
		ans = 0LL;
		v.clear();
	}


	return 0;
}