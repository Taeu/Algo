#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> pp;
vector <pp> e;

int par[1001];
int Find(int x) {
	return (par[x] != x) ? par[x] = Find(par[x]) : x;
}
int Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) {
		if (a == -1) {
			par[b] = a;
		}
		else
			par[a] = b;
		return 1;
	}
	return 0;
}
int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
		par[i] = i;
	for (int i = 0; i<K; i++) {
		int a;
		scanf("%d", &a);
		par[a] = -1;
	}
	for (int i = 0; i<M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		e.push_back(pp(ii(c, a), b));
	}
	sort(e.begin(), e.end());

	int ans = 0;
	for (int i = 0; i<M; i++) {

		int c = e[i].first.first;
		int a = e[i].first.second;
		int b = e[i].second;
		if (Union(a, b)) {
			ans += c;
		}
	}
	printf("%d", ans);
	return 0;

}