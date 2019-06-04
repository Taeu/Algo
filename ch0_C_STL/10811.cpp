#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#pragma waring(disable:4996)

void print(vector<int> a) {
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';
}
int main() {
	vector<int> a = { 0, 1, 2, 3, 4, 5 };
	for (int i = 0; i < a.size(); i++) {
		rotate(a.begin(), a.begin() + 1, a.end());
		print(a);
	}
}