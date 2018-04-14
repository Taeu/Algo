#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int score[333];
int sol[333][3];
int N;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &score[i]);
	sol[1][1] = score[1];
	sol[2][1] = score[2];
	for (int i = 2; i <= N+2; i++) {
		sol[i][1] = sol[i - 2][1]+score[i];
		sol[i][2] = sol[i - 1][1]+score[i];
		sol[i][1] = max( sol[i - 2][1], sol[i - 2][2])+score[i];
	}
	printf("%d", max(sol[N][0], max(sol[N][1], sol[N][2])));
	return 0;
}