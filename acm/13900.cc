#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
int N;
long long S[111111];
int A[111111];
int main() {
	int a;
	long long sum = 0;
	scanf("%d", &N);
	scanf("%d", &A[0]);
	S[0] = A[0];
	for (int i = 1; i < N; i++) {
		scanf("%d", &a);
		A[i] = a;
		S[i] += S[i-1]+a;		
	}

	for (int i = N - 1; i > 0; i--) {
		sum += A[i] * S[i - 1];
	}

	printf("%lld", sum);
	return 0;
}