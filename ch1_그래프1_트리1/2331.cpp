#include<vector>
#include<queue>	
#include<iostream>
using namespace std;
#pragma warning(disable:4996)

vector<int> check(300000);
int p;
int cnt=1;
int mul(int num) {
	int mult = num;
	for (int i = 1; i < p; i++) {
		num *= mult;
	}
	return num;
}

int DFS(int current) {
	check[current] = cnt;
	int sum = 0;
	do {
		sum += mul(current % 10);
		current /= 10;
	} while (current != 0);
	if (check[sum] == 0) {
		cnt++;
		DFS(sum);
	}
	else {
		return check[sum];
	}
}

int main() {
	int n;
	cin >> n >> p;
	cout << DFS(n)-1;
	return 0;
}