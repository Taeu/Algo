#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n, k;
int coin[100];
int sol[10001];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
		sol[coin[i]] = 1;
	}
	sol[0] = 0;
	int a, b;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			if (i - coin[j] >= 0) {
				a = sol[i];
				b = sol[i - coin[j]];
				if (a != 0 && b != 0)
					sol[i] = min(a, b + 1);
				else if ((a == 0 && b != 0) || (a == 0 && i - coin[j] == 0)) {
					 sol[i] = b + 1;
				}
			}
		}
	}
	if (sol[k] == 0) printf("-1");
	else
		printf("%d", sol[k]);
	return 0;
}