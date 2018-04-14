#include<stdio.h>
int main() {
	int a, max;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a);
		if (i == 0) {
			max = a; continue;
		}
		if (a > max) max = a;
	}
	printf("%d", max);
	return 0;
}