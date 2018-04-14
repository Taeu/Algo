#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;

int map[1002][1002];
int D;
typedef pair<int, int> ii;

vector<ii> v;
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};

int N, M;
int wok[1111];
int S[11111];
// 주문 처리할 수 없는경우 -1 출력
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &wok[i]);
		S[wok[i]] = 1;
	}
	sort(wok.begin(), wok.end());
	for (int i = 0; i < N; i++) {
		if (S[i] == 0) S[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - sok[j] <= 0 || S[i-sok[j]]==-1) break;
			
			S[i] = min(S[i], S[i - sok[j]]+1);
		}
	}
	
	printf("%d", S[M]);



	return 0;
}