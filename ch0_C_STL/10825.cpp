#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#pragma warning(disable:4996)
struct student {
	string s;
	int K, E, M;
};
bool cmp(const student &s1, const student &s2) {
	if (s1.K == s2.K) {
		if (s1.E == s2.E) {
			if (s1.M == s2.M) {
				return s1.s < s2.s;
			}
			else
				return s1.M > s2.M;
		}
		else
			return s1.E < s2.E;
	}
	else
		return s1.K > s2.K;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<student> v(N);
	int i = 0;
	while (N--) {
		string s;
		int K, E, M;
		cin >> s >> K >> E >> M;
		v[i].s = s;
		v[i].K = K;
		v[i].E = E;
		v[i].M = M;

		i++;
	}

	sort(v.begin(), v.end(), cmp);

	for (student st : v) {
		cout << st.s << '\n';
	}


	return 0;
}