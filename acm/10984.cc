#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;


int main() {
	int T, N, C, sum_c = 0;
	double G, sum_g = 0;
	scanf("%d", &T);
	for (int i = 0; i<T; i++) {
		scanf("%d", &N);
		for (int j = 0; j<N; j++) {
			scanf("%d%lf", &C, &G);
			sum_c += C;
			sum_g += G*C;
		}
		printf("%d %.1lf\n", sum_c, sum_g / sum_c); // 반올림 되는지 확인하기
		sum_c = 0;
		sum_g = 0;
	}


	
	return 0;
}