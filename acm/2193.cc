#include<stdio.h>
long long DP[91][2];
int main(){
int n;
scanf("%d",&n);
DP[1][0]=0;
DP[1][1]=1;
DP[2][0]=1;
DP[2][1]=0;
for(int i=3; i<=n; i++){
DP[i][0] = DP[i-1][0]+DP[i-1][1];
DP[i][1] = DP[i-1][0];
}
long long sum = DP[n][0]+DP[n][1];
printf("%lld",sum);
return 0;
}