/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
using namespace std;
int Answer;


long long v[450001];
int s[450001];
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	v[1] = 1;
	for (int i = 2; i <= 450000; i++) {
		v[i] = v[i - 1] + i;
	}

	s[0] = 0;
	s[1] = 1;
	s[2] = 2;
	s[3] = 2;
	for (int i = 2; i <= 1000; i++) {
		int idx = v[i];
		if (idx > 450000) break;
		s[idx] = i;
		for (int j = 1; j <= i; j++) {
			if (idx + j > 450000)
				break;
			s[idx + j] = s[idx] + s[j];

		}
	}


	long long a, b;
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%lld %lld", &a, &b);
		int x_i, y_i;
		cout << '\n';
		for (int i = 1; i <= 450000; i++) {
			if (v[i] <= a && a < v[i + 1])
				x_i = i;
			if (v[i] <= b && b < v[i + 1]) {
				y_i = i;
				break;
			}
		}
		int current_answer;
		if (x_i < y_i - 1) {
			// v[y_i]
			int j = 0;
			for (long long i = v[y_i - 1]; i < v[y_i]; i++) {
				current_answer = y_i - 1 + s[j];
				if (Answer < current_answer)
					Answer = current_answer;
				j++;
			}
			j = 0;
			for (long long i = v[y_i]; i <= b; i++) {
				current_answer = y_i + s[j];
				if (Answer < current_answer)
					Answer = current_answer;
				j++;
			}
		}
		else if (x_i == y_i - 1) {
			int j = a - v[y_i - 1];
			for (long long i = a; i < v[y_i]; i++) {
				current_answer = y_i - 1 + s[j];
				if (Answer < current_answer)
					Answer = current_answer;
				j++;
			}
			j = 0;
			for (long long i = v[y_i]; i <= b; i++) {
				current_answer = y_i + s[j];
				if (Answer < current_answer)
					Answer = current_answer;
				j++;
			}
		}
		else { // x_i == y_i;
			int j = a - v[x_i];
			for (long long i = a; i <= b; i++) {
				current_answer = y_i + s[j];
				if (Answer < current_answer)
					Answer = current_answer;
				j++;
			}
		}



		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
		Answer = 0;
	}

	return 0;//Your program should return 0 on normal termination.
}