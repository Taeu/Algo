#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {
		printf("%d\n", a + b);
	}


	return 0;
}