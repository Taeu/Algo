#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int A[502][502];
int B[502][502];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int find11(int x, int y) {
	if (x == 1 && y == 1) return 1;
	int & ret = B[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!A[nx][ny]) continue;
		if (A[nx][ny] <= A[x][y]) continue;
		ret += find11(nx, ny);
	}
	return ret;
}
int main() {
	memset(B, -1, sizeof(B));
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("%d", find11(m, n));
	return 0;
}