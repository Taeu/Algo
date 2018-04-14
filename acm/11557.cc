#include<stdio.h>

#include<iostream>
#include <map>
#include<string>
using namespace std;

int main() {

	int tc;
	scanf("%d", &tc);
	map<string,int> mp;
	while (tc--) {
		mp.clear();
		int num;
		scanf("%d", &num);
		while (num--) {
			string s;
			int num2;
			cin >> s;
			scanf("%d", &num2);
			mp[s] += num2;

		}
		int maxx_cnt = -1000;
		string dab;

		for (map<string, int>::iterator it = mp.begin(); it != mp.end();it++) {
			if (it->second > maxx_cnt) {
				maxx_cnt = it->second;
				dab = it->first;

			}
		}
		cout << dab << endl;

	}
}

