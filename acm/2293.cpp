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
		sol[coin[i]] = 1;
	}
	sol[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int  j= 0; j <= n; j++) {
			if (i-coin[j]>=0){
				if(sol[i]!=0&&sol[i-coin[j]]!=0)
					sol[i] = min(sol[i], sol[i - coin[j]] + 1);
				else if ((sol[i] == 0 && sol[i - coin[j]] != 0)||( sol[i] == 0 && i - coin[j] == 0)) {
					else sol[i] = sol[i - coin[j]] + 1;
				}
			}
		}
	}
	if (sol[k] == 0) printf("-1");
	else
	printf("%d", sol[k]);
	return 0;
}