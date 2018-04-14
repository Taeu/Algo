#include<stdio.h>
#pragma warning(disable :4996)

int main() {
	int n,a,even=0,pot=0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		if (a & 1);
		else even++;
		while (a) {
			if (a & 1 == 1) {
				if (a == 1) pot++;
				else break;
			}
			a= a >> 1;
		}
	}
	printf("%d\n%d", even, pot);
	return 0;
}