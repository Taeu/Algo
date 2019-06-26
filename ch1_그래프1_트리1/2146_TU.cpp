#include<iostream>
#include<queue>
using namespace std;
#pragma warning(disable:4996)

int map[102][102];
int island_check[102][102];
int bridge[102][102];
int dir[4][2] = { {0,1},{0,-1} ,{1,0} ,{-1,0} };

void DFS(int start_x, int start_y, int num) {
	island_check[start_x][start_y] = num;
	for (int i = 0; i < 4; i++) {
		if (island_check[start_x + dir[i][0]][start_y + dir[i][1]] == 0 &&map[start_x+dir[i][0]][start_y+dir[i][1]]== 1)
			DFS(start_x + dir[i][0], start_y + dir[i][1], num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int island_id  = 0;
	// 섬 구분하기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (island_check[i][j] == 0 && map[i][j] == 1)
			{
				island_id++;
				DFS(i, j, island_id);
				
			}
		}
	}
	// 가장 가까운 다리 찾기
	queue<pair<int, int>> q1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (island_check[i][j] != 0)
				q1.push(make_pair(i, j));
		}
	}

	int point = 0;
	bool found = false;
	int ans =N*3;
	while (!q1.empty() && !found) {
		point++;
		int current_size = q1.size();
		pair<int, int> current;
		while (current_size--) {
			
			current = q1.front();
			q1.pop();
			for (int i = 0; i < 4; i++) {
				int next_x, next_y;
				next_x = current.first + dir[i][0];
				next_y = current.second + dir[i][1];
				if (next_x < 0) continue;
				if (next_x > N) continue;
				if (next_y < 0) continue;
				if (next_y > N) continue;
				if (island_check[next_x][next_y] == 0) {
					island_check[next_x][next_y] = island_check[current.first][current.second];
					bridge[next_x][next_y] = point;
					q1.push(make_pair(next_x,next_y));
				}
				else if (island_check[next_x][next_y] != island_check[current.first][current.second]) {
					found = true;
					if (bridge[next_x][next_y] == bridge[current.first][current.second]) {
						if (ans > bridge[next_x][next_y] * 2)
							ans = bridge[next_x][next_y]*2;

					}
					else {
						if (ans > point * 2 - 1) // (point-1) * 2 +1;
							ans = point * 2 - 1;
					}
					
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << bridge[i][j];
			}
			cout << '\n';
		}
		cout << '\n';
	}

	cout << ans;
	return 0;
}
