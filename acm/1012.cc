#include<stdio.h>
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0, 1,-1 };
int A[50][50] = { 0 };
int C[50][50] = { 0 };
int cnt;int a, b, c;
void dfs(int x, int y);
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &a, &b, &c);
		while (c--) {
			int d, e;
			scanf("%d%d", &d, &e);
			A[e][d] = 1;
		}
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				if (!C[i][j] && A[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				A[i][j] = 0;
				C[i][j] = 0;
			}
		}
	}
	return 0;
}
void dfs(int x, int y) {
	C[x][y] = 1;
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < b &&nx>=0 && ny < a&&ny>=0) {
			if (!C[nx][ny] && A[nx][ny])
				dfs(nx,ny);
		}
		}
}