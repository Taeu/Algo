#include<stdio.h>

#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
	int n,pn;
	scanf("%d", &n);
	string s;
	queue<int> q;
	while (n--) {
		cin >> s;
		if (s == "push") {
			scanf("%d", &pn);
			q.push(pn);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop();
			}
			else
				printf("-1\n");
		}
		else if (s == "size")
			printf("%d\n", q.size());
		else if (s == "empty")
			printf("%d\n", q.empty());
		else if (s == "front") {
			if (!q.empty()) 
				printf("%d\n", q.front());
			else printf("-1\n");
		}
		else if (s == "back") {
			if (!q.empty())
				printf("%d\n", q.back());
			else printf("-1\n");
		}
	}
	
	return 0;
}

