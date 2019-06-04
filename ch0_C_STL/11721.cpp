#include <stdio.h>
#pragma warning(disable:4996)
char s[100];
int main() {
	while (scanf("%10s", s) == 1) {
		printf("%s\n", s);
	}

	return 0;
}