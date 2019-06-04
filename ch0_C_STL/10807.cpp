#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	vector<int> a;
	cin >> N;
	int num;
	while (N--) {
		
		cin >> num;
		a.push_back(num);
	}
	cin >> num;
	num = count(a.begin(), a.end(), num);
	cout << num;
	return 0;
}