#include<stdio.h>
#include<math.h>
#pragma warning(disable :4996)
int cnt;
int isPrime(int);
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = 2; i <= sqrt(b); i++) {
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
	int a = num / 2;
	for (int i = 2; i <= a; i++) {
		if (num%i == 0) return 0;
	}
	return 1;
}