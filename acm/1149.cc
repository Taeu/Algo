#include<stdio.h>

int a[4][1001];
int min(int a, int b) {
	if(a < b) return a;
	else return b;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[1][i], &a[2][i], &a[3][i]);
	}
	for (int i = 2; i <= n; i++) {
		a[1][i] += min(a[2][i - 1], a[3][i - 1]);
		a[2][i] += min(a[1][i - 1], a[3][i - 1]);
		a[3][i] += min(a[1][i - 1], a[2][i - 1]);
	}
	printf("%d", min(min(a[1][n], a[2][n]), a[3][n]));
	return 0;
}