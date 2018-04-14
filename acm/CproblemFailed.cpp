#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;

vector<int> wok;

int N, M;
int S[11111];
// 주문 처리할 수 없는경우 -1 출력
int main() {
	int a;
	long long sum = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		S[a] = 1;
		wok.push_back(a);
	
	}


	sort(wok.begin(), wok.end());
	for (int i = 0; i < M-1; i++) {
		for (int j = i + 1; j < M; j++) {
			}
	}

	for (int i = 0; i <= N; i++) {
		if (S[i] == 0) S[i] = -1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - wok[j] <= 0 ) break;
			if (S[i - wok[j]] == -1) continue;
			if (S[i] == -1) S[i] = S[i - wok[j]] + 1;
			else S[i] = min(S[i], S[i - wok[j]] + 1);
		}
	}

	printf("%d", S[N]);



	return 0;
}