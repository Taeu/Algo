#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 102;
typedef pair <int, int> ii;
int input[N][N];
int visit[N][N]; //갔는지 안 갔는지 카운트, 한 턴 끝나고 다시 0으로 업데이트 필요
int cnt; // cnt 업뎃 필요
int idx[4] = { 1,-1,0,0 };
int idy[4] = { 0,0,1,-1 };

void bfs(ii start) {
	cnt++;
	queue <ii> q;
	q.push(start);
	visit[start.first][start.second] = 1;
	while (!q.empty()) {
		ii cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ii next = ii(cur.first + idx[i], cur.second + idy[i]);
			if (!visit[next.first][next.second]&&input[next.first][next.second]>0) {
				visit[next.first][next.second] = 1;
				q.push(next);
			}
		}
	}	
}

int main() {
	int a,b;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= a; j++) {
			scanf("%d", &b);
			input[i][j] = b;
		}
	}
	int max = 1;
	for (int x = 0; x < 100; x++) {
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				input[i][j]--;
			}
		}
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (!visit[i][j] && input[i][j] > 0)
					bfs(ii(i, j));
			}
		}
		if (max < cnt) max = cnt;
		cnt = 0;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				visit[i][j] = 0;
			}
		}

	}

	printf("%d", max);
	return 0;
}