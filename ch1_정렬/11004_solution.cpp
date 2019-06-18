#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable : 4996)
int v[5000000];
// https://en.wikipedia.org/wiki/Median_of_medians#Algorithm 이거 공부해보기
// https://www.acmicpc.net/source/12995642
// medium 으로 하면 되는 것 같네..;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	k -= 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	nth_element(v, v + k, v + n);
	cout << v[k];
	return 0;
}