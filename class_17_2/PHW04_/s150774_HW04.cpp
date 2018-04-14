#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}
extern void Edit_Distance(
	char *SS,		
	char *TS,		
	int ins_cost, int del_cost, int sub_cost,
	int **Table,   
	char **SR,		
	char **OP,		
	char **TR,
	int  *Mem_Allocated
){
	int sn = strlen(SS);
	int tn = strlen(TS);
	// init Table[i][0], [0][j];
	for (int i = 0; i <= sn; i++) {
		Table[i][0] = i*del_cost;
	}
	for (int j = 0; j <= tn; j++) {
		Table[0][j] = j*ins_cost;
	}

	int a, b, c, d;
	for (int i = 1; i <= sn; i++) {
		for (int j = 1; j <= tn; j++) {
			a = Table[i][j - 1] + ins_cost;
			if (SS[i - 1] != TS[j - 1]) b = Table[i - 1][j - 1] + sub_cost;
			else b = Table[i - 1][j - 1];
			c = Table[i - 1][j] + del_cost;
			d = min(min(a, b), c);
			Table[i][j] = d;
		}
	}
	// 위에꺼 맞는 지도 좀 확인
	// n 알아내려고 backtracking 이것도 두 가지 방면으로 가야하는거 아닌가
	int stringSize = sn;
	int m = sn, n = tn, num;
	while (m || n) {
		num = Table[m][n];
		// ins
		if (Table[m][n - 1] == num - ins_cost) { // ins 로 왔으면
			stringSize++;
			n--;
		}
		// del
		else if (Table[m - 1][n] == num - del_cost) {
			m--;
		}
		// nop
		else if (Table[m - 1][n - 1] == num) {
			m--;
			n--;
		}
		// sub
		else {
			m--;
			n--;
		}
	}
	while (m) {
		m--;
	} // 사실 스트링사이즈를 위해서는 이거 필요없음
	while (n) {
		stringSize++;
		n--;
	}


	// 한번 back tracking 제대로 해서 n 값 얻고, r그거 해야겠네.ㄴ
	// n 으로 SR, OP, TR allocation <- 이 부분 맞는지 확인
	
	*SR = new char[stringSize+1];
	*TR = new char[stringSize + 1]; // 만약에 제대로 안되면 stringSize+1 한다음에 끝에 '\n' 넣어주기
	*OP = new char[stringSize + 1];
	*Mem_Allocated = stringSize * 3;
	for (int k = 0; k < stringSize; k++) {
		*SR[k] = '0';
	}
	// Back Tracking Real
	int i = sn, j = tn;
	n = stringSize-1;
	// 아래는 insert 가 더 중요할 때
	if (ins_cost <= del_cost) {
		while (i || j) {
			num = Table[i][j];
			// ins
			if (Table[i][j - 1] == num - ins_cost) { // ins 로 왔으면
				*OP[n] = 'i';
				*SR[n] = '*';
				*TR[n--] = TS[j-1];
				j--;
			}
			// del
			else if (Table[i - 1][j] == num - del_cost) {
				*OP[n] = 'd';
				*SR[n] = SS[i-1];
				*TR[n--] = '*';
				i--;

			}
			// nop
			else if (Table[i - 1][j - 1] == num) {
				*OP[n] = '.';
				*SR[n] = SS[i];
				*TR[n--] = TS[j-1];
				i--;
				j--;
			}
			// sub
			else {
				*OP[n] = 's';
				*SR[n] = SS[i-1];
				*TR[n--] = TS[j-1];
				i--;
				j--;
			}
		}
		while (i) {
			*OP[n] = 'd';
			*SR[n] = SS[i-1];
			*TR[n--] = '*';
			i--;
		}
		while (j) {
			*OP[n] = 'i';
			*SR[n] = '*';
			*TR[n--] = TS[j-1];
			j--;
		}
	}
	// 아래는 delete가 더 중요할 때,
	else {
		while (i || j) {
			num = Table[i][j];
			// ins
			
			// del
			if (Table[i - 1][j] == num - del_cost) {
				*OP[n] = 'd';
				*SR[n] = SS[i-1];
				*TR[n--] = '*';
				i--;
			}
			else if (Table[i][j - 1] == num - ins_cost) { // ins 로 왔으면
				*OP[n] = 'i';
				*SR[n] = '*';
				*TR[n--] = TS[j-1];
				j--;
			}
			// nop
			else if (Table[i - 1][j - 1] == num) {
				*OP[n] = '.';
				*SR[n] = SS[i-1];
				*TR[n--] = TS[j-1];
				i--;
				j--;
			}
			// sub
			else {
				*OP[n] = 's';
				*SR[n] = SS[i-1];
				*TR[n--] = TS[j-1];
				i--;
				j--;
			}
		}
		while (i) {
			*OP[n] = 'd';
			*SR[n] = SS[i-1];
			*TR[n--] = '*';
			i--;
		}
		while (j) {
			*OP[n] = 'i';
			*SR[n] = '*';
			*TR[n--] = TS[j-1];
			j--;
		}
	}
}
