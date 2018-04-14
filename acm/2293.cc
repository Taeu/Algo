#include<stdio.h>
#include<algorithm>
#include<iostream>
int n, k;
int coin[111];
int sol[10001];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	sol[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int  j= 1; j <= k; j++) {
			if (j - coin[i] >= 0) {
				sol[j] += sol[j - coin[i]];
				
			}
		}
	}
	printf("%d", sol[k]);
	return 0;
}