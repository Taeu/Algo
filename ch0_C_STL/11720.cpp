#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int N, x, sum=0;
	scanf("%d", &N);
	while (N--) {
		scanf("%1d", &x);
		sum += x;
	}
	printf("%d", sum);

	return 0;
}