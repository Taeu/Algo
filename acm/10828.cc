#include<stdio.h>

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int n,pn;
	scanf("%d", &n);
	string s;
	stack<int> st;
	while (n--) {
		cin >> s;
		if (s == "push") {
			scanf("%d", &pn);
			st.push(pn);
		}
		else if (s == "pop") {
			if (!st.empty()) {
				printf("%d\n", st.top());
				st.pop();
			}
			else
				printf("-1\n");
		}
		else if (s == "size")
			printf("%d\n", st.size());
		else if (s == "empty")
			printf("%d\n", st.empty());
		else if (s == "top") {
			if (!st.empty()) 
				printf("%d\n", st.top());
			else printf("-1\n");
		}
	}
	
	return 0;
}

