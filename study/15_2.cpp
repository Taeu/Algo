#include<stdio.h>
#include<math.h>
//#pragma warning(disable :4996)
int cnt;
long long prime[100001], a, b;
int chk[10000001];
int main() {
	// prime
	for (long long i = 2; i <= 10000000; i++) {
		if (chk[i] == 0) {
			prime[cnt++] = i;
			for (long long j = i*i; j <= 10000000; j += i) chk[j] = 1;
		}
	}
	// que
	int q, c, d;
	int ans = 0;
	scanf("%d", &q);
	while (q--) {
		scanf("%lld%lld", &a, &b);
		c = ceil(sqrt(a));
		d = sqrt(b);
		for (int i = 0; i < cnt; i++) {
			if (prime[i] >= c && prime[i] <= d) ans++;
		}
		if (a == 1 || a == 2) ans--;
		printf("%d\n", ans);
		ans = 0;
	}


	return 0;
}