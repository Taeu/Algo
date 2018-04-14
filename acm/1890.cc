#include<stdio.h>
#include<vector>

int A[102][102];
long long B[102][102];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	B[n][n] = 1;
	for (int i = n + n-1; i >= 2; i--) {
		for (int st = i, y = n; y >= 1; y--) {
			int x = st - y;
			int ln = A[x][y];
			if (x <= 0) continue;
			else if (x>n) break;
			else {
				if (x + ln <= n)
					B[x][y] += B[x + ln][y];
				if (y + ln <= n)
					B[x][y] += B[x][y + ln];
			}
		}
	}
	printf("%lld", B[1][1]);
	return 0;
}