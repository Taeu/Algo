#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int x, y;
vector<int> v[101];
vector<int> vv;
vector<int> vch;
int chk[101], cnt,found;
int main() {
	int n;
	int p, c;
	scanf("%d%d%d%d", &N ,&x, &y,&n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d",&p,&c);
		v[p].push_back(c);
		v[c].push_back(p);
	}
	chk[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		vv.push_back(v[x][i]);
	while (!found && !vv.empty()) {
		while (!vv.empty()) {
			vch.push_back(vv.back());
			vv.pop_back();
		}
		cnt++;
		while (!vch.empty()) {
			int ni = vch.back();
			vch.pop_back();
			if (!chk[ni]) {
				chk[ni] = 1;
				if (ni == y) {
					printf("%d", cnt);
					vv.clear();
					vch.clear();
					found = 1;
					break;
				}
				else {
					for (int i = 0; i < v[ni].size(); i++)
						vv.push_back(v[ni][i]);
				}
			}
		}
	}
	if (!found) {
		printf("-1");
	}
	return 0;
}