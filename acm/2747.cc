#include<stdio.h>
#include<vector>
using namespace std;
int a[46];
int main() {
	a[1] = 1;
	for (int i = 2; i <= 45; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	int n;
	scanf("%d", &n);
	printf("%d", a[n]);
	return 0;
}