#include<stdio.h>
#include<vector>
using namespace std;
typedef pair<int, int> ii;
vector<ii> v;
vector<ii> chk;
int N, M;
int A[1002][1002];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int day, total;
int mx;
void solve(void);
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i <= N + 1; i++)
		A[0][i] = 1;
	for (int i = 0; i <= N + 1; i++)
		A[M + 1][i] = 1;
	for (int i = 0; i <= M + 1; i++)
		A[i][0] = 1;
	for (int i = 0; i <= M + 1; i++)
		A[i][N + 1] = 1;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	mx = M*N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == 1) {
				v.push_back(ii(i, j));
				total++;
			}
			else if (A[i][j] == -1)
				mx--;
		}
	}
	while (!v.empty()) {
			solve();
		}
	if (mx == total)
		printf("%d", day-1);
	else
		printf("-1");
	return 0;
}
void solve(void) {
	while (!v.empty()) {
		chk.push_back(v.back());
		v.pop_back();
	}
	day++;
	while (!chk.empty()) {
		ii ni = chk.back();
		chk.pop_back();
		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = ni.first + dx[i];
			ny = ni.second + dy[i];
			if (A[nx][ny]==0) {
				A[nx][ny]=1;
				v.push_back(ii(nx, ny));
				total++;
			}
		}
	}
}