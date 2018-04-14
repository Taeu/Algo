#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
int T, n;
int main() {
	char c;
	int num;
	for (scanf("%d", &T); T--;) {
		multiset<int> ms;
		for (scanf("%d", &n); n--;) {
			scanf("%c%d", &c, &num);
			if (c == "I") ms.insert(num);
			else if (!ms.empty()) num < 0 ? ms.erase(ms.begin()) : ms.erase(ms.end());

		}
		if (!ms.empty()) for (int i = 0; i < ms.size(); i++) pritnf("%d ", ms[i]);
		else printf("EMPTY");
		pritnf("\n");
	}


}