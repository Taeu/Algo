#include<iostream>
#include<string>
using namespace std;

#pragma warning(disable:4996)

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	for (int i = 0; i<100; i++){
		getline(cin, s);
		if (s.length() == 0) break;
		int l = 0, u = 0, n = 0, sp = 0;
		for (char x : s) {
			if (x >= 'a' && x <= 'z') l+=1;
			else if (x >= 'A' && x <= 'Z') u+=1;
			else if (x >= '0' && x <= '9') n+=1;
			else if (x == ' ') sp+=1;
		}
		cout << l << ' ' << u << ' ' << n << ' ' << sp << '\n';

	}

	return 0;
}

// c++11 기준으로 짠 코드라 그런가?