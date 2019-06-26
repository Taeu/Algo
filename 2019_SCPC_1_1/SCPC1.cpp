#include<math.h>
#include<iostream>
#include<cstdio>

using namespace std;
#pragma warning (disable:4996)
double PI = 3.14159265;
int main() {
	double k = (double) sqrt(3) / 2;
	cout << k << '\n';
	cout << asin(k) << '\n';
	cout << asin(sin((double)360*PI/180)) <<'\n';


	return 0;
}