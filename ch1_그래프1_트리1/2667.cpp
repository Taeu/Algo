#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int v[27][27];
int check[27][27];
int dir[4][2] = { {1,0},{-1,0},{0,1}, {0, -1} };
vector<int> sum_house;
int BFS(int start_i, int start_j) {
	int sum = 0;
	queue<pair<int,int>> q;
	check[start_i][start_j] = 1;
	q.push(make_pair(start_i,start_j));
	sum++;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			p.first += dir[i][0];
			p.second += dir[i][1];
			if (check[p.first][p.second] == 0 && v[p.first][p.second] == 1) {
				sum++;
				q.push(p);
				check[p.first][p.second] = 1;
			}
			p.first -= dir[i][0];
			p.second -= dir[i][1];
		}
	}
	return sum;

}

int main() {

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for(int j= 1; j<=N; j++)
			scanf("%1d", &v[i][j]);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (check[i][j] == 0 && v[i][j] == 1) {
				cnt++;
				sum_house.push_back(BFS(i, j));
			}
		}
	}
	printf("%d\n", cnt);
	sort(sum_house.begin(), sum_house.end());
	for (int x : sum_house)
		printf("%d\n", x);

	return 0;
}