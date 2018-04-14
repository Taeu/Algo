#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1000000000;
int d[101][1LL << 10][10];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 9; i++)
		d[1][1LL << i][i] = 1;
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < (1LL << 10); ++j){
			for (int a = 0; a <= 9; ++a){
				if (a + 1 < 10)
					d[i + 1][j | (1LL << a)][a] = (d[i + 1][j | (1LL << a)][a]+ d[i][j][a + 1]) % N;
				if (a - 1 >= 0)
					d[i + 1][j | (1LL << a)][a] = (d[i + 1][j | (1LL << a)][a]+ d[i][j][a - 1]) % N;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++)
		sum = (sum+ d[n][1023][i])%N;
	printf("%d", sum);
	return 0;
}