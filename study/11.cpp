#include<stdio.h>
int main() {
	int a, n, max1, max2;
	scanf("%d", &n);
	scanf("%d", &max1);
	scanf("%d", &a);
	if (max1 < a) {
		max2 = max1; max1 = a;
	}
	else max2 = a;
	n -= 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (max1 < a)
		{
			max2 = max1; max1 = a;
		}
		else if (max2 < a) max2 = a;
	}
	printf("%d %d", max1, max2);
	return 0;
}