#include<stdio.h>
#include<math.h>
#pragma warning(disable :4996)
int cnt;
int isPrime(int);
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int c = ceil(sqrt(a));
	int d = sqrt(b);
	for (int i = c; i <= d; i++) {
		if (i & 1) {
			cnt += isPrime(i);
		}
		else {
			if (i == 2) cnt++;
			continue;
		}
	}
	printf("%d", cnt);
	return 0;
}

int isPrime(int num) {
	if (num == 1) return 0;
	int a = num / 2;
	for (int i = 2; i <= a; i++) {
		if (num%i == 0) return 0;
	}
	return 1;
}