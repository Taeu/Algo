#include<stdio.h>
#include<algorithm>
using namespace std;
int A[502][502];
int B[502][502];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
void find(int x, int y) {
	int j;
	for (j = 0; j<4; j++) {
		int nx = x + dx[j], ny = y + dy[j];
		if (A[x][y]<A[nx][ny]) break;
	}
	if (j == 4) {
		B[x][y] = 1;
		return;
	}
	int & mx = B[x][y];
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!A[nx][ny]) continue;
		if (A[x][y] >= A[nx][ny]) continue;
		if (B[nx][ny] == 0) find(nx, ny);
		mx = max(B[x][y], B[nx][ny] + 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(!B[i][j])find(i, j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mx = max(mx, B[i][j]);
		}
	}
	printf("%d", mx);
	return 0;
}