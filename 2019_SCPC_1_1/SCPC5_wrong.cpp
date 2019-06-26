
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long Answer;
pair<long long,long long> a[100001];
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	long long left, right;
	long long x, y;
	int n;
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%lld %lld", &left, &right);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", &x, &y);
			if (y < 0) y *= -1;
			a[i] = make_pair(x, y);
		}
		sort(a, a + n);

		
		
		printf("Case #%d\n", test_case + 1);
		printf("%lld\n", Answer);
		Answer = 0;
	}

	return 0;//Your program should return 0 on normal termination.
}