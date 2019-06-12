#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int d[5002][3];
int num[5002];
int mod = 1000000;
int length;
int go(int i) {

	if (d[i][1] == 1) {
		if (d[i][2] == 1) {
			if (i + 1 == length)
				return go(i + 1) + 1;
			return (go(i + 1) + go(i + 2))%mod;
		}
		if (length == i)
			return 1;
		return go(i + 1);
	}
	else if (d[i][2] == 1) {
		return go(i + 2);
	}
	else
		return 0;
	
}
int main() {
	int i = 1;
	while (scanf("%1d", &num[i]) == 1) {
		i++;
	}
	length = i - 1;

	int a1, b2;
	for (i = 1; i < length; i++) {
		a1 = num[i];
		b2 = a1 * 10 + num[i + 1];
		if (a1 != 0) {
			d[i][1] = 1;
			if (b2 <= 26)
				d[i][2] = 1;
		}
	}
	if(num[i] != 0)
		d[i][1] = 1;
	int ans = go(1);
	printf("%d", ans);

	return 0;
}
