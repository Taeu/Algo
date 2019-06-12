#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int num[5001];
int d[5001];
int main() {
	int i = 1;
	int mod = 1000000;
	while (scanf("%1d", &num[i]) == 1) {
		i++;
	}
	int length = i - 1;
	if (num[1] != 0)
		d[1] = 1;
	else
		d[1] = 0;
	int a;
	d[0] = 1;
	for (int i = 2; i <= length; i++) {
		if (num[i] != 0) {
			d[i] += d[i - 1];
			a = num[i - 1] * 10 + num[i];

			if (num[i - 1] != 0 && a <= 26)
				d[i] = (d[i] + d[i - 2]) % mod;
		}
		else {
			if (num[i - 1] == 1 || num[i - 1] == 2)
				d[i] += d[i - 2];
		}
	}
	printf("%d", d[length]);


	return 0;
}