#include<stdio.h>
#include<vector>
using namespace std;

int N, S, sum;
int cnt;
vector<int> v;
void nCn(int st, int num);
int main() {
	int n;
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j<=N - i; j++) {
			nCn(j, i);
		}
	}
	printf("%d", cnt);
	return 0;
}
void nCn(int st, int num) {
	sum += v[st];
	num--;
	if (num == 0) {
		if (sum == S) {
			cnt++;
		}
		sum -= v[st];
	}
	else {
		for (int i = st + 1; i <= N - num; i++) {
			nCn(i, num);
		}
		sum -= v[st];
	}
}