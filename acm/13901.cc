#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int map[1002][1002];
int D;
typedef pair<int, int> ii;

vector<ii> v;
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};
int input[5];
int main() {
	int a, b; 
	int x, y, cx, cy;
	int n = 0, index;
	scanf("%d%d", &a, &b);
	scanf("%d", &D);
	
	for (int i = 1; i <= D; i++) {
		scanf("%d%d", &x, &y);
		map[x][y] = -1;
	}
	
	scanf("%d%d", &cx, &cy);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &input[i]);
	}
	v.push_back(ii(cx, cy));
	while (!v.empty()) {
		ii k = v.back();
		v.pop_back();
		cx = k.first;
		cy = k.second;
		map[cx][cy] = 1;
		index = input[n];
			if (dx[index] + cx >= 0 && dx[index] + cx < a && dy[index] + cy >= 0 && dy[index] + cy < b && map[dx[index] + cx][dy[index] + cy] == 0)
			{
					v.push_back(ii(dx[index] + cx, dy[index] + cy));

			}
			else {
				for (int i = 0; i < 3; i++) {
					n = (n + 1) % 4;
					index = input[n];
					if (dx[index] + cx >= 0 && dx[index] + cx < a && dy[index] + cy >= 0 && dy[index] + cy < b &&map[dx[index] + cx][dy[index] + cy] == 0)
						{
						v.push_back(ii(dx[index] + cx, dy[index] + cy));
						break;
						}
					}
			}
		}
	printf("%d %d", cx, cy);
	return 0;
}