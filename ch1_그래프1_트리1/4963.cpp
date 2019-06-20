#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int v[52][52];
int check[52][52];
int dir[8][2] = { {0,1},{0,-1},{1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1}};
vector<int> sum_house;
void BFS(int start_i, int start_j) {

	queue<pair<int,int>> q;
	check[start_i][start_j] = 1;
	q.push(make_pair(start_i,start_j));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			p.first += dir[i][0];
			p.second += dir[i][1];
			if (check[p.first][p.second] == 0 && v[p.first][p.second] == 1) {
				q.push(p);
				check[p.first][p.second] = 1;
			}
			p.first -= dir[i][0];
			p.second -= dir[i][1];
		}
	}

}

int main() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		for (int i = 1; i <= b; i++) {
			for (int j = 1; j <= a; j++) {
				scanf("%d", &v[i][j]);
				check[i][j] = 0;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= b; i++) {
			for (int j = 1; j <= a; j++) {
				if (check[i][j] == 0 && v[i][j] == 1) {
					cnt++;
					BFS(i, j);
				}
			}
		}
		printf("%d\n", cnt);

	}

	return 0;
}