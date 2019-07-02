#include<iostream>
#pragma warning(disable:4996)
#include<queue>
#include<vector>
using namespace std;

vector<int> tree[100001];
int t[100001];
bool check[100001]; // check �� ��� �ʿ������
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; 
	cin >> n;
	// parent�� �������� �𸣴� ��Ȳ�� �Ͼ �� ����
	// tree�̹Ƿ� �ִ� ���� ���� 3��
	for (int i = 1; i < n; i++) {
		int a1, a2;
		cin >> a1 >> a2;
		tree[a1].push_back(a2);
		tree[a2].push_back(a1);
	}
	
	q.push(1);
	while (!q.empty()) {
		int current_parent = q.front();
		q.pop();
		check[current_parent] = true;
		for (int nod : tree[current_parent]) {
			if (check[nod] == false) {
				t[nod] = current_parent;
				q.push(nod);
			}
		}

	}

	for (int i = 2; i <= n; i++) {
		cout << t[i] << '\n';
	}
	
	return 0;
}