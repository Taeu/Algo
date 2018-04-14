#include "Graph_adj_list.h"
#include "Graph_adj_list_extern.h"
#include "Graph_adj_list_function.h"

void Read_Graph_adj_list(int Vnum, vertex *V, int Enum, edge *E) {
	// Read graph information and form an adjacent list
	// null 로 만들어주기
	for (int i = 0; i < Vnum; i++) {
		V[i].p = NULL;
	}
	int vf, vr, cost;
	for (int i = 0; i < Enum; i++) {
		scanf_s("%d%d%d", &vf, &vr, &cost);
		// E[i] 를 읽어서 넣고
		E[i].name = i;
		E[i].vf = vf;
		E[i].vr = vr;
		E[i].cost = cost;
		// 만들고
		pushQ_ptr_L(&(V[vf].p), E[i].name);
		pushQ_ptr_L(&(V[vr].p), E[i].name);
	}
}

void Free_Graph_adj_list(int Vnum, vertex *V, int Enum, edge *E) {
	// remove the links (ptr_Ls) for the adjacent list
	for (int i = 0; i < Vnum; i++) {
		for (ptr_L * p = V[i].p; p != NULL;) {
			ptr_L * Fp = p;
			p = p->p;
			Free_ptr_L(Fp);
		}
	}
}

void DFS_Tree_adj_list (
	int     src,   // source node index
	int     Vnum,  // number of vertices
	vertex *V,     // vertex structure array (starting index 0)
	int     Enum,  // number of edges
	edge   *E,     // edge structure array (starting index 0)
	int    *cost   // accumulated tree cost
) {
	// preform DFS and set the flags of edges in the DFS tree
	// return the DFS tree cost.
	// Recursively do DFS.

	V[src].flag = true;
	for (ptr_L * p = V[src].p; p != NULL; p = p->p) {
		// 첫번째 vf , vr을 봐야함
		if (p != NULL) { // 쓰레기값이 아니어야함
			if (E[p->i].vf == src) {
				if (V[E[p->i].vr].flag == false && E[p->i].flag == false) { // 사실 하나만 체크해줘도 되는 문제긴함. 어짜피 거기를 넘어간다는 거는 그 노드를 방문하게 될 거니까.
					E[p->i].flag = true;
					*cost += E[p->i].cost;
					DFS_Tree_adj_list(E[p->i].vr, Vnum, V, Enum, E, cost);
				}
			}
			// 두번째 vr, vf를 봐야함
			else {
				if (V[E[p->i].vf].flag == false && E[p->i].flag == false) {
					E[p->i].flag = true;
					*cost += E[p->i].cost;
					DFS_Tree_adj_list(E[p->i].vf, Vnum, V, Enum, E, cost);

				}
			}
		}
	}
}