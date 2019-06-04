#include<stack>
#include<iostream>
#include<string>
using namespace std;

#pragma warning (disable:4996)

stack<int> ss;

void stack_c(string s) {
	if (s == "push") {
		int num;
		cin >> num;
		ss.push(num);
	}
	else if (s == "pop") {
		if (ss.empty())
			cout << -1 << '\n';
		else {
			cout << ss.top() << '\n';
			ss.pop();
		}
	}
	else if (s== "size"){
		cout << ss.size() << '\n';
	}
	else if (s == "empty") {
		if (ss.empty())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	else if (s == "top") {
		if (ss.empty())
			cout << -1 << '\n';
		else
			cout << ss.top() << '\n';
	}
}
int main() {

	int N;
	cin >> N;
	string s;
	while (N--) {
		cin >> s;
		stack_c(s);
	}


	return 0;
}