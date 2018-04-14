#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
using namespace std;
int main() {
	int A, B,a;
	set<int> s;
	scanf("%d%d", &A, &B);
	int n = A + B;
	for (int i = 0; i< n; i++) {
		scanf("%d", &a);
		s.insert(a);
	}
	printf("%d", n-2*(n-s.size()));
	return 0;
}