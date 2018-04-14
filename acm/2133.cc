#include<stdio.h>
int D[32][5] = {0};
int P[32][5] = {0};
int DP[32] ={0};
int main(){
	int n;
	scanf("%d",&n);
	DP[1]=0;DP[2]=3;
	P[1][0] =1;
	P[1][1] =1;
	P[2][2] =1;
	P[2][3] =1;
	P[1][4] =1;
	P[2][4] =0;
	for(int i =3; i<=31; i++){
		P[i][4] += P[i-1][3]+P[i-1][2]+P[i-2][4];
		P[i][0] += P[i][4]+P[i-1][3];
		P[i][1] += P[i][4]+P[i-1][2];
		P[i][2] += P[i-1][1];
		P[i][3] += P[i-1][0];
		
	}
	for(int i =3; i<=30; i++){
		DP[i] += P[i+1][4];
	}
	printf("%d",DP[n]);
	return 0;
}