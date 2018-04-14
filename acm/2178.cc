#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int A[102][102];
int C[102][102];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
typedef pair<int, int> ii;
vector<ii> q;
vector<ii> chk;
int main() {
	int N, M;
	string s;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			A[i][j] = s[j - 1] - '0';
		}
	}
	
	int sol = 1, cnt = 0;
	q.push_back(ii(1, 1));
	cnt++;
	while (sol && !q.empty()) {
		while (!q.empty()) { 
			chk.push_back(q.back());
			q.pop_back();
		}
		cnt++;
		while (!chk.empty()) {
			ii ci = chk.back();
			chk.pop_back();
			if (ci.first == N&&ci.second == M) {
				sol = 0;
				break;
			}
			int ni, nj;
			for (int i = 0; i<4; i++) {
				ni = ci.first + dx[i];
				nj = ci.second + dy[i];
				if (!C[ni][nj] && A[ni][nj]) {
					C[ni][nj] = 1;
					q.push_back(ii(ni, nj));
				}
			}
		}

	}
	printf("%d", cnt-1);
	return 0;
}