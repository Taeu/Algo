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
	// ������ �´� ���� �� Ȯ��
	// n �˾Ƴ����� backtracking �̰͵� �� ���� ������� �����ϴ°� �ƴѰ�
	int stringSize = sn;
	int m = sn, n = tn, num;
	while (m || n) {
		num = Table[m][n];
		// ins
		if (Table[m][n - 1] == num - ins_cost) { // ins �� ������
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
	} // ��� ��Ʈ������� ���ؼ��� �̰� �ʿ����
	while (n) {
		stringSize++;
		n--;
	}


	// �ѹ� back tracking ����� �ؼ� n �� ���, r�װ� �ؾ߰ڳ�.��
	// n ���� SR, OP, TR allocation <- �� �κ� �´��� Ȯ��
	
	*SR = new char[stringSize+1];
	*TR = new char[stringSize + 1]; // ���࿡ ����� �ȵǸ� stringSize+1 �Ѵ����� ���� '\n' �־��ֱ�
	*OP = new char[stringSize + 1];
	*Mem_Allocated = stringSize * 3;
	for (int k = 0; k < stringSize; k++) {
		*SR[k] = '0';
	}
	// Back Tracking Real
	int i = sn, j = tn;
	n = stringSize-1;
	// �Ʒ��� insert �� �� �߿��� ��
	if (ins_cost <= del_cost) {
		while (i || j) {
			num = Table[i][j];
			// ins
			if (Table[i][j - 1] == num - ins_cost) { // ins �� ������
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
	// �Ʒ��� delete�� �� �߿��� ��,
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
			else if (Table[i][j - 1] == num - ins_cost) { // ins �� ������
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
