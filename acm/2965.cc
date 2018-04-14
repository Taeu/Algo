#include<stdio.h>
int main() {
	int a, b, c, mx;
	scanf("%d%d%d", &a, &b, &c);
	if (b - a>c - b) mx = b - a;
	else mx = c - b;
	int cnt = 0;
	while (mx-->1) {
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}