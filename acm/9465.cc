#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int T, n;
int score[2][100001];
int sol[2][100001];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				scanf("%d", &score[j][i]);
			}
		}
		sol[0][0] = score[0][0];
		sol[1][0] = score[1][0];
		sol[0][1] = sol[1][0] + score[0][1];
		sol[1][1] = sol[0][0] + score[1][1];
		for (int i = 2; i < n; i++) {
			sol[0][i] = max(sol[1][i-1],sol[1][i-2] )+score[0][i];
			sol[1][i] = max(sol[0][i-1],sol[0][i-2] )+score[1][i];
		}
		printf("%d\n", max(sol[0][n-1], sol[1][n-1]));
	}
	return 0;
}