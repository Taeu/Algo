#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//typedef pair<int, int> ii;
vector <int> V[1001];
int vd[1001];
int vb[1001];

void dfs(int x){
	vd[x] = 1;
	printf("%d", x);
	for (int i = 0; i < V[x].size(); i++){
		int u = V[x][i];
		if (!vd[u]){
			printf(" ");
			dfs(u);
		}
	}
}
void bfs(int x){
	queue <int> q;
	q.push(x);
	vb[x] = 1;
	printf("%d", x);
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i = 0; i < V[cur].size(); i++){
			int u = V[cur][i];
			if (!vb[u]){
				vb[u] = 1;
				printf(" %d", u);
				q.push(u);
			}
		}
	}
}
int main(){
	int m, n, v;
	int a, b;
	scanf("%d%d%d", &m, &n, &v);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 0; i < 1001; i++){
		if (V[i].size())
		sort(V[i].begin(), V[i].end());
	}
	dfs(v);
	printf("\n");
	bfs(v);
	return 0;
}