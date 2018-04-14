#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

#pragma warning (disable:4996)


int main(){
	int N;
	scanf("%d", &N); 
	priority_queue<int,vector<int>,greater<int> > mnpq;
	while (N--){
		int n;
		scanf("%d", &n);
		if (n == 0){
			if (mnpq.empty()) printf("0\n");
			else{
				printf("%d\n", mnpq.top());
				mnpq.pop();
			}
		}
		else{
			mnpq.push(n);
		}


	}

	return 0;
}