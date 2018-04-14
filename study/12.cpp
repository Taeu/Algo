#include<stdio.h>
#pragma warning(disable :4996)
int L[100];
int main() {
	int n,a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &L[i]);
	}
	//sort
	int temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (L[i] < L[j]) {
				temp = L[j];
				L[j] = L[i];
				L[i] = temp;
			}
		}
	}
	//print
	for (int i = 0; i < 8; i++) {
		printf("%d ", L[i]);
	}
	return 0;
}