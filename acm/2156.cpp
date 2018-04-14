#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int podo[11111];
int sol[11111][3];
int N;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &podo[i]);
	}
	sol[1][0] = 0;
	sol[1][1] = podo[1];
	sol[1][2] = 0;
	for (int i = 2; i <= N; i++) {
		sol[i][0] = max(sol[i - 1][0], max(sol[i - 1][1], sol[i - 1][2]));
		sol[i][1] = sol[i - 1][0] + podo[i];
		sol[i][2] = sol[i - 1][1] + podo[i];
	}
	printf("%d", max(sol[N][0], max(sol[N][1], sol[N][2])));
	return 0;
}