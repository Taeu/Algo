#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ERROR_BOUND 1.0e-30

void   Error_Exit(char *s);

void   Sort_by_X_or_Y(double *A, unsigned int *P, unsigned int N) {
	// input  : A[] (x or y position array of N points)
	//          P[] (index array of X (initial) or Y (during combine))
	//          N   number of points to sort
	// output : P[] (the indices are sorted by x or y position)
	int temp = 0;
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[P[i]] > A[P[j]]) {
				temp = P[i];
				P[i] = P[j];
				P[j] = temp;
			}
		}
	}

}
double Closest_Pair_DC(
	unsigned int L, unsigned int R,		// left and right indices
	unsigned int *pt1, unsigned int *pt2,   // min dist points inices (x,y)
	double *X, double *Y,					// input points position array
	unsigned int *X1, unsigned int *Y1, unsigned int *P3, // temp index arrays
	unsigned int THR	// threshold value
) {
	// Input : L, R, X[], Y[], X1[]
	// Output : pt1, pt2 ( the distance between (X[pt1],Y[pt1]) and
	//                     (X[pt2],Y[pt2]) is the closest )
	//          return the distance value
	// Others ; Y1[], P3[] (scratch arrays for D&C algorithm)
	double cd1, cd2, cd3, cdtmp, cd;
	int n = R - L + 1;
	if ( n <= THR) { // (1) 들어온 크기가 THR 보다 작거나 같으면 BF
		int yn = 0;
		for (int i = L; i < L + n; i++) {
			Y1[yn++] = X1[i];
		}
		// Y 정렬
		Sort_by_X_or_Y(Y, Y1, yn);
		// BF 하게 찾기
		cd = sqrt((Y[Y1[0]] - Y[Y1[1]])*(Y[Y1[0]] - Y[Y1[1]]) + (X[Y1[0]] - X[Y1[1]])*(X[Y1[0]] - X[Y1[1]]));
		*pt1 = Y1[0];
		*pt2 = Y1[1];
		for (int i = 0; i < yn-1; i++) {
			for (int j = i + 1; j < yn; j++) {
				cdtmp = sqrt((Y[Y1[i]] - Y[Y1[j]])*(Y[Y1[i]] - Y[Y1[j]]) + (X[Y1[i]] - X[Y1[j]])*(X[Y1[i]] - X[Y1[j]]));
				if (cdtmp < cd) {
					*pt1 = Y1[i];
					*pt2 = Y1[j];
					cd = cdtmp;
				}
			}
		}
	}
	else {
		cd1 = Closest_Pair_DC(L,(R-L)/ 2, &pt1, &pt2, X, Y, X1, Y1, P3, THR);
		cd2 = Closest_Pair_DC((R-L)/2+1, R , &pt1, &pt2, X, Y, X1, Y1, P3, THR);
		cd3 = fmin(cd1, cd2);
		cd = cd3;
		// 중간영역 P3 에 넣을까
		// L의 끝점 -> X[X1[R-L/2]] -cd3;
		// R의 첫점 -> X[X1[R-L/2+1]] + cd3;
		// 에 해당되는 부분만 Y1 에 카피후, Y에대해서 정렬
		double left, right;
		int yn = 0;
		for (int i = L; i < L + n; i++) {
			if (X[X1[i]] >= left && X[X1[i]] <= right) Y1[yn++] = X1[i];
		}
		// Y에 대해 정렬
		Sort_by_X_or_Y(Y, Y1, yn);
		for (int i = 0; i < yn-1; i++) {
			for (int j = i + 1; j < yn; j++) {
				if (Y[Y1[j]] - Yp[Y1[i]] >= cd3) break;
				cdtmp = sqrt((Y[Y1[i]] - Y[Y1[j]])*(Y[Y1[i]] - Y[Y1[j]]) + (X[Y1[i]] - X[Y1[j]])*(X[Y1[i]] - X[Y1[j]]));
				if (cdtmp < cd) {
					*pt1 = Y1[i];
					*pt2 = Y1[j];
					cd = cdtmp;
				}
			}

		}
	}
	return cd;
}
void main ( void ) {
    int TNUM, THR;
	unsigned int N, pt1, pt2;
	double cmpt, cd; // cd : closest distance
	double cd1;      // distance between pt1 and pt2(for verification)
	clock_t start, finish;
	double *X, *Y;
	unsigned int *X1, *Y1, *P3;

	scanf_s("%d", &TNUM); // read the number of tests
	for ( int t = 0; t < TNUM; t++ ) {  // for each test case
		scanf_s("%u %d", &N, &THR); // read point number and threshold
		X  = new double [N];        Y = new double [N];  // allocate arrays
		X1 = new unsigned int [N]; Y1 = new unsigned int [N];
		P3 = new unsigned int [N];
		if ( X == NULL || Y == NULL || X1 == NULL || Y1 == NULL || P3 == NULL ) {
			Error_Exit("Memory allocation error!");
		}
		for (unsigned int i = 0; i < N; i++) { // read points
			scanf_s("%le %le",&X[i], &Y[i]); 
			X1[i] = i; // set indices of points
		}
		start = clock();
		// ** Apply the D&C algorithm
			Sort_by_X_or_Y ( X, X1, N ); // sort point indices by x-coords
			cd = Closest_Pair_DC(0, N-1, &pt1, &pt2, X, Y, X1, Y1, P3, THR);
		// **End of thr algorithm
		finish = clock();
		cmpt = ((double)(finish - start)) / CLK_TCK;
		if ( t != 0 ) printf("\n");
		printf("**Test Case %d (N = %u, time = %.3f sec)", t+1, N, cmpt);
		cd1 = sqrt((Y[pt1] - Y[pt2])*(Y[pt1] - Y[pt2]) + (X[pt1] - X[pt2])*(X[pt1] - X[pt2]));
		if ( fabs(cd - cd1) <= ERROR_BOUND ) {
			printf("\npt pair = (%u, %u), min_dist = %23.16le", pt1, pt2, cd);
		}
		else {
			printf("\npt pair = (%u, %u), min_dist = %23.16le, ERROR: dist(pt1,pt2) != cd.", pt1, pt2, cd);
		}
		delete X; delete Y;
		delete X1; delete Y1; delete P3;
	}
}

void Error_Exit(char *s) {
	printf("%s", s);
	exit(-100);
}
