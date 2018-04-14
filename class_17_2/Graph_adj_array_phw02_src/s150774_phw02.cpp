#include "Graph_adj_array.h"
#include "Graph_adj_array_extern.h"
#include "Graph_adj_array_function.h"

void Read_Graph_adj_array ( ) {
	// read graph information
	int vf, vr, cost; 
	
	// f_hd, r_hd, -1로 초기화
	for (int i = 0; i < Vnum; i++) {
		V[i].name = i;
		V[i].f_hd = V[i].r_hd = -1;
	}
	for (int i = 0; i < Enum; i++) {
		E[i].fp = -1;
		E[i].rp = -1;
	}
	for (int i = 0; i < Enum; i++) {
		scanf_s("%d%d%d", &vf, &vr, &cost);
		// Edge부터 채우기
		E[i].name = i;
		E[i].vf = vf;
		E[i].vr = vr;
		E[i].cost = cost;

		// 4가지 조건
		if (V[vf].f_hd == -1 && V[vr].r_hd == -1) {
			V[vf].f_hd = i;
			V[vr].r_hd = i;
		} else if (V[vf].f_hd != -1 && V[vr].r_hd == -1) {
			E[i].fp = V[vf].f_hd;
			V[vf].f_hd = i;
			V[vr].r_hd = i;
		} else if (V[vf].f_hd == -1 && V[vr].r_hd != -1) {
			V[vf].f_hd = i;
			E[i].rp = V[vr].r_hd;
			V[vr].r_hd = i;
		}
		else {
			E[i].fp = V[vf].f_hd;
			V[vf].f_hd = i;
			E[i].rp = V[vr].r_hd;
			V[vr].r_hd = i;
		}
		// 이게 나중에 어떻게 연결돼있는지를 확인할 때, DFS를 할 수 있음
	}
	
}

void DFS_Tree_adj_array ( int src ) {  // src = source node index
	V[src].flag = true;
	// f_hd
	int edge = V[src].f_hd;
	if (edge != -1) {
		if (E[edge].flag != true && V[E[edge].vr].flag != true) {
			E[edge].flag = true;
			Tree_cost += E[edge].cost;
			DFS_Tree_adj_array(E[edge].vr);
		}
		for (int i = E[edge].fp; i != -1; i = E[i].fp) {
			if (E[i].flag != true && V[E[i].vr].flag != true) {
				E[i].flag = true;
				Tree_cost += E[i].cost;
				DFS_Tree_adj_array(E[i].vr);
			}
		}
	}

	//r_hd
	edge = V[src].r_hd;
	if (edge != -1) {
		if (E[edge].flag != true && V[E[edge].vf].flag != true) {
			E[edge].flag = true;
			Tree_cost += E[edge].cost;
			DFS_Tree_adj_array(E[edge].vf);
		}
		for (int i = E[edge].rp; i != -1; i = E[i].rp) {
			if (E[i].flag != true && V[E[i].vf].flag != true) {
				E[i].flag = true;
				Tree_cost += E[i].cost;
				DFS_Tree_adj_array(E[i].vf);
			}
		}
	}
}
