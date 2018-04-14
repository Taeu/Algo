#include "Graph_include.h"

// any function definitions here
// You may write any functions here (eg. heap insert, delete, adjustment)

void insert_heap(int* heap, int* distance, int item) {
	int i;
	i = ++heap[0];
	while ((i != 1) && (distance[item] < distance[heap[i / 2]])) {
		heap[i] = heap[i / 2];
		i /= 2;

	}
	heap[i] = item;
}

void delete_heap(int* heap, int* distance, int v) {
	int parent, child;
	int item, temp;
	item = heap[1];
	temp = heap[heap[0]--];
	parent = 1;
	child = 2;
	int n = heap[0];
	while (child < n) {
		if (child <n && distance[heap[child]] > distance[heap[child + 1]])
			child++;
		if (distance[temp] < distance[heap[child]]) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
}

void adjust(int *heap, int *distance, int w) {
	int i = 1;
	while (1) {
		if (heap[i] == w) break;
		i++;
	}
	int temp;
	while ((i != 1) && (distance[heap[i]] < distance[heap[i / 2]])) {
		temp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = temp;
		i /= 2;
	}
}
// You must not declare any global variable

extern int SPT_Dijkstra(		// return SPT cost
	int src,			// source vertex index
	int Vnum, vertex *V, int Enum, edge *E,		// Graph data(the same as in HW04, 05)
	int *P1, int *P2, int *P3, int *P4,			// scratch int  storage of size (Vnum+1)
	bool *P5,									// scratch bool storage of size (Vnum+1)
	int *Maxd1,		// The largest distance (output)
	int *Maxd3      // The third largest distance (output)
) {
	int totalCost = 0;
	int edge;
	// 초기화
	for (int i = 0; i < Vnum; i++) {
		P5[i] = false; P1[i] = 987654321;
	}

	// 첫 시작은 src 이다
	P1[src] = 0; P2[0] = src; P5[src] = true;
	//f_hd
	for (edge = V[src].f_hd; edge != -1; edge = E[edge].fp) {
			P1[E[edge].vr] = E[edge].cost;
			P4[E[edge].vr] = src;
	}

	//r_hd
	for (edge = V[src].r_hd; edge != -1;edge = E[edge].rp) {
		P1[E[edge].vf] = E[edge].cost;
		P4[E[edge].vf] = src;
	}
	// src 초기화 끝

	// min_heap 만들기 - P3 가 민힙
	P3[0] = 0;
	for (int i = 0; i < Vnum; i++) {
		if (i == src) continue;
		insert_heap(P3, P1, i);
	}

	int u, w;
	int v1, v2;
	for (int i = 0; i < Vnum - 1; i++) {
		u = P3[1];

		//flag 업데이트 고쳐야함.
		P2[i + 1] = u;
		// u에 붙어있는 것 검색해서 edge.flag = true 로 만들어주어야함
		v1 = P2[i+1];
		v2 = P4[v1];
		//f_hd
		for (edge = V[v1].f_hd; edge != -1; edge = E[edge].fp) {
			if (E[edge].flag ==false && E[edge].vr == v2) {
				E[edge].flag = true;
				totalCost += E[edge].cost;
			}
		}
		//r_hd
		for (edge = V[v1].r_hd; edge != -1; edge = E[edge].rp) {
			if (E[edge].flag == false && E[edge].vf == v2 ) {
				E[edge].flag = true;
				totalCost += E[edge].cost;
			}
		}
		
		// flag 업데이트 끝

		// P5 체크
		P5[u] = true;
		delete_heap(P3, P1, u);

		// 여기서부터  u 와 붙어있는 것들 검색
		//f_hd
		for (edge = V[u].f_hd; edge != -1; edge = E[edge].fp) {
			if (E[edge].flag == false) {
				w = E[edge].vr;
				if (P5[w] == false && P1[u] + E[edge].cost < P1[w]) {
					P4[w] = u;
					P1[w] = P1[u] + E[edge].cost;
					adjust(P3, P1, w);
				}
			}
		}
		//r_hd
		for (edge = V[u].r_hd; edge != -1; edge = E[edge].rp) {
			if (E[edge].flag != true) {
				w = E[edge].vf;
				if (P5[w] == false && P1[u] + E[edge].cost < P1[w]) {
					P4[w] = u;
					P1[w] = P1[u] + E[edge].cost;
					adjust(P3, P1, w);
				}
			}
		}
		// 검색 끝
	}
	int max = 0, index1;
	for (int i = 0; i < Vnum; i++) {
		if (P1[i] > max) {
			max = P1[i];
			index1 = i;
		}
	}
	*Maxd1 = max;
	max = 0;
	int index2;
	for (int i = 0; i < Vnum; i++) {
		if (P1[i] > max&& i != index1) {
			max = P1[i];
			index2 = i;
		}
	}
	max = 0;
	for (int i = 0; i < Vnum; i++) {
		if (P1[i] > max && i != index1&& i != index2) {
			max = P1[i];
		}
	}
	*Maxd3 = max;

	return totalCost;
}

extern void Read_Graph(int Vnum, vertex *V, int Enum, edge *E) { 
	// construct the adjacency list of a graph using array style linked list
	// read graph information
	int vf, vr, cost;
	// f_hd, r_hd, -1로 초기화
	for (int i = 0; i < Vnum; i++) {
		V[i].f_hd = V[i].r_hd = -1;
	}
	for (int i = 0; i < Enum; i++) {
		E[i].fp = -1;
		E[i].rp = -1;
	}
	for (int i = 0; i < Enum; i++) {
		scanf_s("%d%d%d", &vf, &vr, &cost);
		// Edge부터 채우기
		E[i].vf = vf;
		E[i].vr = vr;
		E[i].cost = cost;
		E[i].flag = false;
		// 4가지 조건
		if (V[vf].f_hd == -1 && V[vr].r_hd == -1) {
			V[vf].f_hd = i;
			V[vr].r_hd = i;
		}
		else if (V[vf].f_hd != -1 && V[vr].r_hd == -1) {
			E[i].fp = V[vf].f_hd;
			V[vf].f_hd = i;
			V[vr].r_hd = i;
		}
		else if (V[vf].f_hd == -1 && V[vr].r_hd != -1) {
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
	}


}

