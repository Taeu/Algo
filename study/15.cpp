#include<stdio.h>
#include<math.h>
#pragma warning(disable :4996)
int cnt;
long long prime[700001], a, b;
int chk[10000001];
int bs_c(long long num);
int bs_d(long long num);
int main() {
	// prime
	for (long long i = 2; i <= 10000000; i++) {
		if (chk[i] == 0) {
			prime[cnt++] = i;
			for (long long j = i*i; j <= 10000000; j += i) chk[j] = 1;
		}
	}
	// ques
	int q, c, d, e, f;
	int ans = 0;
	scanf("%d", &q);
	while (q--) {
		scanf("%lld%lld", &a, &b);
		c = ceil(sqrt(a));
		d = sqrt(b);
		e = bs_c(c); //index
		f = bs_d(d); //index

		ans = f - e + 1;
		if (c == 1 && d == 1) ans = 0;
		if (e > f) ans = 0;
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}
int bs_c(long long num) {
	int f = 0, l = 664578;
	int m = (f + l) / 2;
	while (f <= l) {
		if (prime[m] < num) f = m + 1;
		else {
			// chk sol.
			if (m == 0) return m;
			if (prime[m - 1] < num) return m;
			else l = m - 1;
		}
		m = (f + l) / 2;
	}
}
int bs_d(long long num) {
	int f = 0, l = 664578;
	int m = (f + l) / 2;
	while (f <= l) {
		if (prime[m] > num) l = m - 1;
		else {
			// chk sol.
			if (m == l) return l;
			if (prime[m + 1] > num) return m;
			else f = m + 1;
		}
		m = (f + l) / 2;
	}
}