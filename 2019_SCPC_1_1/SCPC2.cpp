/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

double Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	double pi = 3.14159265;
	int R, S, E, N, left, right, height;
	double k = 0;
	double angle;
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d %d", &R, &S, &E);
		scanf("%d", &N);
		double current_point = S;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &left, &right, &height);
			if (height >= R) {
				Answer += right - R - current_point;
				Answer = Answer + 2 * (height - R);
				Answer = Answer + pi * R;
				current_point = right + R;
			}
			else {
				k = (double)(R - height) / R;
				angle = asin(k);
				Answer = Answer + right - left;
				Answer = Answer + (pi - 2 * angle) * R;
				Answer = Answer + left - (cos(angle)*R) - current_point;
				current_point = right + cos(angle)*R;
			}

		}
		if (current_point < E)
			Answer = Answer + (E - current_point);

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		printf("Case #%d\n", test_case + 1);
		printf("%f\n", Answer);
		Answer = 0;
	}

	return 0;//Your program should return 0 on normal termination.
}