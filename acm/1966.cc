#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair <int, int> ii;
int main() {
	int N;
	scanf("%d", &N);
	int n, idx,pr;
	deque<ii> que;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &n, &idx);
		for (int j = 0; j < n; j++) {
			scanf("%d", &pr);
			que.push_back(ii(pr, j));
		}
		int cnt = 0, mx;
		while (!que.empty()) {
			int z = que.size();
			//find mx
			mx = 0;
			for (int x = 0; x < z; x++)
				if (mx < que[x].first) mx = que[x].first;
			//pop cnt	
			for (int x = 0; x < z; x++) {
				if (que[0].first == mx) {
					if (que[0].second == idx) {
						printf("%d\n", ++cnt); que.clear(); break;
					}
					que.pop_front();
					cnt++;
					break;
				}
				else {
					que.push_back(ii(que[0].first, que[0].second));
					que.pop_front();
				}
			}
		}
	}
	return 0;
}
