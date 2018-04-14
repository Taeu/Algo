#include<stdio.h>
#include<math.h>
#pragma warning(disable :4996)
int cnt;
int isPrime(int);
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if (b >= 4&& a <= 4) cnt++;
	for (int i = 3; i <= sqrt(b); i=i+2) {
		if (i*i < a) continue;
		cnt += isPrime(i);
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