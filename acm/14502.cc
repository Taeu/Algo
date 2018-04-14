#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef pair <int, int> ii;
const int N = 10;
//int input[N][N];
int visit[N][N];

int idx[4] = { -1,1,0,0 };
int idy[4] = { 0,0,1,-1 };
int a, b;
int bfs(queue<ii> q, int l) {
	int cnt = 0;
	while (!q.empty()) {
		ii cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ii next = ii(cur.first + idx[i], cur.second + idy[i]);
			if (next.first < 0 || next.first >= a || next.second < 0 || next.second >= b) continue;
			if (visit[next.first][next.second] != -1 && visit[next.first][next.second] != l) {
				visit[next.first][next.second] = l;
				cnt++;
				q.push(ii(next.first, next.second));
			}
		}
	}

	return cnt;
}

int main() {
	int in;
	int base = 0;
	queue <ii> que;
	scanf("%d%d", &a, &b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &in);
			if (in == 1) {
				visit[i][j] = -1;
			}
			else if (in == 2) {
				visit[i][j] = -1;
				que.push(ii(i, j));
			}
			else {
				visit[i][j] = 0;
				base++;
			}
		}
	}
	int l = 1;
	int ans = 0, max = 0;

	for (int i = 0; i < a*b; i++) {
		for (int j = i + 1; j < a*b; j++) {
			for (int k = j + 1; k < a*b; k++) {
				ii x = ii(i / b, i%b);
				ii y = ii(j / b, j%b);
				ii z = ii(k / b, k%b);
				if ((visit[x.first][x.second] + 1) * (visit[y.first][y.second] + 1) * (visit[z.first][z.second] + 1) == 0) continue;
				visit[x.first][x.second] = visit[y.first][y.second] = visit[z.first][z.second] = -1;

				ans = base - bfs(que, l++) - 3;
				if (ans > max) max = ans;

				visit[x.first][x.second] = visit[y.first][y.second] = visit[z.first][z.second] = 0;


			}
		}
	}
	printf("%d", max);
	return 0;
}
