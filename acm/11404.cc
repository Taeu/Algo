#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int CC[101][101];
// const int inf = 987654321;
void Floyd(int V){
	
		for (int k = 1; k <= V; k++){
			for (int i = 1; i <= V; i++){
				for (int j = 1; j <= V; j++){
					if (CC[i][k] && CC[k][j]){
						if (CC[i][j])
							CC[i][j] = min(CC[i][j], CC[i][k] + CC[k][j]);
						else CC[i][j] = CC[i][k] + CC[k][j];
					}
				}
			}
		}
	
}
int main(){
	int n,m;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (!CC[a][b] || (CC[a][b] && CC[a][b] > c)){
			CC[a][b] = c;
		}
		
	}
	Floyd(n);
	for (int i = 1; i<= n; i++){
		CC[i][i] = 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			printf("%d ", CC[i][j]);
		}
		printf("\n");
	}
	return 0;
}